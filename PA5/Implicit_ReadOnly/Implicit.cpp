//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Implicit.h"

Vect::Vect()
	: x(0.0f), y(0.0f), z(0.0f)
{
};

Vect::Vect(const Vect &tmp)
	: x(tmp.x), y(tmp.y), z(tmp.z)
{
};

const Vect & Vect::operator = (const Vect &tmp)
{
	this->x = tmp.x;
	this->y = tmp.y;
	this->z = tmp.z;

	return *this;
};

Vect::~Vect()
{
};

Vect::Vect(const float inX, const float inY, const float inZ)
	: x(inX), y(inY), z(inZ)
{
};

void Vect::setX(const float inX)
{
	this->x = inX;
};

void Vect::setY(const float inY)
{
	this->y = inY;
};

void Vect::setZ(const float inZ)
{
	this->z = inZ;
};

void Vect::set(const float inX, const float inY, const float inZ)
{
	this->x = inX;
	this->y = inY;
	this->z = inZ;
};

float Vect::getX() const
{
	return this->x;
};

float Vect::getY() const
{
	return this->y;
};

float Vect::getZ() const
{
	return this->z;
};

Vect Vect::operator + (const Vect tmp) const
{
	return (Vect(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z));
}

// ---  End of File ---------------
