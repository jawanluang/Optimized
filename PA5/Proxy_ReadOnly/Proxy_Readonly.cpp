//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Proxy.h"

Vect2D::Vect2D(const float inX, const float inY)
	: x(inX), y(inY)
{
}

float Vect2D::getX() const
{
	return this->x;
};

float Vect2D::getY() const
{
	return this->y;
};

void Vect2D::setX(const float inX)
{
	this->x = inX;
};

void Vect2D::setY(const float inY)
{
	this->y = inY;
};

void Vect2D::set(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

// ---  End of File ---------------
