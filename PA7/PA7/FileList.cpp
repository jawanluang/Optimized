//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "AList.h"
#include "Node.h"
#include "FileList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------

FileList::FileList()
: pHead(nullptr),
NumNodes(0)
{
	// Hint you might need to rework this...
	// if you add data to FileList class
	// 
	// probably add a buffer
}

FileList::~FileList()
{
	// Hint you might need to rework this...

	Node* temp = this->pHead;
	Node* nextNode;

	while (nullptr != temp)
	{
		nextNode = temp->getNext();
		delete (temp);
		temp = nextNode;
	}
}


void FileList::WriteToFile(const char * const pFileName, AList *pAList)
{
	// Do your magic

	// Make sure you close the file after you fill it
	// Use fopen,fwrite,ftell,...,fclose

	// Hint: Open the file, write the nodes into the file 

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method

	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor..

	// Quick sample code... remove this code and replace with your own

	FILE *pFileHandle = nullptr;
	errno_t status = 1;

	if (nullptr != pFileName)
	{
		status = fopen_s(&pFileHandle, pFileName, "wb");
	}
	
	if (0 == status)
	{
		Node* pAListNode = pAList->GetHead();

		while (nullptr != pAListNode)
		{
			fwrite(&pAListNode, sizeof(Node), 1, pFileHandle);

			pAListNode = pAListNode->pNext;
		}
	}

	fclose(pFileHandle);

}

FileList::FileList(const char * const pFileName, int numNodes)
{
	// Do your magic here:

	// Create the Linked List... You cannot use the original code
	// The input file, and numNodes is all you need to recreate the FileList
	
	// Hint: Open the file, read and create new nodes, 
	//       fill them with the data from the file

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	     
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor.

	// Quick sample code... remove this code and replace with your own

	this->pHead = nullptr;
	this->NumNodes = numNodes;

	FILE* pFileHandle = nullptr;
	errno_t status = 1;

	if (nullptr != pFileName)
	{
		status = fopen_s(&pFileHandle, pFileName, "rb");
	}
	
	if (0 == status)
	{
		Node* current = nullptr;

		for (int i = 0; i < this->NumNodes; i++)
		{
			Node* data = new Node();
			fread(&data, sizeof(Node), 1, pFileHandle);

			if (nullptr == current)
			{
				current = data;
				current->pPrev = nullptr;

				this->pHead = current;
			}
			else
			{
				current->pNext = data;
				data->pPrev = current;

				current = current->pNext;
			}
		}

		
	}

	fclose(pFileHandle);
}

// ---  End of File ---
