//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"

#include "HotDog.h"
#include "Order.h"
#include "Stand.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

static Order *pJamieOrder(nullptr);

TEST_WITH_TEARDOWN(BigFour_Orders, TestConfig::ALL)
{
#if BigFour_Orders
	
	// -----------------------------------------------
	// Default constructor
	// -----------------------------------------------
	Order R;
	CHECK(R.GetName() == Name::Unknown)
	CHECK(R.GetHead() == nullptr);

	// -----------------------------------------------
	// Specialize constructor
	// -----------------------------------------------
	Order S(Name::Arya);
	CHECK(S.GetName() == Name::Arya);
	CHECK(S.GetHead() == nullptr);

	// -----------------------------------------------
	// Create a complicated order
	// -----------------------------------------------
	pJamieOrder = new Order(Name::Jaime);

	CHECK(pJamieOrder != nullptr);
	CHECK(pJamieOrder->GetName() == Name::Jaime);
	CHECK(pJamieOrder->GetNext() == nullptr);
	CHECK(pJamieOrder->GetPrev() == nullptr);

	HotDog *A = new HotDog();
	CHECK(A != nullptr);

	A->Add(Condiments::Yellow_Mustard);
	A->Add(Condiments::Chopped_Onions);
	A->Add(Condiments::Pickle_Spear);
	A->Add(Condiments::Celery_Salt);
	CHECK(A->GetCondiments() == 0xd4);

	pJamieOrder->Add(A);

	HotDog *B = new HotDog();
	CHECK(B != nullptr);

	B->Add(Condiments::Yellow_Mustard);
	B->Add(Condiments::Chopped_Onions);
	B->Add(Condiments::Pickle_Spear);
	B->Add(Condiments::Celery_Salt);
	B->Add(Condiments::Ketchup);
	B->Add(Condiments::Tomato_Wedge);
	CHECK(B->GetCondiments() == 0xdd);

	pJamieOrder->Add(B);

	HotDog *C = new HotDog();
	CHECK(C != nullptr);

	C->Add(Condiments::Green_Relish);
	C->Add(Condiments::Chopped_Onions);
	C->Add(Condiments::Sport_Peppers);
	C->Add(Condiments::Celery_Salt);
	CHECK(C->GetCondiments() == 0xe2);

	pJamieOrder->Add(C);

	HotDog *D = new HotDog();
	CHECK(D != nullptr);

	D->Add(Condiments::Green_Relish);
	D->Add(Condiments::Chopped_Onions);
	D->Add(Condiments::Sport_Peppers);
	D->Add(Condiments::Celery_Salt);
	D->Add(Condiments::Ketchup);
	D->Add(Condiments::Tomato_Wedge);
	CHECK(D->GetCondiments() == 0xeb);

	pJamieOrder->Add(D);

	HotDog *pDog = pJamieOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xe2);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xe2);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xe2);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Copy constructor - with deep copy
	// -----------------------------------------------
	Order T(*pJamieOrder);

	// Make verify deep copy
	CHECK(T.GetName() == pJamieOrder->GetName());
	CHECK(T.GetNext() == nullptr);
	CHECK(T.GetPrev() == nullptr);

	pDog = T.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	HotDog *T0 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xe2);

	HotDog *T1 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xe2);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	HotDog *T2 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xe2);
	CHECK(pDog->GetNext() == nullptr);

	HotDog *T3 = pDog;

	// Make sure Jamie isn't corrupted
	pDog = pJamieOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	HotDog *S0 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xe2);

	HotDog *S1 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xe2);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	HotDog *S2 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xe2);
	CHECK(pDog->GetNext() == nullptr);

	HotDog *S3 = pDog;

	// Make sure they are not equal
	CHECK(T0 != S0);
	CHECK(T1 != S1);
	CHECK(T2 != S2);
	CHECK(T3 != S3);

	// -----------------------------------------------
	// Assignment operator
	// -----------------------------------------------
	Order M;
	CHECK(M.GetName() == Name::Unknown);
	CHECK(M.GetHead() == nullptr);

	M = *pJamieOrder;

	// Make verify deep copy
	CHECK(M.GetName() == pJamieOrder->GetName());
	CHECK(M.GetNext() == nullptr);
	CHECK(M.GetPrev() == nullptr);

	pDog = M.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	HotDog *M0 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xe2);

	HotDog *M1 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xe2);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	HotDog *M2 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xe2);
	CHECK(pDog->GetNext() == nullptr);

	HotDog *M3 = pDog;

	// Make sure Jamie isn't corrupted
	pDog = pJamieOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	S0 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xe2);

	S1 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xe2);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	S2 = pDog;

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xe2);
	CHECK(pDog->GetNext() == nullptr);

	S3 = pDog;

	// Make sure they are not equal
	CHECK(M0 != S0);
	CHECK(M1 != S1);
	CHECK(M2 != S2);
	CHECK(M3 != S3);

	// -----------------------------------------------
	// destructor - is called freeing up all HotDogs
	// -----------------------------------------------
	delete pJamieOrder;
	pJamieOrder = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(BigFour_Orders)
{
	delete pJamieOrder;
}

//---  End of File ---
