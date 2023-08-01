//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	Vect_vM_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->x);
	Y._m = _mm_set1_ps(this->y);
	Z._m = _mm_set1_ps(this->z);
	W._m = _mm_set1_ps(this->w);
	X._m = _mm_mul_ps(X._m, ma.v0._m);
	Y._m = _mm_mul_ps(Y._m, ma.v1._m);
	Z._m = _mm_mul_ps(Z._m, ma.v2._m);
	W._m = _mm_mul_ps(W._m, ma.v3._m);
	
	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	return Z;
};


// ---  End of File ---------------


