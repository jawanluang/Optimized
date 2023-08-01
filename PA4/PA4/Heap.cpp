//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Heap.h"
#include "Mem.h"

Heap::Heap()
:	pUsedHead(nullptr),
	pFreeHead(nullptr),
	pNextFit(nullptr),
    currNumUsedBlocks(0),
    currUsedMem(0),
    currNumFreeBlocks(0),
    currFreeMem(0)
{
}

void Heap::insertUsed(Used* pUsed)
{

	if (nullptr != this->pUsedHead)
	{
		pUsed->pNext = this->pUsedHead;
		this->pUsedHead->pPrev = pUsed;
	}

	this->pUsedHead = pUsed;
	
	this->currNumUsedBlocks++;
	this->setBelowAboveFlag(pUsed);
}

void Heap::removeUsed(Used* pUsed)
{
	if (pUsed == this->pUsedHead)
	{
		this->pUsedHead = pUsed->pNext;
	}

	if (nullptr != pUsed->pPrev)
	{
		pUsed->pPrev->pNext = pUsed->pNext;
	}

	if (nullptr != pUsed->pNext)
	{
		pUsed->pNext->pPrev = pUsed->pPrev;

		if (pUsed == this->pUsedHead)
		{
			this->pUsedHead = pUsed->pNext;
		}
	}

	this->currNumUsedBlocks--;
}

void Heap::insertFree(Free* pBefore, Free* pFree, Free* pAfter)
{
	if (nullptr == pBefore && nullptr == pAfter)
	{
		this->pNextFit = pFree;
	}
	
	if (nullptr != pBefore)
	{
		pBefore->pNext = pFree;
		pFree->pPrev = pBefore;
	}
	else
	{
		this->pFreeHead = pFree;
	}

	if (nullptr != pAfter)
	{
		pAfter->pPrev = pFree;
		pFree->pNext = pAfter;
	}

	this->currNumFreeBlocks++;
	this->setBelowAboveFlag(pFree);
}

void Heap::removeFree(Free* pFree)
{
	if (pFree == this->pFreeHead)
	{
		this->pFreeHead = nullptr;
	}

	if (nullptr != pFree->pPrev)
	{
		pFree->pPrev->pNext = pFree->pNext;
	}

	if (nullptr != pFree->pNext)
	{
		pFree->pNext->pPrev = pFree->pPrev;

		if (pFree == this->pFreeHead)
		{
			this->pFreeHead = pFree->pNext;
		}
	}

	this->currNumFreeBlocks--;
}

void Heap::setBelowAboveFlag(Free* block)
{
	Used* pBelow = block->BelowMe();

	uint32_t heapBottom = (uint32_t)this + Mem::TotalSize;

	if (heapBottom > (uint32_t)pBelow)
	{
		pBelow->bAboveFree = true;
	}
	
}

void Heap::setBelowAboveFlag(Used* block)
{
	Used* pBelow = block->BelowMe();

	uint32_t heapBottom = (uint32_t)this + Mem::TotalSize;

	if (heapBottom > (uint32_t)pBelow)
	{
		pBelow->bAboveFree = false;
	}
}

// ---  End of File ---
