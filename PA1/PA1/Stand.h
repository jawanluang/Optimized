//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef STAND_H
#define STAND_H

// Add files include as needed
#include "Names.h"
#include "Order.h"

class Stand
{
public:
	// add code here (add more methods if desired)
	Stand();
	Stand(const Stand&);
	Stand& operator = (const Stand&);
	~Stand();

	// Public Methods (Required)
	void Remove(const Name name);
	void Add(Order * const pOrder);
	int GetCurrOrders() const;
	int GetPeakOrders() const;
	
	// Methods used for Testing and Internals (Required)
	Order * const GetHead();


private:
	// Data: ---------------------------
	//        add data here
	Order* ordHead;
	int orderSize;
	int orderPeak;
};

#endif

//---  End of File ---
