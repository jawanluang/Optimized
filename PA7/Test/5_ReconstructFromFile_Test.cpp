//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "FileList.h"
#include "Node.h"
#include "AList.h"

static AList *pAList_5 = nullptr;
static FileList *pNewFileList = nullptr;

PerformanceTimer t_Recreate;
PerformanceTimer t_Verify;
bool VerifyResult;

TEST_WITH_TEARDOWN(ReadFromFile_Test_Enable, TestConfig::ALL)
{
#if ReadFromFile_Test_Enable

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pAList_5 = new AList(25000);
	CHECK(pAList_5 != nullptr);

	// find a specific key
	Node foundNode;

	bool foundFlag = pAList_5->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) Read data from File to SearchList
	//-----------------------------------------------------------------------------

	t_Recreate.Tic();

		// ------------------------------------------------------------------------
		// Rules:
		//
		// Read the Binary file and reconstruct the SearchList from the File
		//
		//		File needs to be in Binary
		//	    Use: fopen,fread,fwrite,etc... 
		//		     Needs to use these functions for consistent timing across class
		//		No Streams/boost/STL/modern C++ - allowed
		//
		//		Add additional private methods or data as you see fit to the SearchList class
		//
		// ------------------------------------------------------------------------
		// Using your file system, 
		//				  Read YOUR FILE and reconstruct a new SearchList into pNewSearchList
		//                Make sure you close the file after you the creation 
		//
		// GRAD Students:
		//     This file needs to be "LOAD in PLACE" flie
		//	   Recreation of List should not be more than 2 or 3 new() calls in total
		//     Make sure you flip the LOAD_IN_PLACE to TRUE;
		//     Watch lecture, read the notes
		//
		// UNDERGRADS students:
		//     You aren't required to do LOAD in PLACE file
		//     It might be fun to try....
		//
		// ------------------------------------------------------------------------

		pNewFileList = new FileList("Data.bin", 25000);

	t_Recreate.Toc();


	//-----------------------------------------------------------------------------
	// 3) Verify data
	//-----------------------------------------------------------------------------

	t_Verify.Tic();
		VerifyResult = AList::Verify(pNewFileList, pAList_5);
	t_Verify.Toc();

	CHECK(VerifyResult == true);

	delete pAList_5;
	pAList_5 = nullptr;

	delete pNewFileList;
	pNewFileList = nullptr;


#endif
} TEST_END

TEST_TEARDOWN(ReadFromFile_Test_Enable)
{
#if ReadFromFile_Test_Enable

	delete pAList_5;
	delete pNewFileList;

#endif
}

// ---  End of File ---
