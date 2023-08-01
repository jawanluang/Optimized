//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"

#include "HotDog.h"
#include "Order.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Add_HotDog, TestConfig::ALL)
{
#if Add_HotDog

	// -----------------------------------------------
	// Create an order
	// -----------------------------------------------
	Order JamieOrder(Name::Jaime);

	CHECK(JamieOrder.GetHead() == nullptr);
	CHECK(JamieOrder.GetName() == Name::Jaime);
	CHECK(JamieOrder.GetNext() == nullptr);
	CHECK(JamieOrder.GetPrev() == nullptr);

	// -----------------------------------------------
	// Add a HotDog to an Order
	// -----------------------------------------------
	HotDog *pA4 = new HotDog();
	CHECK(pA4 != nullptr);

	pA4->Add(Condiments::Yellow_Mustard);
	pA4->Add(Condiments::Chopped_Onions);
	pA4->Add(Condiments::Pickle_Spear);
	pA4->Add(Condiments::Celery_Salt);
	CHECK(pA4->GetCondiments() == 0xd4);

	JamieOrder.Add(pA4);

	const HotDog *pDog = JamieOrder.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Add a HotDog to an Order
	// -----------------------------------------------
	HotDog *pB4 = new HotDog();
	CHECK(pB4 != nullptr);

	pB4->Add(Condiments::Yellow_Mustard);
	pB4->Add(Condiments::Chopped_Onions);
	pB4->Add(Condiments::Pickle_Spear);
	pB4->Add(Condiments::Celery_Salt);
	pB4->Add(Condiments::Ketchup);
	pB4->Add(Condiments::Tomato_Wedge);
	CHECK(pB4->GetCondiments() == 0xdd);

	JamieOrder.Add(pB4);

	pDog = JamieOrder.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Add a HotDog to an Order
	// -----------------------------------------------
	HotDog *pC4 = new HotDog();
	CHECK(pC4 != nullptr);

	pC4->Add(Condiments::Green_Relish);
	pC4->Add(Condiments::Chopped_Onions);
	pC4->Add(Condiments::Sport_Peppers);
	pC4->Add(Condiments::Celery_Salt);
	CHECK(pC4->GetCondiments() == 0xe2);

	JamieOrder.Add(pC4);

	pDog = JamieOrder.GetHead();
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
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Add a HotDog to an Order
	// -----------------------------------------------
	HotDog *pD4 = new HotDog();
	CHECK(pD4 != nullptr);

	pD4->Add(Condiments::Ketchup);
	pD4->Add(Condiments::Green_Relish);
	pD4->Add(Condiments::Chopped_Onions);
	pD4->Add(Condiments::Sport_Peppers);
	pD4->Add(Condiments::Celery_Salt);
	pD4->Add(Condiments::Ketchup);
	pD4->Add(Condiments::Tomato_Wedge);
	CHECK(pD4->GetCondiments() == 0xeb);

	JamieOrder.Add(pD4);

	pDog = JamieOrder.GetHead();
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

#endif
} TEST_END

//---  End of File ---
