//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "HotDog.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods
HotDog::HotDog()
{
	this->condiments = 0x00;
	this->next = nullptr;
	this->prev = nullptr;
}

HotDog::HotDog(const HotDog& r)
{
	this->condiments = r.condiments;
	this->next = nullptr;
	this->prev = nullptr;
}

HotDog& HotDog::operator = (const HotDog& r)
{
	this->condiments = r.condiments;
	this->next = nullptr;
	this->prev = nullptr;

	return *this;
}

HotDog::~HotDog()
{
	// do nothing
}

void HotDog::DeleteHotDog(HotDog* p)
{
	if (nullptr != this->next && nullptr != this->prev)
	{
		this->next->prev = this->prev;
		this->prev->next = this->next;
	}
	else if (nullptr != this->prev)
	{
		this->prev->next = nullptr;
	}
	else if (nullptr != this->next)
	{
		this->next->prev = nullptr;
	}

	delete (p);
}

void HotDog::Minus(const Condiments condiment)
{
	// Only use bit-wise operations
	unsigned int base = this->condiments;
	unsigned int minus = (unsigned int)condiment;

	if (0x00 == base)
	{
		printf("it's already plain");
	}
	
	if (0x00 != minus)
	{
		minus = base & minus;
		base = base ^ minus;
	}

	this->condiments = (unsigned int)base;
}

void HotDog::Add(const Condiments condiment)
{
	// Only use bit-wise operations
	unsigned int base = this->condiments;
	unsigned int add = (unsigned int)condiment;

	base = base | add;
	
	this->condiments = (unsigned int)base;
}

unsigned int HotDog::GetCondiments() const
{
	return this->condiments;
}

HotDog * const HotDog::GetNext() const
{
	return this->next;
}

HotDog * const HotDog::GetPrev() const
{
	return this->prev;
}

void HotDog::SetNext(HotDog *pDog)
{
	this->next = pDog;
}

void HotDog::SetPrev(HotDog *pDog)
{
	this->prev = pDog;
}


// ---  End of File ---------------

