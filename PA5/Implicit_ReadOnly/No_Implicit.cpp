//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "No_Implicit.h"

Vect_No_Protection::Vect_No_Protection()
	: x(0.0f), y(0.0f), z(0.0f)
{
};

Vect_No_Protection::Vect_No_Protection(const Vect_No_Protection &tmp)
	: x(tmp.x), y(tmp.y), z(tmp.z)
{
};

const Vect_No_Protection & Vect_No_Protection::operator = (const Vect_No_Protection &tmp)
{
	this->x = tmp.x;
	this->y = tmp.y;
	this->z = tmp.z;

	return *this;
};

Vect_No_Protection::~Vect_No_Protection()
{
};

Vect_No_Protection::Vect_No_Protection(const float inX, const float inY, const float inZ)
	: x(inX), y(inY), z(inZ)
{
};

void Vect_No_Protection::setX(const float inX)
{
	this->x = inX;
};

void Vect_No_Protection::setY(const float inY)
{
	this->y = inY;
};

void Vect_No_Protection::setZ(const float inZ)
{
	this->z = inZ;
};

void Vect_No_Protection::set(const float inX, const float inY, const float inZ)
{
	this->x = inX;
	this->y = inY;
	this->z = inZ;
};

float Vect_No_Protection::getX() const
{
	return this->x;
};

float Vect_No_Protection::getY() const
{
	return this->y;
};

float Vect_No_Protection::getZ() const
{
	return this->z;
};

Vect_No_Protection Vect_No_Protection::operator + (const Vect_No_Protection tmp) const
{
	return (Vect_No_Protection(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z));
}

// ---  End of File ---------------
