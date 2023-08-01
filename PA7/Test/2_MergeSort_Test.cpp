//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "SearchList.h"
#include "Node.h"
#include "AList.h"

// Used in Combo Test for comparision
PerformanceTimer t_Merge;

// Used for Teardown
static AList *pAList_2 = nullptr;
static SearchList *pSearchList_2 = nullptr;

TEST_WITH_TEARDOWN(Merge_Test_Enable, TestConfig::ALL)
{
#if Merge_Test_Enable

	// Verify environment
	CHECK(sizeof(Node) == 24);
	CHECK(sizeof(SearchList) == 12);

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pAList_2 = new AList(25000);
	CHECK(pAList_2 != nullptr);

	// find a specific key
	Node foundNode;

	bool foundFlag = pAList_2->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) Merge Sort Timing
	//-----------------------------------------------------------------------------
	
	// Give a clean copy to the search class
	pSearchList_2 = new SearchList(pAList_2);

	t_Merge.Tic();

		// -----------------------------------------------------
		// ---->  Create this function, use Merge sort  <-------
		// -----------------------------------------------------
		pSearchList_2->MergeSort();

	t_Merge.Toc();

	// Make sure new list is proper
	bool result = AList::VerifySortOrder(pSearchList_2);
	CHECK(result == true);

	delete pAList_2;
	pAList_2 = nullptr;

	delete pSearchList_2;
	pSearchList_2 = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(Merge_Test_Enable)
{
#if Merge_Test_Enable

	delete pAList_2;
	delete pSearchList_2;

#endif
}

// ---  End of File ---
