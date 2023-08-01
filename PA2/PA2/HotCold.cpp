//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"

HotCold::HotCold(const Bloated * const pBloated)
{
	unsigned int cnt = 0;
	Node* temp = pBloated->GetListHead();
	while (nullptr != temp)
	{
		cnt++;
		temp = temp->pNext;
	}

	HotNode* hotArr = new HotNode[cnt];
	ColdNode* coldArr = new ColdNode[cnt];

	this->pHotHead = hotArr;
	this->pColdHead = coldArr;

	HotNode* hFirst = hotArr;
	HotNode* hLast = hotArr + cnt - 1;
	HotNode* hCurr = hFirst;

	ColdNode* cCurr = coldArr;

	temp = pBloated->GetListHead();
	while (nullptr != temp)
	{
		cCurr->key = temp->key;
		cCurr->aa = temp->aa;
		cCurr->bb = temp->bb;
		cCurr->cc = temp->cc;
		cCurr->dd = temp->dd;
		cCurr->w = temp->w;
		cCurr->x = temp->x;
		cCurr->y = temp->y;
		cCurr->z = temp->z;
		cCurr->A = temp->A;
		cCurr->B = temp->B;
		cCurr->C = temp->C;
		cCurr->D = temp->D;
		cCurr->MA = temp->MA;
		cCurr->MB = temp->MB;
		cCurr->MC = temp->MC;
		cCurr->MD = temp->MD;
		cCurr->ME = temp->ME;
		memcpy(cCurr->name, temp->name, Node::NAME_SIZE);

		hCurr->key = temp->key;
		hCurr->pNext = hCurr + 1;
		hCurr->pPrev = hCurr - 1;
		hCurr->pCold = cCurr;

		cCurr++;
		hCurr++;
		temp = temp->pNext;
	}

	hFirst->pPrev = nullptr;
	hLast->pNext = nullptr;
}

HotCold::~HotCold()
{
	// HINT - do something here
	delete[] this->pHotHead;
	delete[] this->pColdHead;
}

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	if (nullptr != this->pHotHead)
	{
		HotNode* temp = this->pHotHead;

		if (key == temp->key)
		{
			pFoundHotNode = temp;
			pFoundColdNode = temp->pCold;
			return true;
		}
		else
		{
			temp = temp->pNext;
			while (nullptr != temp)
			{
				if (key == temp->key)
				{
					pFoundHotNode = temp;
					pFoundColdNode = temp->pCold;
					return true;
				}
				
				temp = temp->pNext;
			}
		}
	}

	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---

