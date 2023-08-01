//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Users
#include "Bloated.h"
#include "Node.h"
#include "JediHotCold.h"
#include "JediRedirect.h"

JediHotCold::JediHotCold(const Bloated * const pBloated)
{
	unsigned int cnt = 0;
	Node* temp = pBloated->GetListHead();
	while (nullptr != temp)
	{
		cnt++;
		temp = temp->pNext;
	}

	JediHotNode* hotArr = new JediHotNode[cnt / 8];
	JediRedirect* redArr = new JediRedirect[cnt / 8];
	JediColdNode* coldArr = new JediColdNode[cnt];

	this->pHotHead = hotArr;
	this->pRedirectHead = redArr;
	this->pColdHead = coldArr;

	JediHotNode* hFirst = hotArr;
	JediHotNode* hLast = hotArr + (cnt/8) - 1;
	JediHotNode* hCurr = hFirst;

	JediRedirect* rCurr = redArr;

	JediColdNode* cCurr = coldArr;

	int keyCount = 0;
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

		rCurr->pCold[keyCount] = cCurr;
		hCurr->key[keyCount] = temp->key;

		keyCount++;
		cCurr++;
		
		if (JediHotNode::KeyMax == keyCount)
		{
			hCurr->pNext = hCurr + 1;
			hCurr->pPrev = hCurr - 1;
			hCurr->pRedirect = rCurr;

			rCurr++;
			hCurr++;
			keyCount = 0;
		}
		else if (nullptr == temp)
		{
			hCurr->pNext = hCurr + 1;
			hCurr->pPrev = hCurr - 1;
			hCurr->pRedirect = rCurr;

			rCurr++;
			hCurr++;
		}
		
		temp = temp->pNext;
	}

	hFirst->pPrev = nullptr;
	hLast->pNext = nullptr;
}

JediHotCold::~JediHotCold()
{
	// HINT - do something here
	delete[] this->pHotHead;
	delete[] this->pRedirectHead;
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
bool JediHotCold::FindKey(int key, JediColdNode *&pFoundColdNode, JediHotNode *&pFoundHotNode)
{
	if (nullptr != this->pHotHead)
	{
		JediHotNode* temp = this->pHotHead;
		
		while (nullptr != temp)
		{	
			for (int i = 0; i < JediHotNode::KeyMax / 2; i++)
			{
				if (key == temp->key[i])
				{
					pFoundHotNode = temp;
					pFoundColdNode = temp->pRedirect->pCold[i];
					return true;
				}

				if (key == temp->key[JediHotNode::KeyMax - i - 1])
				{
					pFoundHotNode = temp;
					pFoundColdNode = temp->pRedirect->pCold[JediHotNode::KeyMax - i - 1];
					return true;
				}
			}

			temp = temp->pNext;
		}
	}

	return false;
}

JediHotNode *JediHotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---

