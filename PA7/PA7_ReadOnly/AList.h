//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef A_LIST_H
#define A_LIST_H

#include "Node.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

class SearchList;
class FileList;

class AList
{
public:
	// Test Machine
	static const unsigned int CUT_OFF = 64;

public:
	// specialization
	AList(int numNodes);

	// Big four
	AList() = delete;
	~AList();
	AList(const AList &) = delete;
	AList &operator = (const AList &) = delete;

	// Accessors
	Node *GetHead();
	void SetHead(Node *pNode);
	int GetNumNodes();

	// Class methods
	bool FindKey(unsigned int key, Node &foundNode);

	// Static Methods
	static bool Verify(const FileList *const pNew, const AList * const pOld);
	static bool VerifySortOrder(const SearchList *const pList);

private:

	// methods
	void privCreateLinkedList(int numNodes);

	// -----------------------------------
	// data
	// -----------------------------------

	Node *pHead;
	int  NumNodes;
	int  mCutoffLength;

};

#endif 

// ---  End of File ---
