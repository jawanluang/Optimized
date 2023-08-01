//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "AList.h"
#include "Node.h"

PerformanceTimer t_List;

// For Teardown
static AList *pAList_0 = nullptr;

TEST_WITH_TEARDOWN(CreateList_Test_Enable, TestConfig::ALL)
{
#if CreateList_Test_Enable

	// Verify environment
	CHECK(sizeof(Node) == 24);

	//-----------------------------------------------------------------------------
	// 0) Create a timer objects
	//-----------------------------------------------------------------------------
	PerformanceTimer t2;

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// start timer
	t_List.Tic();

		// Do not modify or data this function, you need to leave this routine alone.
		pAList_0 = new AList(25000);

	t_List.Toc();

	// find a specific key
	Node foundNode;

	t2.Tic();

		// search the list for timing
		bool foundFlag = pAList_0->FindKey(0x7f9e1b10, foundNode);

	t2.Toc();

	// log the time and proof
	Trace::out2("Original linked list---------------------------\n");
	Trace::out2("   Finding Key: %f ms\n", t2.TimeInSeconds()*1000.0f);
	Trace::out2(" (Proof)   key: 0x%X  x:%d y:%d z:%d flag:%d\n", foundNode.key, foundNode.x, foundNode.y, foundNode.z, foundFlag);
	Trace::out2("\n");

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

    // This test doesn't count in grading
	_UnitStats.testCount--;
	_UnitStats.testPass--;

	delete pAList_0;
	pAList_0 = nullptr;


#endif	
} TEST_END


TEST_TEARDOWN( CreateList_Test_Enable )
{
#if CreateList_Test_Enable

	delete pAList_0;

#endif
}

// ---  End of File ---
