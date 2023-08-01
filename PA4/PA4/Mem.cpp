//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Type.h"

// To help with coalescing... not required
struct SecretPtr
{
	Free *pFree;
};

// ----------------------------------------------------
//  Initialized the Memory Type:
//  Update the Heap
//  Create a free block
//  Heap structure links to free hdr
//-----------------------------------------------------
void Mem::initialize()
{
	Heap* pHeap = this->poHeap;

	// Bottom of heap
	Free* pFreeAddr = (Free*)(pHeap + 1);


	uint32_t freeBlockSize = this->privGetBottom() - (uint32_t)(pFreeAddr + 1);

	Free* pFree = new(pFreeAddr) Free(freeBlockSize);

	this->addSecretPtr(pFree);

	// Update the Heap

	pHeap->pUsedHead = nullptr;
	pHeap->pFreeHead = pFree;
	pHeap->pNextFit = pFree;

	pHeap->currNumUsedBlocks = 0;
	pHeap->currUsedMem = 0;
	pHeap->currNumFreeBlocks = 1;
	pHeap->currFreeMem = freeBlockSize;
}

// ----------------------------------------------------
//  Do your Magic here:
//  Find a free block that fits
//  Change it to used (may require subdivision)
//  Correct the heap Links (used,free) headers 
//  Update stats
//  Return pointer to block
//-----------------------------------------------------
void *Mem::malloc( const uint32_t _size )
{
	Heap* pHeap = this->poHeap;
	Used* pUsed = nullptr;

	// Find fit
	Free* pFreeFit = this->FindFree(pHeap->pNextFit, _size);

	// Change Free to Used
	if (pFreeFit->mDataSize == _size)
	{
		pUsed = this->allocateAll(pFreeFit, _size);
	}
	else
	{
		pUsed = this->allocatePartial(pFreeFit, _size);
	}


	return pUsed + 1;
}

// ----------------------------------------------------
//  Do your Magic here:
//  Return the free block to the system
//  May require Coalescing
//  Correct the heap Links (used,free) headers 
//  Update stats
//-----------------------------------------------------
void Mem::free( void * const data )
{
	Used* pUsedBlock = (Used*)(data);
	Used* pUsed = pUsedBlock - 1;

	// Change Used to Free
	this->freeUsedBlock(pUsed);
}

uint32_t Mem::privGetBottom() const
{
	return (uint32_t)this->poHeap + Mem::TotalSize;
}

Free* Mem::FindFree(Free* freeHead, uint32_t size)
{
	Heap* pHeap = this->poHeap;
	Free* temp = freeHead;

	while (nullptr != temp)
	{
		if (temp->mDataSize > size)
		{
			// Found free block
			pHeap->pNextFit = temp;
			return temp;
		}
		else if (temp->mDataSize == size)
		{
			pHeap->pNextFit = temp->pPrev;
			return temp;
		}

		temp = temp->pNext;
	}

	temp = pHeap->pFreeHead;
	while (freeHead != temp)
	{
		if (temp->mDataSize > size)
		{
			// Found free block
			pHeap->pNextFit = temp;
			return temp;
		}
		else if (temp->mDataSize == size)
		{
			pHeap->pNextFit = temp->pPrev;
			return temp;
		}

		temp = temp->pNext;
	}

	return nullptr;
}

Used* Mem::allocateAll(Free* pFree, uint32_t size)
{
	Heap* pHeap = this->poHeap;
	Used* pUsedAddr = nullptr;
	Used* pUsed = nullptr;

	pHeap->pNextFit = pFree->pPrev;
	pUsedAddr = (Used*)(pFree);
	pHeap->removeFree(pFree);

	pUsed = new(pUsedAddr) Used(size);
	pHeap->insertUsed(pUsed);

	// Update Heap Stats
	pHeap->currUsedMem += size;
	pHeap->currFreeMem -= pFree->mDataSize;

	return pUsed;
}

Used* Mem::allocatePartial(Free* pFree, uint32_t size)
{
	Heap* pHeap = this->poHeap;
	Free* pFreeAddr = nullptr;
	Free* newPFree = nullptr;
	Used* pUsedAddr = nullptr;
	Used* pUsed = nullptr;

	pUsedAddr = (Used*)(pFree);
	Free* pBeforeFree = pFree->pPrev;
	Free* pAfterFree = pFree->pNext;
	uint32_t botPFree = pFree->TotalDataSize(); 
	pHeap->removeFree(pFree);

	pUsed = new(pUsedAddr) Used(size);
	pHeap->insertUsed(pUsed);

	pFreeAddr = (Free*)pUsed->BelowMe();
	uint32_t pNewFreeBlock = botPFree - pUsed->TotalDataSize() - sizeof(Free);
	newPFree = new(pFreeAddr) Free(pNewFreeBlock);
	pHeap->insertFree(pBeforeFree, newPFree, pAfterFree);

	this->addSecretPtr(newPFree);

	pHeap->pNextFit = newPFree;

	// Update Heap Stats
	pHeap->currUsedMem += pUsed->mDataSize;
	pHeap->currFreeMem -= sizeof(Used) + pUsed->mDataSize;

	return pUsed;
}

