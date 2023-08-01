//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "Node.h"
#include "AList.h"
#include "FileList.h"

// used for teardown
static AList *pAList_4 = nullptr;
static FileList *pFileList_4 = nullptr;

PerformanceTimer t_Create;

// Test functions helpers
bool FileCloseTest(const char * const pFileName);
bool FileSizeTest(const char * const pFileName);

TEST_WITH_TEARDOWN(WriteToFile_Test_Enable, TestConfig::ALL)
{
#if WriteToFile_Test_Enable

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pAList_4 = new AList(25000);
	CHECK(pAList_4 != nullptr);

	// find a specific key
	Node foundNode;

	bool foundFlag = pAList_4->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) Write data (SearchList) to File
	//-----------------------------------------------------------------------------

		pFileList_4 = new FileList();
		CHECK(pFileList_4 != nullptr);

		//	Make sure you are creating a fresh new file
		system("del /f *.bin");

		t_Create.Tic();

		// --------------------------------------------------------------
		// ---->  Create this function, SearchList::WritetoFile(...)  <-------
		// --------------------------------------------------------------

			// ------------------------------------------------------------------------
			// Rules:
			//
			//		File needs to be in Binary
			//	    Use: fopen,fread,fwrite,etc... 
			//		     Needs to use these functions for consistent timing across class
			//		No Streams/boost/STL/modern C++ - allowed
			//
			//		Add additional private methods or data as you see fit to the SearchList class
			//    
			// ------------------------------------------------------------------------
			// Using pSearchList... (original list) walk the list 
			//                  create and place data into a binary file 
			//                  make sure you close the file after you fill it with data
			// GRAD Students:
			//     This file needs to be LOAD in PLACE file
			//     Watch lecture, read the notes
			//
			// UNDERGRADS students:
			//     You aren't required to do LOAD in PLACE file
			//     It might be fun to try....
			//
			// Generate the Binary file
			// ------------------------------------------------------------------------
			
			pFileList_4->WriteToFile("Data.bin", pAList_4);
		
		t_Create.Toc();

		CHECK(FileCloseTest("Data.bin") == true);
		CHECK(FileSizeTest("Data.bin") == true);

		delete pAList_4;
		pAList_4 = nullptr;

		delete pFileList_4;
		pFileList_4 = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(WriteToFile_Test_Enable)
{
#if WriteToFile_Test_Enable

	delete pAList_4;
	delete pFileList_4;

#endif
}

// Test if the file is closed
bool FileCloseTest(const char * const pFileName)
{
	assert(pFileName);

	FILE *pTmpHandle2;
	errno_t status;
	status = fopen_s(&pTmpHandle2,pFileName, "rb");
	assert(pTmpHandle2);
	assert(status == 0);

	unsigned int data;
	unsigned int numBytes = fread(&data, 1, sizeof(unsigned int), pTmpHandle2);

	ferror(pTmpHandle2);

	return numBytes == sizeof(unsigned int);

}

// Test if the file is closed
bool FileSizeTest(const char * const pFileName)
{
	assert(pFileName);

	FILE *pTmpHandle2;
	errno_t status;
	status = fopen_s(&pTmpHandle2,pFileName, "rb");
	assert(pTmpHandle2);
	assert(status == 0);

	int error = fseek(pTmpHandle2, 0, SEEK_END);
	assert(error == 0);
	AZUL_UNUSED_VAR(error);

	int SizeOfFile = ftell(pTmpHandle2);

	ferror(pTmpHandle2);

	return SizeOfFile > sizeof(unsigned int);

}

// ---  End of File ---
