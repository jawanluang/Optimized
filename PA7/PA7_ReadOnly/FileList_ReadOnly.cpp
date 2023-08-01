//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "AList.h"
#include "Node.h"
#include "FileList.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

FileList::FileList(AList *pAList)
	:pHead(pAList->GetHead()),
	NumNodes(pAList->GetNumNodes())
{
	assert(pAList);

	// Really a Constructor and a Move... 
	pAList->SetHead(nullptr);
}

int FileList::GetNumNodes()
{
	return this->NumNodes;
}


bool FileList::FindKey(unsigned int key, Node &foundNode)
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



Node *FileList::GetHead() const
{
	return this->pHead;
}

void FileList::SetHead(Node *pNode)
{
	this->pHead = pNode;
}

// ---  End of File ---
