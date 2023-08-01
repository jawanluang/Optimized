//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect4D.h"
#include "Matrix.h"

// ------------------------------
// DO NOT MODIFY 
// ------------------------------

/*****************************************************************************
* LERP - linear interpolation
*
* This function returns a point on a line segment given in parametric form.
* Where the inputs are point a (starting point), point b (ending point) of
* the line segment and the parametric variable t.  If t is in the range of
* ranging from t=0.0 to 1.0, this function returns a point on the line
* segment. If t=0.0 this function returns point a, if t=1.0 this returns
* point b.  Values of t<0.0 return points on the infinite line defined
* before point a. Values of t>1.0 returns points on the infinite line
* defined after point b.
*
* inputs:
*		a - point A
*		b - point B
*		t - parametric t
*
* @return Vector (point) linearly interpolated based on parametric t
*
* Example:
*
*     Vect   v1(1.0f, 2.0f, 3.0f);   // create v1=[1,2,3,1]
*     Vect   v2(-5.0f, 2.0f, 7.0f);  // create v2=[-5,2,7,1]
*     Vect   out;                    // create out vector
*
*     out =	lineParametric (v1, v2, 0.4f );  // t = 0.4f

******************************************************************************/

Vect4D Vect4D::Lerp(const Vect4D &a, const Vect4D &b, const float t)
{
	return  a + (b - a) * t;
}


Vect4D::Vect4D(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

Vect4D Vect4D::operator + (const Vect4D &t) const
{
	return Vect4D(x + t.x, y + t.y, z + t.z, w + t.w);
}

Vect4D Vect4D::operator - (const Vect4D &t) const
{
	return Vect4D(x - t.x, y - t.y, z - t.z, w - t.w);
}

Vect4D Vect4D::operator * (const float s) const
{
	return Vect4D(x * s, y * s, z * s, w * s);
}

Vect4D Vect4D::operator * (const Matrix &m) const
{
	Vect4D C;

	C.x = x * m.m0 + y * m.m4 + z * m.m8 + w * m.m12;
	C.y = x * m.m1 + y * m.m5 + z * m.m9 + w * m.m13;
	C.z = x * m.m2 + y * m.m6 + z * m.m10 + w * m.m14;
	C.w = x * m.m3 + y * m.m7 + z * m.m11 + w * m.m15;

	return C;
};

float Vect4D::Length() const
{
	// ignore the w component for vectors
	float tmp = this->x * this->x + this->y * this->y + this->z * this->z;
	float len = sqrtf(tmp);
	return len;
}


Vect4D Vect4D::Cross(const Vect4D &B) const
{
	// C.x = AyBz - ByAz
	// C.y = AzBx - BzAx
	// C.z = AxBy - BxAy

	return Vect4D(	this->y * B.z - B.y * this->z,
					this->z * B.x - B.z * this->x,
					this->x * B.y - B.x * this->y,
					0.0f 
				 );

}

float Vect4D::Area(const Vect4D &A, const Vect4D &B) 
{
	Vect4D C = A.Cross(B);
	float area = 0.5f * C.Length();
	return area;
}

// ---  End of File ---------------
