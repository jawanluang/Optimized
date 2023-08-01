//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "AlignData.h"
#include "Align.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

static char *pBuff = nullptr;

TEST_WITH_TEARDOWN(Print_Alignment, TestConfig::ALL)
{

	Align::Info Info;

	// Create a tmp buffer
	const unsigned int BUFF_SIZE = 256;
	pBuff = new char[BUFF_SIZE];
	assert(pBuff != nullptr);
	
	//-------------------------------------------
	// Structure A:
	//-------------------------------------------

	// Fill tmp buffer with 0xAA
	memset(pBuff, 0xAA, BUFF_SIZE);

	// Construct structure in the memory
	AZUL_PLACEMENT_NEW_BEGIN
	#undef new

		A *pA = new(pBuff) A();

	AZUL_PLACEMENT_NEW_END

	// Print it
	Info = Align::PrintME(pA, sizeof(A), "data A");

	CHECK(Info.NumTotalBytes == 8);
	CHECK(Info.NumBytesOfPadding == 3);

	//-------------------------------------------
	// Structure B:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);

	AZUL_PLACEMENT_NEW_BEGIN
	#undef new

		B *pB = new(pBuff) B();

	AZUL_PLACEMENT_NEW_END

	Info = Align::PrintME(pB, sizeof(B), "data B");

	CHECK(Info.NumTotalBytes == 16);
	CHECK(Info.NumBytesOfPadding == 3);

	//-------------------------------------------
	// Structure C:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);

	AZUL_PLACEMENT_NEW_BEGIN
	#undef new

		C *pC = new(pBuff) C();

	AZUL_PLACEMENT_NEW_END

	Info = Align::PrintME(pC, sizeof(C), "data C");

	CHECK(Info.NumTotalBytes == 24);
	CHECK(Info.NumBytesOfPadding == 14);

	//-------------------------------------------
	// Structure D:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);
	
	AZUL_PLACEMENT_NEW_BEGIN
	#undef new

		D *pD = new(pBuff) D();

	AZUL_PLACEMENT_NEW_END

	Info = Align::PrintME(pD, sizeof(D), "data D");

	CHECK(Info.NumTotalBytes == 64);
	CHECK(Info.NumBytesOfPadding == 27);

	//-------------------------------------------
	// Structure E:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);

	AZUL_PLACEMENT_NEW_BEGIN
	#undef new

		E* pE = new(pBuff) E();

	AZUL_PLACEMENT_NEW_END

	Info = Align::PrintME(pE, sizeof(E), "data E");

	CHECK(Info.NumTotalBytes == 56);
	CHECK(Info.NumBytesOfPadding == 27);

	delete[] pBuff;
	pBuff = nullptr;

} TEST_END


TEST_TEARDOWN(Print_Alignment)
{
	delete[] pBuff;
}


// ---  End of File ---
