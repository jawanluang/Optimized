//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Stand.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods
Stand::Stand()
{
	this->ordHead = nullptr;
	this->orderSize = 0;
	this->orderPeak = 0;
}

Stand::Stand(const Stand& r)
{
	if (nullptr != r.ordHead)
	{
		Order* copyHead = new Order(*r.ordHead);
		this->ordHead = copyHead;

		Order* temp = r.ordHead;
		while (nullptr != temp->GetNext())
		{
			Order* copyNext = new Order(*temp->GetNext());
			this->Add(copyNext);
		}
	}
	else
	{
		this->ordHead = nullptr;
	}

	this->orderSize = r.orderSize;
	this->orderPeak = r.orderSize;
}

Stand& Stand::operator = (const Stand& r)
{
	if (nullptr != r.ordHead)
	{
		Order* copyHead = new Order(*r.ordHead);
		this->ordHead = copyHead;

		Order* temp = r.ordHead;
		while (nullptr != temp->GetNext())
		{
			Order* copyNext = new Order(*temp->GetNext());
			this->Add(copyNext);
		}
	}
	else
	{
		this->ordHead = nullptr;
	}

	this->orderSize = r.orderSize;
	this->orderPeak = r.orderSize;

	return *this;
}

Stand::~Stand()
{
	Order* temp = this->ordHead;
	Order* nextOrd;

	while (nullptr != temp)
	{
		nextOrd = temp->GetNext();
		delete (temp);
		temp = nextOrd;
	}
}

int Stand::GetCurrOrders() const
{
	return this->orderSize;
}

int Stand::GetPeakOrders() const
{
	return this->orderPeak;
}

Order * const Stand::GetHead()
{
	return this->ordHead;
}

void Stand::Remove(const Name name)
{
	if (nullptr != this->ordHead)
	{
		Order* temp = this->ordHead;
		while (name != temp->GetName())
		{
			temp = temp->GetNext();
		}

		if (temp == this->ordHead)
		{
			this->ordHead = temp->GetNext();
		}
		temp->DeleteOrder(temp);
	}

	this->orderSize = this->orderSize--;
}

void Stand::Add(Order * const pOrder)
{
	if (nullptr != this->ordHead)
	{
		Order* temp = this->ordHead;
		while (nullptr != temp->GetNext())
		{
			temp = temp->GetNext();
		}
		temp->SetNext(pOrder);
		pOrder->SetPrev(temp);
	}
	else
	{
		this->ordHead = pOrder;
	}

	this->orderSize = this->orderSize++;
	if (this->orderSize > this->orderPeak)
	{
		this->orderPeak = this->orderSize;
	}
}

//---  End of File ---
