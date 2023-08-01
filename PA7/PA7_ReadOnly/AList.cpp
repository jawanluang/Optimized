//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Node.h"
#include "SearchList.h"
#include "FileList.h"
#include "AList.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

int AList::GetNumNodes()
{
	return this->NumNodes;
}

void AList::privCreateLinkedList(int numNodes)
{
	// initialize it NULL
	this->pHead = nullptr;
	this->NumNodes = numNodes;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(2017);

	// create the nodes
	Node *pCurr = new Node();
	pCurr->setPrev(nullptr);
	this->pHead = pCurr;
	Node *pPrev = pCurr;

	// initialize the all nodes
	for (int i = 0; i < this->NumNodes - 1; ++i)
	{
		pCurr = new Node();

		// Update links
		pCurr->setPrev(pPrev);

		if (pPrev != nullptr)
		{
			pPrev->setNext(pCurr);
		}

		pPrev = pCurr;
	}

	// last node
	pCurr->setNext(nullptr);

}

bool AList::VerifySortOrder(const SearchList* const pList)
{
	bool Result = false;

	// Don't crash 
	if (pList == nullptr)
	{
		return false;
	}

	Node* pTmp = pList->GetHead();
	Node* pTmpPrev = nullptr;
	unsigned int prevKey = 0;
	int count = 0;

	// Loop forward through the list
	while (pTmp != nullptr)
	{
		//Trace::out("%i) %x %x\n", count, pTmp->key, prevKey);  // <--- verify 
		count++;
		pTmpPrev = pTmp;

		// is this the node?
		if (pTmp->key >= prevKey)   // <--- changed
		{
			// Good keep going
			Result = true;
		}
		else
		{
			// yes error, then break
			Result = false;
			break;
		}

		prevKey = pTmp->key;   // <--- changed

		// go to next
		pTmp = pTmp->pNext;

		// Quick test
		if (pTmp != nullptr)
		{
			// Check back pointers
			if (pTmpPrev != pTmp->pPrev)
			{
				// yes error, then break
				Result = false;
				break;
			}
		}

	}

	// Better be at the end
	if (count != pList->GetNumNodes())
	{
		return false;
	}

	// Now move backwards through the list
	pTmp = pTmpPrev;

	pTmpPrev = nullptr;
	prevKey = pTmp->key + 1;
	count = 0;

	// Loop forward through the list
	while (pTmp != nullptr)
	{
		//Trace::out("%i) %x %x\n", count, pTmp->key, prevKey);  // <--- verify
		count++;
		pTmpPrev = pTmp;

		// is this the node?
		if (pTmp->key <= prevKey)  // <--- changed
		{
			// Good keep going
			Result = true;
		}
		else
		{
			// yes error, then break
			Result = false;
			break;
		}

		prevKey = pTmp->key;   // <-- changed

		// go to prev
		pTmp = pTmp->pPrev;

		// Quick test
		if (pTmp != nullptr)
		{
			// Check back pointers
			if (pTmpPrev != pTmp->pNext)
			{
				// yes error, then break
				Result = false;
				break;
			}
		}
	}

	// Better be at the beginning
	if (count != pList->GetNumNodes())
	{
		return false;
	}

	return Result;
}

bool AList::Verify(const FileList *pNew, const AList *const pOld)
{
	bool Result = false;

	// Don't crash 
	if (pNew == nullptr || pOld == nullptr)
	{
		return false;
	}

	Node *pTmp = pOld->pHead;
	Node *pTmp2 = pNew->GetHead();

	Node *pTmpOld = nullptr;
	Node *pTmp2Old = nullptr;

	unsigned int count = 0;

	// Loop until you find a node
	while (pTmp != nullptr && pTmp2 != nullptr)
	{
		count++;

		// keep old
		pTmpOld = pTmp;
		pTmp2Old = pTmp2;

		// is this the node?
		if (*pTmp == *pTmp2)
		{
			// Good keep going
			Result = true;
		}
		else
		{
			// yes error, then break
			Result = false;
			break;
		}

		// go to next
		pTmp = pTmp->pNext;
		pTmp2 = pTmp2->pNext;

		// Quick test
		if (pTmp != nullptr && pTmp2 != nullptr)
		{
			// Check back pointers
			if (pTmpOld != pTmp->pPrev)
			{
				// yes error, then break
				Result = false;
				break;
			}

			if (pTmp2Old != pTmp2->pPrev)
			{
				// yes error, then break
				Result = false;
				break;
			}
		}
	}

	pTmp = pTmpOld;
	pTmp2 = pTmp2Old;

	// Loop until you find a node from End to beginning
	while (pTmp != nullptr && pTmp2 != nullptr)
	{
		count++;

		// keep old
		pTmpOld = pTmp;
		pTmp2Old = pTmp2;

		// is this the node?
		if (*pTmp == *pTmp2)
		{
			// Good keep going
			Result = true;
		}
		else
		{
			// yes error, then break
			Result = false;
			break;
		}

		// go to next
		pTmp = pTmp->pPrev;
		pTmp2 = pTmp2->pPrev;

		// Quick test
		if (pTmp != nullptr && pTmp2 != nullptr)
		{
			// Check back pointers
			if (pTmpOld != pTmp->pNext)
			{
				// yes error, then break
				Result = false;
				break;
			}

			if (pTmp2Old != pTmp2->pNext)
			{
				// yes error, then break
				Result = false;
				break;
			}
		}
	}

	//total count
	if (count != 50000)
	{
		Result = false;
	}

	return Result;
}

bool AList::FindKey(unsigned int key, Node &foundNode)
{
	bool foundFlag(false);

	Node *p = this->pHead;

	// Loop until you find a node
	while (p != nullptr)
	{
		// is this the node?
		if (p->key == key)
		{
			// yes, then break
			foundFlag = true;
			break;
		}

		// go to next
		p = p->pNext;
	}

	// return the node reference that contains the key
	if (foundFlag)
	{
		foundNode = *p;
	}

	// flag
	return foundFlag;
}

AList::AList(int numNodes)
	: pHead(nullptr),
 NumNodes(numNodes),
	mCutoffLength(AList::CUT_OFF)
{
	this->privCreateLinkedList(numNodes);
}

AList::~AList()
{
	// LOAD from RAM: used in unit tests 0-5
	Node *pTmp = this->pHead;
	Node *pNode = nullptr;
	while (pTmp != nullptr)
	{
		pNode = pTmp;
		pTmp = pTmp->getNext();

		// Make sure the data is scrambled before delete
		pNode->BlowUp();
		delete pNode;
	}

	this->SetHead(nullptr);
}


Node *AList::GetHead()
{
	return this->pHead;
}

void AList::SetHead(Node *pNode)
{
	this->pHead = pNode;
}

// ---  End of File ---
