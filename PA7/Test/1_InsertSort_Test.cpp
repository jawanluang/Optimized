//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "AList.h"
#include "SearchList.h"
#include "Node.h"

// used for comparison with merge
PerformanceTimer t_Insert;

// Used for Teardown
static AList *pAList_1 = nullptr;
static SearchList *pSearchList_1 = nullptr;

TEST_WITH_TEARDOWN(Insert_Test_Enable,TestConfig::ALL)
{

#if Insert_Test_Enable

	// Verify environment
	CHECK(sizeof(Node) == 24);
	CHECK(sizeof(SearchList) == 12);

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pAList_1 = new AList(25000);
	CHECK(pAList_1 != nullptr);

	// find a specific key
	Node foundNode;

	bool foundFlag = pAList_1->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) Insertion Sort Timing
	//-----------------------------------------------------------------------------

	// Give a clean copy to the search class
	pSearchList_1 = new SearchList(pAList_1);

	t_Insert.Tic();
		
		// ---------------------------------------------------------
		// ---->  Create this function, use insertion sort  <-------
		// ---------------------------------------------------------
		pSearchList_1->InsertionSort();

	t_Insert.Toc();

	// Make sure new list is proper
	bool result = AList::VerifySortOrder(pSearchList_1);
	CHECK(result == true);

	delete pAList_1;
	pAList_1 = nullptr;

	delete pSearchList_1;
	pSearchList_1 = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(Insert_Test_Enable)
{
#if Insert_Test_Enable

	delete pAList_1;
	delete pSearchList_1;

#endif
}

// ---  End of File ---
