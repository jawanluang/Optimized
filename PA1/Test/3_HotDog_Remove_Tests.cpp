//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"

#include "HotDog.h"
#include "Order.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Remove_HotDog, TestConfig::ALL)
{
#if Remove_HotDog

	// -----------------------------------------------
	// Create an order
	// -----------------------------------------------
	Order JamieOrder(Name::Jaime);

	CHECK(JamieOrder.GetHead() == nullptr);
	CHECK(JamieOrder.GetName() == Name::Jaime);
	CHECK(JamieOrder.GetNext() == nullptr);
	CHECK(JamieOrder.GetPrev() == nullptr);

	// -----------------------------------------------
	// Create 4 HotDogs to add to Order
	// -----------------------------------------------
	HotDog *pA3 = new HotDog();
	CHECK(pA3 != nullptr);

	pA3->Add(Condiments::Yellow_Mustard);
	pA3->Add(Condiments::Chopped_Onions);
	pA3->Add(Condiments::Pickle_Spear);
	pA3->Add(Condiments::Celery_Salt);
	CHECK(pA3->GetCondiments() == 0xd4);

	JamieOrder.Add(pA3);

	HotDog *pB3 = new HotDog();
	CHECK(pB3 != nullptr);

	pB3->Add(Condiments::Yellow_Mustard);
	pB3->Add(Condiments::Chopped_Onions);
	pB3->Add(Condiments::Pickle_Spear);
	pB3->Add(Condiments::Celery_Salt);
	pB3->Add(Condiments::Ketchup);
	pB3->Add(Condiments::Tomato_Wedge);
	CHECK(pB3->GetCondiments() == 0xdd);

	JamieOrder.Add(pB3);

	HotDog *pC3 = new HotDog();
	CHECK(pC3 != nullptr);

	pC3->Add(Condiments::Green_Relish);
	pC3->Add(Condiments::Chopped_Onions);
	pC3->Add(Condiments::Sport_Peppers);
	pC3->Add(Condiments::Celery_Salt);
	CHECK(pC3->GetCondiments() == 0xe2);

	JamieOrder.Add(pC3);

	HotDog *pD3 = new HotDog();
	CHECK(pD3 != nullptr);

	pD3->Add(Condiments::Green_Relish);
	pD3->Add(Condiments::Chopped_Onions);
	pD3->Add(Condiments::Sport_Peppers);
	pD3->Add(Condiments::Celery_Salt);
	pD3->Add(Condiments::Ketchup);
	pD3->Add(Condiments::Tomato_Wedge);
	CHECK(pD3->GetCondiments() == 0xeb);

	JamieOrder.Add(pD3);

	// Verify HotDogs in order
	CHECK(JamieOrder.GetName() == Name::Jaime);
	CHECK(JamieOrder.GetNext() == nullptr);
	CHECK(JamieOrder.GetPrev() == nullptr);

	const HotDog *pDog = JamieOrder.GetHead();
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
	// Remove HotDogs one at a Time
	// 
	//     Setup is done:  AA->BB->CC->DD
	// -----------------------------------------------

	// -----------------------------------------------
	// Delete CC
	//     AA->BB->DD
	// -----------------------------------------------
	JamieOrder.Remove(pC3);

	pDog = JamieOrder.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xd4);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xdd);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xd4);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete AA
	//     BB->DD
	// -----------------------------------------------
	JamieOrder.Remove(pA3);

	pDog = JamieOrder.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xeb);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xeb);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xdd);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete DD
	//     BB
	// -----------------------------------------------
	JamieOrder.Remove(pD3);

	pDog = JamieOrder.GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xdd);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete BB
	//     empty
	// -----------------------------------------------
	JamieOrder.Remove(pB3);

	pDog = JamieOrder.GetHead();
	CHECK(pDog == nullptr);

#endif
} TEST_END

//---  End of File ---
