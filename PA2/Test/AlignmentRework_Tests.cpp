//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "ReworkData.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Rework_Alignment, TestConfig::ALL)
{

	// Make sure you go to ReworkData.h
	// Rearrange to make size smaller (use alignment rules)
	// make Explicit padding

	DataA AA;
	DataB BB;
	DataC CC;
	DataD DD;
	DataE EE;
	Vect  VV;
	DataF FF;
	DataG GG;

	CHECK(sizeof(GG) == 56);
	CHECK(sizeof(FF) == 32);
	CHECK(sizeof(VV) == 20);
	CHECK(sizeof(EE) == 32);
	CHECK(sizeof(DD) == 16);
	CHECK(sizeof(CC) == 12);
	CHECK(sizeof(BB) == 24);
	CHECK(sizeof(AA) == 16);

} TEST_END

// ---  End of File ---

