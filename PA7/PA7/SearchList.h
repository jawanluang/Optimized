//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef SEARCH_LIST_H
#define SEARCH_LIST_H

#include "Node.h"

class AList;

class SearchList
{
public:
	// ---> CHANGE this value
	static const unsigned int CUT_OFF = 128;

public:
	// Big four
	SearchList() = delete;
	~SearchList();
	SearchList(const SearchList &) = delete;
	SearchList &operator = (const SearchList &) = delete;

	SearchList(AList *pList);

	// Accessors
	Node *GetHead() const;
	void SetHead(Node *pNode);
	int GetNumNodes() const;

	// Class methods
	int GetCutoffLength(); 

	//---------------------------------------------------------------------------------------
	// Please implement(rework) these methods (add additional methods to help if you want)
	//---------------------------------------------------------------------------------------
	void InsertionSort();
	void MergeSort();
	void MergeComboSort(int CutoffLength);

	// Helper functions
	void SortedInsert(Node* pNode);
	void MergeSortHelper(Node** headRef);
	Node* SortedMerge(Node* a, Node* b);
	void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);
	void ComboHelper(Node** headRef, int cutOff);

private:
	// ------------------------------------------------------
	// Data - YOU CANNOT add or change data in this class
	// ------------------------------------------------------

	Node *pHead;
	int  NumNodes;
	int  mCutoffLength;
};

#endif 

// ---  End of File ---
