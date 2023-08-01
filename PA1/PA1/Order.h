//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ORDER_H
#define ORDER_H

// Add files include as needed
#include "HotDog.h"
#include "Names.h"

class Order 
{
public:
	// add code here (add more methods if desired)
	Order();
	Order(const Order&);
	Order& operator = (const Order&);
	~Order();

	void DeleteOrder(Order* p);

	// Public Methods (Required)
	Order(const Name name);
	Name GetName() const;
	void SetName(const Name name);
	void Add(HotDog * const pDog);
	void Remove(HotDog * const pDog);

	// Methods used for Testing and Internals (Required)
	HotDog * const GetHead() const;
	Order * const GetNext() const;
	Order * const GetPrev() const;
	void SetNext(Order * const pOrder);
	void SetPrev(Order * const pOrder);


private:
	// Data: ---------------------------
	//        add data here
	Name ordName;
	HotDog* head;
	Order* next;
	Order* prev;
};

#endif

//---  End of File ---
