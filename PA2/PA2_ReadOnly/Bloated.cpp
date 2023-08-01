//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

// user headers
#include "bloated.h"
#include "Node.h"

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//               starting from the head ptr using next until you find it
//
// Return true if you find the node
// Return the pointer in the argument list to the node (if found)
//----------------------------------------------------------------------------------

Node *Bloated::GetListHead() const
{
	return this->pHead;
}

Bloated::Bloated(const unsigned int NodeCount)
{
	// initialize it NULL
	this->pHead = nullptr;

	// Reset the seed
	// NO-ONE should ever call this function
	//        it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(2018);

	// create the nodes
	// this function magically initialize all the data with a set pattern
	Node *p = new Node[NodeCount];
	assert(p);

	// head
	this->pHead = p;

	// some markers...
	Node *pFirst = p;
	Node *pLast = p + NodeCount - 1;
	Node *pCurr = pFirst;

	// initialize the all nodes
	for (unsigned int i = 0; i < NodeCount; ++i)
	{
		pCurr->pNext = (pCurr + 1);
		pCurr->pPrev = (pCurr - 1);
		pCurr++;
	}

	// fix up the first and last node
	pLast->pNext = nullptr;
	pFirst->pPrev = nullptr;
}

Bloated::~Bloated()
{
	// it was created with array new, so you use delete array
	delete[] this->pHead;
}

// ---  End of File ---

