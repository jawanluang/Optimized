//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}



VmulM::operator Vect_Row_SIMD ()
{
	Vect_Row_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->vector.x);
	Y._m = _mm_set1_ps(this->vector.y);
	Z._m = _mm_set1_ps(this->vector.z);
	W._m = _mm_set1_ps(this->vector.w);
	X._m = _mm_mul_ps(X._m, this->matrix.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->matrix.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->matrix.v2._m);
	W._m = _mm_mul_ps(W._m, this->matrix.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	return Z;
}

VmulM2::operator Vect_Row_SIMD ()
{
	Vect_Row_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->vector.x);
	Y._m = _mm_set1_ps(this->vector.y);
	Z._m = _mm_set1_ps(this->vector.z);
	W._m = _mm_set1_ps(this->vector.w);
	X._m = _mm_mul_ps(X._m, this->M1.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M1.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M1.v2._m);
	W._m = _mm_mul_ps(W._m, this->M1.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m2

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	return W;
}

VmulM3::operator Vect_Row_SIMD ()
{
	Vect_Row_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->vector.x);
	Y._m = _mm_set1_ps(this->vector.y);
	Z._m = _mm_set1_ps(this->vector.z);
	W._m = _mm_set1_ps(this->vector.w);
	X._m = _mm_mul_ps(X._m, this->M1.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M1.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M1.v2._m);
	W._m = _mm_mul_ps(W._m, this->M1.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m2

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m3

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	return W;

}

VmulM4::operator Vect_Row_SIMD ()
{
	Vect_Row_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->vector.x);
	Y._m = _mm_set1_ps(this->vector.y);
	Z._m = _mm_set1_ps(this->vector.z);
	W._m = _mm_set1_ps(this->vector.w);
	X._m = _mm_mul_ps(X._m, this->M1.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M1.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M1.v2._m);
	W._m = _mm_mul_ps(W._m, this->M1.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m2

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m3

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m4

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	return W;

}

VmulM5::operator Vect_Row_SIMD ()
{
	Vect_Row_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->vector.x);
	Y._m = _mm_set1_ps(this->vector.y);
	Z._m = _mm_set1_ps(this->vector.z);
	W._m = _mm_set1_ps(this->vector.w);
	X._m = _mm_mul_ps(X._m, this->M1.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M1.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M1.v2._m);
	W._m = _mm_mul_ps(W._m, this->M1.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m2

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m3

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m4

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	// m5

	X._m = _mm_set1_ps(W.x);
	Y._m = _mm_set1_ps(W.y);
	Z._m = _mm_set1_ps(W.z);
	W._m = _mm_set1_ps(W.w);
	X._m = _mm_mul_ps(X._m, this->M5.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M5.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M5.v2._m);
	W._m = _mm_mul_ps(W._m, this->M5.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	W._m = _mm_add_ps(X._m, Y._m);

	return W;

}

// ---  End of File ---------------


