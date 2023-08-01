//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "SearchList.h"
#include "Node.h"
#include "AList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------
Node* sorted;

void SearchList::MergeSort()
{
	Node** start = &(this->pHead);

	MergeSortHelper(start);

}

void SearchList::InsertionSort()
{
	sorted = nullptr;
	Node* current = this->pHead;
	Node* nextTemp;

	while (nullptr != current)
	{
		nextTemp = current->pNext;

		SortedInsert(current);

		current = nextTemp;
	}

	this->pHead = sorted;
}

void SearchList::MergeComboSort(int CutoffLength)
{
	Node** start = &(this->pHead);

	ComboHelper(start, CutoffLength);
}

void SearchList::SortedInsert(Node* pNode)
{	
	if (nullptr == sorted || sorted->key >= pNode->key)
	{
		pNode->pNext = sorted;
		pNode->pPrev = nullptr;
		if (nullptr != sorted)
		{
			sorted->pPrev = pNode;
		}

		sorted = pNode;
	}
	else
	{
		Node* current = sorted;

		while (nullptr != current->pNext 
			&& current->pNext->key < pNode->key)
		{
			current = current->pNext;
		}

		pNode->pNext = current->pNext;
		if (nullptr != current->pNext)
		{
			current->pNext->pPrev = pNode;
		}
		

		current->pNext = pNode;
		pNode->pPrev = current;
	}
}

void SearchList::MergeSortHelper(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	if (nullptr == head || nullptr == head->pNext)
	{
		return;
	}

	FrontBackSplit(head, &a, &b);

	MergeSortHelper(&a);
	MergeSortHelper(&b);

	*headRef = SortedMerge(a, b);
}

Node* SearchList::SortedMerge(Node* a, Node* b)
{
	Node* result = nullptr;

	if (nullptr == a)
	{
		return b;
	}
	else if (nullptr == b)
	{
		return a;
	}

	if (a->key <= b->key)
	{
		result = a;
		result->pNext = SortedMerge(a->pNext, b);
		result->pNext->pPrev = result;
	}
	else
	{
		result = b;
		result->pNext = SortedMerge(a, b->pNext);
		result->pNext->pPrev = result;
	}

	result->pPrev = nullptr;
	return result;
}

void SearchList::FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->pNext;

	while (nullptr != fast)
	{
		fast = fast->pNext;
		if (nullptr != fast)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}

	*frontRef = source;
	*backRef = slow->pNext;
	slow->pNext = nullptr;
}

void SearchList::ComboHelper(Node** headRef, int cutOff)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	if (0 == cutOff)
	{
		sorted = nullptr;
		Node* current = *headRef;
		Node* nextTemp;

		while (nullptr != current)
		{
			nextTemp = current->pNext;

			SortedInsert(current);

			current = nextTemp;
		}

		*headRef = sorted;
	}
	else
	{
		if (nullptr == head || nullptr == head->pNext)
		{
			return;
		}

		FrontBackSplit(head, &a, &b);

		ComboHelper(&a, cutOff--);
		ComboHelper(&b, cutOff--);

		*headRef = SortedMerge(a, b);
	}
}

// ---  End of File ---
