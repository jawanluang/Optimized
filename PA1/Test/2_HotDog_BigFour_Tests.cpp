//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"

#include "HotDog.h"
#include "Order.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------
static HotDog *pE2(nullptr);

TEST_WITH_TEARDOWN(Big_Four, TestConfig::ALL)
{
#if Big_Four

	// -----------------------------------------------
	// Default constructor
	// -----------------------------------------------
	HotDog  A;
	CHECK(A.GetNext() == nullptr);
	CHECK(A.GetPrev() == nullptr);
	CHECK(A.GetCondiments() == 0);

	HotDog  AA;
	CHECK(A.GetNext() == nullptr);
	CHECK(A.GetPrev() == nullptr);
	CHECK(A.GetCondiments() == 0);

	// -----------------------------------------------
	// B - complicated node used in copy constructor
	// -----------------------------------------------
	HotDog B;

	B.Add(Condiments::Everything);
	B.Minus(Condiments::Chopped_Onions);
	B.Minus(Condiments::Green_Relish);
	B.Add(Condiments::Ketchup);
	B.SetNext(&AA);
	B.SetPrev(&A);
	CHECK(B.GetNext() == &AA);
	CHECK(B.GetPrev() == &A);
	CHECK(B.GetCondiments() == 0x7d);

	// -----------------------------------------------
	// Copy constructor
	// -----------------------------------------------
	HotDog C(B);

	// Copy B into C
	CHECK(C.GetNext() == nullptr);
	CHECK(C.GetPrev() == nullptr);
	CHECK(C.GetCondiments() == 0x7d);

	// Make sure B isn't corrupted
	CHECK(B.GetNext() == &AA);
	CHECK(B.GetPrev() == &A);
	CHECK(B.GetCondiments() == 0x7d);

	// -----------------------------------------------
	// Assignment operator
	// -----------------------------------------------
	HotDog D;
	CHECK(D.GetNext() == nullptr);
	CHECK(D.GetPrev() == nullptr);
	CHECK(D.GetCondiments() == 0);

	D = B;

	// Copy B into C
	CHECK(D.GetNext() == nullptr);
	CHECK(D.GetPrev() == nullptr);
	CHECK(D.GetCondiments() == 0x7d);

	// Make sure B isn't corrupted
	CHECK(B.GetNext() == &AA);
	CHECK(B.GetPrev() == &A);
	CHECK(B.GetCondiments() == 0x7d);

	// -----------------------------------------------
	// Destructor
	// -----------------------------------------------
	pE2 = new HotDog();
	CHECK(pE2 != nullptr);

	pE2->Add(Condiments::Yellow_Mustard);
	CHECK(pE2->GetCondiments() == 0x10);
	CHECK(pE2->GetNext() == nullptr);
	CHECK(pE2->GetPrev() == nullptr);

	delete pE2;
	pE2 = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(Big_Four)
{
	delete pE2;
}

//---  End of File ---
