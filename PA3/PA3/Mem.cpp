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
//  Initialized the Memory block:
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

	return nullptr;
}

Used* Mem::allocateAll(Free* pFree, uint32_t size)
{
	Heap* pHeap = this->poHeap;
	Used* pUsedAddr = nullptr;
	Used* pUsed = nullptr;

	pUsedAddr = (Used*)(pFree);
	pHeap->removeFree(pFree);

	pUsed = new(pUsedAddr) Used(size);
	pHeap->insertUsed(pUsed);

	// Update Heap Stats
	pHeap->currNumUsedBlocks++;
	pHeap->currUsedMem += size;
	pHeap->currNumFreeBlocks--;
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
	uint32_t botPFree = sizeof(pFree) + pFree->mDataSize - 4; // accounting for 4 extra bits (have to actually find where it is coming from)
	pHeap->removeFree(pFree);

	pUsed = new(pUsedAddr) Used(size);
	pHeap->insertUsed(pUsed);

	pFreeAddr = (Free*)((uint32_t)(pUsedAddr + 1) + size);
	uint32_t pNewFreeBlock = botPFree - (pUsed->mDataSize + sizeof(Used));
	newPFree = new(pFreeAddr) Free(pNewFreeBlock);
	pHeap->insertFree(pBeforeFree, newPFree, pAfterFree);

	pHeap->pNextFit = newPFree;

	// Update Heap Stats
	pHeap->currNumUsedBlocks++;
	pHeap->currUsedMem += pUsed->mDataSize;
	pHeap->currFreeMem -= pUsed->mDataSize + sizeof(Used);

	return pUsed;
}

Free* Mem::freeUsedBlock(Used* pUsed)
{
	Heap* pHeap = this->poHeap;
	Free* pFreeAddr = nullptr;
	Free* pFree = nullptr;

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
		// For PA4 Coalesce 
	}
	else if (aboveFree)
	{
		// For PA4 Coalesce 
	}
	else if (nullptr != belowBlock)
	{
		uint32_t newFreeBlockSize = (uint32_t)(sizeof(Free)) + (belowBlock->mDataSize + pFree->mDataSize);
		pHeap->currFreeMem -= belowBlock->mDataSize;

		pFree = new(pFreeAddr) Free(newFreeBlockSize);
		pHeap->currNumFreeBlocks--;

		pHeap->insertFree(nullptr, pFree, nullptr);
	}
	else
	{
		// For PA4 while loop sorted order fit
		pHeap->insertFree(nullptr, pFree, nullptr);
	}

	// Update Heap Stats
	pHeap->currNumUsedBlocks--;
	pHeap->currUsedMem -= freeBlockSize;
	pHeap->currNumFreeBlocks++;
	pHeap->currFreeMem += pFree->mDataSize;

	return pFree;
}

Free* Mem::checkBlockBelow(Free* pFree)
{
	uint32_t totalSize = (uint32_t)(pFree + 1) + pFree->mDataSize;
	Free* pBelow = (Free*)totalSize; // figure out how to get to the bottom

	if (pBelow->mType == Type::FREE)
	{
		return pBelow;
	}
	else
	{
		return nullptr;
	}
}

// ---  End of File ---
