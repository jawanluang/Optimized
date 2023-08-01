//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Vect.h"

// Insert code if desired

Vect& Vect::operator = (const Vect& r)
{
	this->x = r.x;
	this->y = r.y;
	this->z = r.z;

	return *this;
}

Vect::~Vect()
{
	// do nothing?
}

// ---  End of File ---

