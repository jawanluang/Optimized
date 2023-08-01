//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef VECT_H
#define VECT_H

struct Vect
{
	Vect() = default;
	Vect(const Vect&) = default;
	Vect& operator = (const Vect&);
	~Vect();

	// You CANNOT add additional data to this class
	float x;
	float y;
	float z;
};

#endif

// ---  End of File ---

