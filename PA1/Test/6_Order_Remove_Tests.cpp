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

TEST(Remove_Orders, TestConfig::ALL)
{
#if Remove_Orders

	// -----------------------------------------------
	// Create a Jamie order
	// -----------------------------------------------
	Order *pJamieOrder = new Order(Name::Jaime);
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

	const HotDog *pDog = pJamieOrder->GetHead();
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
	// Create a Cersei order
	// -----------------------------------------------
	Order *pCerseiOrder = new Order(Name::Cersei);
	CHECK(pCerseiOrder != nullptr);
	CHECK(pCerseiOrder->GetName() == Name::Cersei);
	CHECK(pCerseiOrder->GetNext() == nullptr);
	CHECK(pCerseiOrder->GetPrev() == nullptr);

	HotDog *E = new HotDog();
	CHECK(E != nullptr);

	E->Add(Condiments::Everything);
	E->Minus(Condiments::Tomato_Wedge);
	CHECK(E->GetCondiments() == 0xf6);

	pCerseiOrder->Add(E);

	HotDog *F = new HotDog();
	CHECK(F != nullptr);

	F->Add(Condiments::Everything);
	F->Add(Condiments::Ketchup);
	CHECK(F->GetCondiments() == 0xFF);

	pCerseiOrder->Add(F);

	pDog = pCerseiOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xf6);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xFF);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xFF);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xf6);
	CHECK(pDog->GetNext() == nullptr);


	// -----------------------------------------------
	// Create a Arya order
	// -----------------------------------------------
	Order *pAryaOrder = new Order(Name::Arya);
	CHECK(pAryaOrder != nullptr);
	CHECK(pAryaOrder->GetName() == Name::Arya);
	CHECK(pAryaOrder->GetNext() == nullptr);
	CHECK(pAryaOrder->GetPrev() == nullptr);

	HotDog *M11 = new HotDog();
	CHECK(M11 != nullptr);

	M11->Add(Condiments::Ketchup);
	M11->Add(Condiments::Tomato_Wedge);
	CHECK(M11->GetCondiments() == 0x09);

	pAryaOrder->Add(M11);

	HotDog *M22 = new HotDog();
	CHECK(M22 != nullptr);

	M22->Add(Condiments::Yellow_Mustard);
	M22->Add(Condiments::Pickle_Spear);
	CHECK(M22->GetCondiments() == 0x14);

	pAryaOrder->Add(M22);

	HotDog *M22_1 = new HotDog(*M22);
	CHECK(M22_1 != nullptr)

	pAryaOrder->Add(M22_1);

	HotDog *M22_2 = new HotDog(*M22);
	CHECK(M22_2 != nullptr);

	pAryaOrder->Add(M22_2);

	HotDog *M22_3 = new HotDog(*M22);
	CHECK(M22_3 != nullptr);

	pAryaOrder->Add(M22_3);

	pDog = pAryaOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0x09);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x09);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Create a Sansa order
	// -----------------------------------------------
	Order *pSansaOrder = new Order(Name::Sansa);
	CHECK(pSansaOrder != nullptr);
	CHECK(pSansaOrder->GetName() == Name::Sansa);
	CHECK(pSansaOrder->GetNext() == nullptr);
	CHECK(pSansaOrder->GetPrev() == nullptr);

	HotDog *M33 = new HotDog();
	CHECK(M33 != nullptr);

	M33->Add(Condiments::Ketchup);
	M33->Add(Condiments::Yellow_Mustard);
	M33->Add(Condiments::Tomato_Wedge);
	M33->Add(Condiments::Pickle_Spear);
	CHECK(M33->GetCondiments() == 0x1d);

	pSansaOrder->Add(M33);

	HotDog *M00 = new HotDog();
	CHECK(M00 != nullptr);
	CHECK(M00->GetCondiments() == 0x00);

	pSansaOrder->Add(M00);

	HotDog *M00_1 = new HotDog();
	CHECK(M00_1 != nullptr);
	CHECK(M00_1->GetCondiments() == 0x00);

	pSansaOrder->Add(M00_1);

	HotDog *M44 = new HotDog();
	CHECK(M44 != nullptr);

	M44->Add(Condiments::Green_Relish);
	M44->Add(Condiments::Sport_Peppers);
	CHECK(M44->GetCondiments() == 0x22);

	pSansaOrder->Add(M44);

	pDog = pSansaOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0x1d);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0x0);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x0);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x1d);
	CHECK(pDog->GetNext()->GetCondiments() == 0x0);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x0);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x0);
	CHECK(pDog->GetNext()->GetCondiments() == 0x22);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x22);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x0);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Stand - add 4 orders
	// -----------------------------------------------

	Stand stand;
	CHECK(stand.GetCurrOrders() == 0);
	CHECK(stand.GetPeakOrders() == 0);
	CHECK(stand.GetHead() == nullptr);

	stand.Add(pJamieOrder);
	CHECK(stand.GetCurrOrders() == 1);
	CHECK(stand.GetPeakOrders() == 1);

	const Order *pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Jaime);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext() == nullptr);

	stand.Add(pCerseiOrder);
	CHECK(stand.GetCurrOrders() == 2);
	CHECK(stand.GetPeakOrders() == 2);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Jaime);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext()->GetName() == Name::Cersei);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev()->GetName() == Name::Jaime);
	CHECK(pOrder->GetNext() == nullptr);

	stand.Add(pAryaOrder);

	CHECK(stand.GetCurrOrders() == 3);
	CHECK(stand.GetPeakOrders() == 3);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Jaime);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext()->GetName() == Name::Cersei);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev()->GetName() == Name::Jaime);
	CHECK(pOrder->GetNext()->GetName() == Name::Arya);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Arya);
	CHECK(pOrder->GetPrev()->GetName() == Name::Cersei);
	CHECK(pOrder->GetNext() == nullptr);

	stand.Add(pSansaOrder);

	// ---------------------------------------------------
	//  Verify the 4 orders with hotdogs
	// ---------------------------------------------------

	CHECK(stand.GetCurrOrders() == 4);
	CHECK(stand.GetPeakOrders() == 4);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Jaime);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext()->GetName() == Name::Cersei);

	pDog = pOrder->GetHead();
	CHECK(pDog != nullptr);

	// Verify Jaime's order
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
	CHECK(pDog->GetNext() == nullptr)

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	// Verify Cersei's order
	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev()->GetName() == Name::Jaime);
	CHECK(pOrder->GetNext()->GetName() == Name::Arya);

	pDog = pOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0xf6);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0xFF);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0xFF);
	CHECK(pDog->GetPrev()->GetCondiments() == 0xf6);
	CHECK(pDog->GetNext() == nullptr);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	// Verify Arya's order
	CHECK(pOrder->GetName() == Name::Arya);
	CHECK(pOrder->GetPrev()->GetName() == Name::Cersei);
	CHECK(pOrder->GetNext()->GetName() == Name::Sansa);

	pDog = pOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0x09);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x09);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext()->GetCondiments() == 0x14);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x14);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x14);
	CHECK(pDog->GetNext() == nullptr);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	// Verify Sansa's order
	CHECK(pOrder->GetName() == Name::Sansa);
	CHECK(pOrder->GetPrev()->GetName() == Name::Arya);
	CHECK(pOrder->GetNext() == nullptr);

	pDog = pOrder->GetHead();
	CHECK(pDog != nullptr);

	CHECK(pDog->GetCondiments() == 0x1d);
	CHECK(pDog->GetPrev() == nullptr);
	CHECK(pDog->GetNext()->GetCondiments() == 0x0);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x0);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x1d);
	CHECK(pDog->GetNext()->GetCondiments() == 0x0);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x0);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x0);
	CHECK(pDog->GetNext()->GetCondiments() == 0x22);

	pDog = pDog->GetNext();
	CHECK(pDog->GetCondiments() == 0x22);
	CHECK(pDog->GetPrev()->GetCondiments() == 0x0);
	CHECK(pDog->GetNext() == nullptr);

	// -----------------------------------------------
	// Remove Orders one at a Time
	// 
	//     Setup is done:  Jamie->Cersei->Arya->Sansa
	// -----------------------------------------------

	// -----------------------------------------------
	// Delete Arya
	//     Jamie->Cersei->Sansa
	// -----------------------------------------------
	stand.Remove(Name::Arya);

	CHECK(stand.GetCurrOrders() == 3);
	CHECK(stand.GetPeakOrders() == 4);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Jaime);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext()->GetName() == Name::Cersei);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev()->GetName() == Name::Jaime);
	CHECK(pOrder->GetNext()->GetName() == Name::Sansa);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Sansa);
	CHECK(pOrder->GetPrev()->GetName() == Name::Cersei);
	CHECK(pOrder->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete Jamie
	//     Cersei->Sansa
	// -----------------------------------------------
	stand.Remove(Name::Jaime);

	CHECK(stand.GetCurrOrders() == 2);
	CHECK(stand.GetPeakOrders() == 4);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext()->GetName() == Name::Sansa);

	pOrder = pOrder->GetNext();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Sansa);
	CHECK(pOrder->GetPrev()->GetName() == Name::Cersei);
	CHECK(pOrder->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete Sansa
	//     Cersei
	// -----------------------------------------------
	stand.Remove(Name::Sansa);

	CHECK(stand.GetCurrOrders() == 1);
	CHECK(stand.GetPeakOrders() == 4);

	pOrder = stand.GetHead();
	CHECK(pOrder != nullptr);

	CHECK(pOrder->GetName() == Name::Cersei);
	CHECK(pOrder->GetPrev() == nullptr);
	CHECK(pOrder->GetNext() == nullptr);

	// -----------------------------------------------
	// Delete Cersei
	//     empty
	// -----------------------------------------------
	stand.Remove(Name::Cersei);

	CHECK(stand.GetCurrOrders() == 0);
	CHECK(stand.GetPeakOrders() == 4);

	pOrder = stand.GetHead();
	CHECK(pOrder == nullptr);

#endif
} TEST_END

//---  End of File ---
