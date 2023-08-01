//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef HOTDOG_H
#define HOTDOG_H

// Add files include as needed
#include "Condiments.h"

class HotDog
{
public:
	// add code here (add more methods if desired)
	HotDog();
	HotDog(const HotDog&);
	HotDog& operator = (const HotDog&);
	~HotDog();

	void DeleteHotDog(HotDog* p);
	 
	// Public Methods (Required)
	void Minus(const Condiments condiment);
	void Add(const Condiments condiment);

	// Methods for Testing and Internals (Required)
	unsigned int GetCondiments() const;
	HotDog * const GetNext() const;
	HotDog * const GetPrev() const;
	void SetNext(HotDog * const pDog);
	void SetPrev(HotDog * const pDog);
	
	// Debugging
	void Print(int num = -1, int numTabs = 0) const;

private:
	// Data: ---------------------------
	//        add data here
	// add links (next/prev)... 
	//
	// use the condiments unsigned integer provided
	// no additional data for condiments
	//
	HotDog* next;
	HotDog* prev;
	unsigned int condiments;
};

#endif

//---  End of File ---
