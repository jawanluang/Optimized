//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "No_RVO.h"

// DO NOT CHANGE THIS FILE

Vect2D_No_RVO::Vect2D_No_RVO()
	: x(3.0f), y(4.0f)
{
};

Vect2D_No_RVO::Vect2D_No_RVO(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

Vect2D_No_RVO::~Vect2D_No_RVO()
{
};

void Vect2D_No_RVO::setX(const float inX)
{
	this->x = inX;
};

void Vect2D_No_RVO::setY(const float inY)
{
	this->y = inY;
};

void Vect2D_No_RVO::set(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

float Vect2D_No_RVO::getX() const
{
	return this->x;
};

float Vect2D_No_RVO::getY() const
{
	return this->y;
};


Vect2D_No_RVO Vect2D_No_RVO::operator + (const Vect2D_No_RVO &tmp) const
{
	Vect2D_No_RVO sum;

	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;

	return (sum);
};

Vect2D_No_RVO Vect2D_No_RVO::operator - (const Vect2D_No_RVO &tmp) const
{
	Vect2D_No_RVO sum;

	sum.x = this->x - tmp.x;
	sum.y = this->y - tmp.y;

	return (sum);
};

Vect2D_No_RVO Vect2D_No_RVO::operator * (const float scale) const
{
	Vect2D_No_RVO tmp;

	tmp.x = this->x * scale;
	tmp.y = this->y * scale;

	return (tmp);
};

// Assume scale != 0.0f
Vect2D_No_RVO Vect2D_No_RVO::operator / (const float scale) const
{
	Vect2D_No_RVO tmp;

	tmp.x = this->x / scale;
	tmp.y = this->y / scale;

	return (tmp);
};

// ---  End of File ---------------
