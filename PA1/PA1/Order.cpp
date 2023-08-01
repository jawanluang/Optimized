//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Order.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods

Order::Order()
{
	this->ordName = Name::Unknown;
	this->head = nullptr;
	this->next = nullptr;
	this->prev = nullptr;
}

Order::Order(const Order& r)
{
	this->ordName = r.ordName;
	if (nullptr != r.head)
	{
		HotDog* copyHead = new HotDog(*r.head);
		this->head = copyHead;

		HotDog* temp = r.head;
		while (nullptr != temp->GetNext())
		{
			HotDog* copyNext = new HotDog(*temp->GetNext());
			this->Add(copyNext);
			temp = temp->GetNext();
		}
	}
	else
	{
		this->head = nullptr;
	}
	

	this->next = nullptr;
	this->prev = nullptr;
}

Order& Order::operator = (const Order& r)
{
	this->ordName = r.ordName;
	if (nullptr != r.head)
	{
		HotDog* copyHead = new HotDog(*r.head);
		this->head = copyHead;

		HotDog* temp = r.head;
		while (nullptr != temp->GetNext())
		{
			HotDog* copyNext = new HotDog(*temp->GetNext());
			this->Add(copyNext);
			temp = temp->GetNext();
		}
	}
	else
	{
		this->head = nullptr;
	}

	this->next = nullptr;
	this->prev = nullptr;

	return *this;
}

Order::~Order()
{
	HotDog* temp = this->head;
	HotDog* nextDog;

	while (nullptr != temp)
	{
		nextDog = temp->GetNext();
		delete (temp);
		temp = nextDog;
	}
}

Order::Order(Name name)
{
	this->ordName = name;
	this->head = nullptr;
	this->next = nullptr;
	this->prev = nullptr;
}

void Order::DeleteOrder(Order* p)
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

void Order::Add(HotDog *p)
{
	if (nullptr != this->head)
	{
		HotDog* temp = this->head;
		while (nullptr != temp->GetNext())
		{
			temp = temp->GetNext();
		}
		temp->SetNext(p);
		p->SetPrev(temp);
	}
	else
	{
		this->head = p;
	}
	
}

void Order::Remove(HotDog *p)
{
	if (nullptr != this->head)
	{
		HotDog* temp = this->head;
		while (p != temp)
		{
			temp = temp->GetNext();
		}

		if (temp == this->head)
		{
			this->head = temp->GetNext();
		}
		temp->DeleteHotDog(p);
	}

}

Order * const Order::GetNext() const
{
	return this->next;
}

Order * const Order::GetPrev() const
{
	return this->prev;
}

HotDog * const Order::GetHead() const
{
	return this->head;
}

void Order::SetNext(Order *p)
{
	this->next = p;
}

void Order::SetPrev(Order *p)
{
	this->prev = p;
}

Name Order::GetName() const
{
	return this->ordName;
}

void Order::SetName(Name name)
{
	this->ordName = name;
}


//---  End of File ---
