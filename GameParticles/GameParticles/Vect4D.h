//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef Vect4D_H
#define Vect4D_H

// includes
#include "Enum.h"
#include <xmmintrin.h>
#include <smmintrin.h> 

// Foward Declarations
class Matrix;

// class
class Vect4D
{
public:
	friend class Matrix;

	Vect4D();
	Vect4D(const Vect4D& r) = default;
	Vect4D& operator = (const Vect4D& r) = default;
	Vect4D(const float tx, const float ty, const float tz, const float tw = 1.0f);
	~Vect4D();

	void Cross(const Vect4D &vin, Vect4D &vout);
	float &operator[](const Vect e);
	void norm(Vect4D &out);
	void set(float tx, float ty, float tz, float tw = 1.0f);

	Vect4D operator * (const float scale);
	Vect4D operator - (const Vect4D& t);
	Vect4D operator + (const Vect4D& t);

	// Add SIMD inclusion with __m128
private:

	float x; // 4 byte
	float y;
	float z;
	float w;

};

#endif

// --- End of File ---
