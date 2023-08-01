//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Used.h"
#include "Free.h"
#include "Type.h"

Free::Free(uint32_t BlockSize)
	: mType(Type::FREE),
	bAboveFree(false),
	mDataSize((uint16_t)BlockSize),
	pNext(nullptr),
	pPrev(nullptr)
{
}

uint32_t Free::TotalDataSize()
{
	return (uint32_t)(this) + this->mDataSize;
}

Used* Free::BelowMe()
{
	uint32_t bottom = (uint32_t)(this + 1) + this->mDataSize;
	return (Used*)bottom;
}

// ---  End of File ---
