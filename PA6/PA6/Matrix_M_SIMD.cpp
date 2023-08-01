//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	Matrix_M_SIMD A;
	Vect_M_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->v0.x);
	Y._m = _mm_set1_ps(this->v0.y);
	Z._m = _mm_set1_ps(this->v0.z);
	W._m = _mm_set1_ps(this->v0.w);
	X._m = _mm_mul_ps(X._m, mb.v0._m);
	Y._m = _mm_mul_ps(Y._m, mb.v1._m);
	Z._m = _mm_mul_ps(Z._m, mb.v2._m);
	W._m = _mm_mul_ps(W._m, mb.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(this->v1.x);
	Y._m = _mm_set1_ps(this->v1.y);
	Z._m = _mm_set1_ps(this->v1.z);
	W._m = _mm_set1_ps(this->v1.w);
	X._m = _mm_mul_ps(X._m, mb.v0._m);
	Y._m = _mm_mul_ps(Y._m, mb.v1._m);
	Z._m = _mm_mul_ps(Z._m, mb.v2._m);
	W._m = _mm_mul_ps(W._m, mb.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(this->v2.x);
	Y._m = _mm_set1_ps(this->v2.y);
	Z._m = _mm_set1_ps(this->v2.z);
	W._m = _mm_set1_ps(this->v2.w);
	X._m = _mm_mul_ps(X._m, mb.v0._m);
	Y._m = _mm_mul_ps(Y._m, mb.v1._m);
	Z._m = _mm_mul_ps(Z._m, mb.v2._m);
	W._m = _mm_mul_ps(W._m, mb.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(this->v3.x);
	Y._m = _mm_set1_ps(this->v3.y);
	Z._m = _mm_set1_ps(this->v3.z);
	W._m = _mm_set1_ps(this->v3.w);
	X._m = _mm_mul_ps(X._m, mb.v0._m);
	Y._m = _mm_mul_ps(Y._m, mb.v1._m);
	Z._m = _mm_mul_ps(Z._m, mb.v2._m);
	W._m = _mm_mul_ps(W._m, mb.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	return A;
}


// ---  End of File ---------------
