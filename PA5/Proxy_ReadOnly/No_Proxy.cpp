//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "No_Proxy.h"

Vect2D_No_Proxy Vect2D_No_Proxy::operator + (const Vect2D_No_Proxy &tmp) const
{
	Vect2D_No_Proxy sum;

	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;

	return (sum);
};

void Vect2D_No_Proxy::setX(const float inX)
{
	this->x = inX;
};

void Vect2D_No_Proxy::setY(const float inY)
{
	this->y = inY;
};

void Vect2D_No_Proxy::set(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

float Vect2D_No_Proxy::getX() const
{
	return this->x;
};

float Vect2D_No_Proxy::getY() const
{
	return this->y;
};

// ---  End of File ---------------
