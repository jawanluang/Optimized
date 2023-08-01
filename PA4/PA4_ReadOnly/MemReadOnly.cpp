//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Type.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#ifdef _DEBUG
	#define HEAP_SET_BOTTOM_A_GUARDS uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + Mem::TotalSize); \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA;	\
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA;

	#define HEAP_TEST_BOTTOM_A_GUARDS	uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + Mem::TotalSize); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA);

	#define HEAP_SET_BOTTOM_5_GUARDS uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + Mem::TotalSize); \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555;	\
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555;

	#define HEAP_TEST_BOTTOM_5_GUARDS	uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + Mem::TotalSize); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555);

#else
	#define HEAP_SET_BOTTOM_A_GUARDS  	
	#define HEAP_TEST_BOTTOM_A_GUARDS	
	#define HEAP_SET_BOTTOM_5_GUARDS  	
	#define HEAP_TEST_BOTTOM_5_GUARDS
#endif
							
Mem::~Mem()
{
	// do not modify this function
	if (this->type == Guard::Type_A)
	{
		HEAP_TEST_BOTTOM_A_GUARDS
	}
	else
	{
		HEAP_TEST_BOTTOM_5_GUARDS
	}
	_aligned_free(this->poRawMem);
}

Heap *Mem::GetHeap()
{
	return this->poHeap;
}

Mem::Mem(Guard _type)
{
	// now initialize it.
	this->poHeap = nullptr;
	this->poRawMem = nullptr;
	this->type = _type;

	// Do a land grab --- get the space for the entire heap
	// Since OS have Different Alignments... I forced it to 16 byte aligned
	poRawMem = _aligned_malloc(Mem::TotalSize + Mem::HeaderGuards, Mem::HeapAlign);

	// verify alloc worked
	assert(poRawMem != nullptr);
	
	if (this->type == Guard::Type_A)
	{
		HEAP_SET_BOTTOM_A_GUARDS
	}
	else
	{
		HEAP_SET_BOTTOM_5_GUARDS
	}

	// Guarantee alignemnt
	assert( ((uint32_t)poRawMem & Mem::HeapAlignMask) == 0x0 ); 

	Heap *p = new(poRawMem) Heap();
	assert(p);

	// update it
	this->poHeap = p;

}

void Mem::Print(int count)
{

	fprintf(FileIO::GetHandle(),"\n------- Print %d -------------\n\n",count);

	fprintf(FileIO::GetHandle(), "heapStart: 0x%p     \n", this->poHeap );
	fprintf(FileIO::GetHandle(), "  heapEnd: 0x%p   \n\n", (void *)((uint32_t)this->poHeap+Mem::TotalSize) );
	fprintf(FileIO::GetHandle(), "pUsedHead: 0x%p     \n", this->poHeap->pUsedHead );
	fprintf(FileIO::GetHandle(), "pFreeHead: 0x%p     \n", this->poHeap->pFreeHead );
	fprintf(FileIO::GetHandle(), " pNextFit: 0x%p   \n\n", this->poHeap->pNextFit);

	fprintf(FileIO::GetHandle(),"Heap Hdr   s: %p  e: %p                            size: 0x%x \n",(void *)this->poHeap, this->poHeap+1, sizeof(Heap) );

	uint32_t p = (uint32_t)(poHeap+1);

	char *blocktype;
	char *typeHdr;

	while( p < ((uint32_t)poHeap+Mem::TotalSize) )
	{
		Used *used = (Used *)p;
		if( used->mType == Type::USED )
		{
			typeHdr = "USED HDR ";
			blocktype = "USED     ";
		}
		else
		{
			typeHdr = "FREE HDR ";
			blocktype    = "FREE     ";
		}

		uint32_t hdrStart = (uint32_t)used;
		uint32_t hdrEnd   = (uint32_t)used + sizeof(Used);
		fprintf(FileIO::GetHandle(),"%s  s: %p  e: %p  p: %p  n: %p  size: 0x%x    AF: %d \n",typeHdr, (void *)hdrStart, (void *)hdrEnd, used->pPrev, used->pNext, sizeof(Used), used->bAboveFree );
	
		uint32_t blkStart = hdrEnd;
		uint32_t blkEnd   = blkStart + used->mDataSize; 
		fprintf(FileIO::GetHandle(),"%s  s: %p  e: %p                            size: 0x%x \n",blocktype, (void *)blkStart, (void *)blkEnd, used->mDataSize );

		p = blkEnd;
	}
}

// --- End of File ---
