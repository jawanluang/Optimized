//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Vect4D.h"

Vect4D::Vect4D()
	: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vect4D::Vect4D(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

Vect4D::~Vect4D()
{
	// nothing to delete
}

void Vect4D::norm(Vect4D &v)
{
	float mag = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);

	if(0.0f < mag)
	{
		v.x = this->x / mag;
		v.y = this->y / mag;
		v.z = this->z / mag;
		v.w = 1.0f;
	}
}

Vect4D Vect4D::operator + (const Vect4D& t)
{
	//RVO

	return Vect4D(this->x + t.x, this->y + t.y, this->z + t.z, 0.0);
}

float &Vect4D::operator[](const Vect e)
{
	switch(e)
	{
	case Vect::X:
		return x;
		break;
	case Vect::Y:
		return y;
		break;
	case Vect::Z:
		return z;
		break;
	case Vect::W:
		return w;
		break;
	default:
		assert(0);
		return x;
	}
}

Vect4D Vect4D::operator *(const float scale)
{
	// RVO

	return Vect4D(this->x * scale, this->y * scale, this->z * scale, 0.0f);
}

Vect4D Vect4D::operator - (const Vect4D& t)
{
	// RVO for now, maybe change to SIMD later

	return Vect4D(this->x - t.x, this->y - t.y, this->z - t.z, 0.0f);
}

void Vect4D::Cross(const Vect4D &vin, Vect4D &vout)
{
	// Use SIMD
	
	vout.x = (y * vin.z - z * vin.y);
	vout.y = (z * vin.x - x * vin.z);
	vout.z = (x * vin.y - y * vin.x);
	vout.w = 1.0f;
}

void Vect4D::set(float tx, float ty, float tz, float tw)
{
	this->x = tx;
	this->y = ty;
	this->z = tz;
	this->w = tw;
}

// --- End of File ---
