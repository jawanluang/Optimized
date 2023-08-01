//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Free.h"
#include "Used.h"

// Add code here
Used::Used(uint32_t BlockSize)
	:	mType(Type::USED), 
		bAboveFree(false), 
		mDataSize((uint16_t)BlockSize), 
		pNext(nullptr), 
		pPrev(nullptr)
{
}

uint32_t Used::TotalDataSize()
{
	return (uint32_t)(this + 1) + this->mDataSize;
}

// ---  End of File ---

