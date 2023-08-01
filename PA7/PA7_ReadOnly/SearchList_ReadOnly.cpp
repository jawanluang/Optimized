//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "SearchList.h"
#include "Node.h"
#include "AList.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

SearchList::SearchList(AList *pAList)
:pHead(pAList->GetHead()),
NumNodes(pAList->GetNumNodes()),
mCutoffLength(SearchList::CUT_OFF)
{
	assert(pAList);

	// Really a Constructor and a Move... 
	pAList->SetHead(nullptr);
}

SearchList::~SearchList()
{
	// LOAD from RAM: used in unit tests 0-5
	Node *pTmp = this->GetHead();
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

int SearchList::GetNumNodes() const
{
	return this->NumNodes;
}

int SearchList::GetCutoffLength()
{
	return this->mCutoffLength;
}

Node *SearchList::GetHead() const
{
	return this->pHead;
}

void SearchList::SetHead(Node *pNode)
{
	this->pHead = pNode;
}

// ---  End of File ---
