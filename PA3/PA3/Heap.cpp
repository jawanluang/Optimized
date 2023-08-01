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

}

void Heap::removeUsed(Used* pUsed)
{
	if (pUsed == this->pUsedHead)
	{
		this->pUsedHead = nullptr;
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
}

void Heap::insertFree(Free* pBefore, Free* pFree, Free* pAfter)
{
	if (nullptr != pBefore)
	{
		pBefore->pNext = pFree;
		pFree->pPrev = pBefore;
	}
	else
	{
		this->pFreeHead = pFree;
		this->pNextFit = pFree;
	}

	if (nullptr != pAfter)
	{
		pAfter->pPrev = pFree;
		pFree->pNext = pAfter;
	}
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
}

// ---  End of File ---
