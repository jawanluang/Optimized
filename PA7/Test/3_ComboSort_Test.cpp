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

PerformanceTimer t_Combo;
int CutoffLength;

// Used for TEARDOWN
static AList *pAList_3 = nullptr;
static SearchList *pSearchList_3 = nullptr;

TEST_WITH_TEARDOWN(Combo_Test_Enable, TestConfig::ALL)
{
#if Combo_Test_Enable

	// Verify environment
	CHECK(sizeof(Node) == 24);
	CHECK(sizeof(SearchList) == 12);

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pAList_3 = new AList(25000);
	CHECK(pAList_3 != nullptr);

	// find a specific key
	Node foundNode;

	bool foundFlag = pAList_3->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) (Merge/Insert)Combo Timing
	//-----------------------------------------------------------------------------

	// Give a clean copy to the search class
	pSearchList_3 = new SearchList(pAList_3);

#ifdef TEST_MACHINE
  	// Test Macine on Keenan's PC
	CutoffLength = 64;	
#else
	// Experiment with this number for best results
	// Set the CutoffLength to the best value in the constuctor
	CutoffLength = pSearchList_3->GetCutoffLength();
#endif

	t_Combo.Tic();
		
		// -----------------------------------------------------------------------
		// ---->  Create this function, Merge Sort with Insertion Sort <---------- 
		// -----------------------------------------------------------------------
		// -----  CutoffLength is length that determines when to used   ----------
		// -----  Insertion Sort instead of Merge Sort for sublist of   ----------
		// -----  of smaller lengths                                    ---------- 
		// -----------------------------------------------------------------------
		pSearchList_3->MergeComboSort(CutoffLength);

	t_Combo.Toc();

	// Make sure new list is proper
	bool result = AList::VerifySortOrder(pSearchList_3);
	CHECK(result == true);

	delete pAList_3;
	pAList_3 = nullptr;

	delete pSearchList_3;
	pSearchList_3 = nullptr;

#endif
}  TEST_END

TEST_TEARDOWN(Combo_Test_Enable)
{
#if Combo_Test_Enable

	delete pAList_3;
	delete pSearchList_3;

#endif
}

// ---  End of File ---
