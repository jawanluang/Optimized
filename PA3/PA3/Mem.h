//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef MEM_H
#define MEM_H

#include "Heap.h"

class Mem
{
public:
	static const uint32_t TotalSize = (50 * 1024);
	static const uint32_t HeapAlign = 16;
	static const uint32_t HeapAlignMask = HeapAlign - 1;
	static const uint32_t HeaderGuards = 64;

	enum class Guard
	{
		Type_A,
		Type_5
	};

public:

	Mem( Guard type );	

	Mem() = delete;
	Mem(const Mem &) = delete;
	Mem & operator = (const Mem &) = delete;
	~Mem();

	// implement these functions
	void free( void * const data );
	void *malloc( const uint32_t size );
	void initialize( );

	// helper functions
	Heap *GetHeap();
	void Print(int count);

private:

	uint32_t privGetBottom() const;
	Free* FindFree(Free* freeHead, uint32_t size);
	Used* allocateAll(Free* pFree, uint32_t size);
	Used* allocatePartial(Free* pFree, uint32_t size);
	Free* freeUsedBlock(Used* pUsed);
	Free* checkBlockBelow(Free* pFree);
	

private:
	// Useful in malloc and free
	Heap *poHeap;

	// Below: 
	//    Not used in malloc, free, or initialize
	Guard type;	
	void *poRawMem;
};

#endif 

// ---  End of File ---