Free* Mem::freeUsedBlock(Used* pUsed)
{
	Heap* pHeap = this->poHeap;
	Free* pFreeAddr = nullptr;
	Free* pFree = nullptr;
	SecretPtr* secret = nullptr;

	uint32_t freeBlockSize = pUsed->mDataSize;
	bool aboveFree = pUsed->bAboveFree;

	pFreeAddr = (Free*)(pUsed);
	pHeap->removeUsed(pUsed);

	pFree = new(pFreeAddr) Free(freeBlockSize);
	Free* belowBlock = nullptr;

	if (pHeap->currNumFreeBlocks >= 1)
	{
		belowBlock = this->checkBlockBelow(pFree);
	}

	if (aboveFree && nullptr != belowBlock)
	{
		// For PA4 Coalesce Sandwhich
		secret = (SecretPtr*)pFree;
		secret = secret - 1;

		Free* aboveFreeBlock = secret->pFree;

		pFree = this->CoalesceSandwhich(aboveFreeBlock, pFree, belowBlock);
	}
	else if (aboveFree)
	{
		// For PA4 Coalesce above
		secret = (SecretPtr*)pFree;
		secret = secret - 1;

		Free* aboveFreeBlock = secret->pFree;

		pFree = this->CoalesceTop(aboveFreeBlock, pFree); 
	}
	else if (nullptr != belowBlock)
	{
		// PA4 Coalesce below
		pFree = this->CoalesceBottom(pFree, belowBlock);
	}
	else
	{
		// For PA4 while loop sorted order fit
		Free* before = nullptr;
		Free* after = nullptr;
		Free* curr = pHeap->pFreeHead;

		if (nullptr != curr)
		{
			while (nullptr != curr && pFree->mDataSize >= curr->mDataSize)
			{
				before = curr;

				curr = curr->pNext;
			}

			after = curr;
		}

		pHeap->insertFree(before, pFree, after);

		this->addSecretPtr(pFree);
	}

	// Update Heap Stats
	pHeap->currUsedMem -= freeBlockSize;
	pHeap->currFreeMem += pFree->mDataSize;

	return pFree;
}

Free* Mem::checkBlockBelow(Free* pFree)
{
	Used* pBelow = pFree->BelowMe();

	uint32_t heapBottom = this->privGetBottom();

	if (heapBottom > (uint32_t)pBelow && pBelow->mType == Type::FREE)
	{
		return (Free*)pBelow;
	}
	else
	{
		return nullptr;
	}
}

void Mem::addSecretPtr(Free* secretPFree)
{
	SecretPtr* secret = (SecretPtr*)secretPFree->BelowMe();
	secret = secret - 1;
	secret->pFree = secretPFree;
}

Free* Mem::CoalesceTop(Free* top, Free* pFree)
{
	Heap* pHeap = this->poHeap;
	Free* next = top->pNext;
	Free* prev = top->pPrev;

	uint32_t freeBlockSize = sizeof(Free) + (pFree->mDataSize + top->mDataSize);
	pHeap->currFreeMem -= top->mDataSize;

	pHeap->removeFree(top);
	pFree = new(top) Free(freeBlockSize);

	pHeap->insertFree(prev, pFree, next);

	this->addSecretPtr(pFree);

	return pFree;
}

Free* Mem::CoalesceBottom(Free* pFree, Free* bottom)
{
	Heap* pHeap = this->poHeap;
	Free* next = bottom->pNext;
	Free* prev = bottom->pPrev;
	
	uint32_t freeBlockSize = sizeof(Free) + (bottom->mDataSize + pFree->mDataSize);
	pHeap->currFreeMem -= bottom->mDataSize;

	pHeap->removeFree(bottom);
	pFree = new(pFree) Free(freeBlockSize);

	if (bottom == pHeap->pNextFit)
	{
		pHeap->pNextFit = pFree;
	}

	pHeap->insertFree(prev, pFree, next);

	this->addSecretPtr(pFree);

	return pFree;
}

Free* Mem::CoalesceSandwhich(Free* top, Free* pFree, Free* bottom)
{
	Heap* pHeap = this->poHeap;
	Free* next = bottom->pNext;
	Free* prev = top->pPrev;

	uint32_t freeBlockSize = 2 * sizeof(Free) + (bottom->mDataSize + pFree->mDataSize + top->mDataSize);
	pHeap->currFreeMem -= bottom->mDataSize + top->mDataSize;

	pHeap->removeFree(top);
	pHeap->removeFree(bottom);
	pFree = new(top) Free(freeBlockSize);

	if (bottom == pHeap->pNextFit)
	{
		pHeap->pNextFit = pFree;
	}

	pHeap->insertFree(prev, pFree, next);

	this->addSecretPtr(pFree);

	return pFree;
}

// ---  End of File ---
