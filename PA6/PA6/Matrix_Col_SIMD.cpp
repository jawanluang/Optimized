//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

MmulV::operator Vect_Col_SIMD ()
{
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_mul_ps(this->M1.v0._m, this->V._m);
	Y._m = _mm_mul_ps(this->M1.v1._m, this->V._m);
	Z._m = _mm_mul_ps(this->M1.v2._m, this->V._m);
	W._m = _mm_mul_ps(this->M1.v3._m, this->V._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	X._m = _mm_hadd_ps(X._m, Z._m);

	return X;
}

MmulM::operator Matrix_Col_SIMD ()
{
	Matrix_Col_SIMD A;
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->M1.v0.x);
	Y._m = _mm_set1_ps(this->M1.v0.y);
	Z._m = _mm_set1_ps(this->M1.v0.z);
	W._m = _mm_set1_ps(this->M1.v0.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(this->M1.v1.x);
	Y._m = _mm_set1_ps(this->M1.v1.y);
	Z._m = _mm_set1_ps(this->M1.v1.z);
	W._m = _mm_set1_ps(this->M1.v1.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(this->M1.v2.x);
	Y._m = _mm_set1_ps(this->M1.v2.y);
	Z._m = _mm_set1_ps(this->M1.v2.z);
	W._m = _mm_set1_ps(this->M1.v2.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(this->M1.v3.x);
	Y._m = _mm_set1_ps(this->M1.v3.y);
	Z._m = _mm_set1_ps(this->M1.v3.z);
	W._m = _mm_set1_ps(this->M1.v3.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	return A;
}

MmulM2::operator Matrix_Col_SIMD ()
{
	Matrix_Col_SIMD A, B;
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->M1.v0.x);
	Y._m = _mm_set1_ps(this->M1.v0.y);
	Z._m = _mm_set1_ps(this->M1.v0.z);
	W._m = _mm_set1_ps(this->M1.v0.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(this->M1.v1.x);
	Y._m = _mm_set1_ps(this->M1.v1.y);
	Z._m = _mm_set1_ps(this->M1.v1.z);
	W._m = _mm_set1_ps(this->M1.v1.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(this->M1.v2.x);
	Y._m = _mm_set1_ps(this->M1.v2.y);
	Z._m = _mm_set1_ps(this->M1.v2.z);
	W._m = _mm_set1_ps(this->M1.v2.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(this->M1.v3.x);
	Y._m = _mm_set1_ps(this->M1.v3.y);
	Z._m = _mm_set1_ps(this->M1.v3.z);
	W._m = _mm_set1_ps(this->M1.v3.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	// m2

	X._m = _mm_set1_ps(A.v0.x);
	Y._m = _mm_set1_ps(A.v0.y);
	Z._m = _mm_set1_ps(A.v0.z);
	W._m = _mm_set1_ps(A.v0.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v0 = Z;

	X._m = _mm_set1_ps(A.v1.x);
	Y._m = _mm_set1_ps(A.v1.y);
	Z._m = _mm_set1_ps(A.v1.z);
	W._m = _mm_set1_ps(A.v1.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v1 = Z;

	X._m = _mm_set1_ps(A.v2.x);
	Y._m = _mm_set1_ps(A.v2.y);
	Z._m = _mm_set1_ps(A.v2.z);
	W._m = _mm_set1_ps(A.v2.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v2 = Z;

	X._m = _mm_set1_ps(A.v3.x);
	Y._m = _mm_set1_ps(A.v3.y);
	Z._m = _mm_set1_ps(A.v3.z);
	W._m = _mm_set1_ps(A.v3.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v3 = Z;

	return B;

}

MmulM3::operator Matrix_Col_SIMD ()
{
	Matrix_Col_SIMD A, B;
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->M1.v0.x);
	Y._m = _mm_set1_ps(this->M1.v0.y);
	Z._m = _mm_set1_ps(this->M1.v0.z);
	W._m = _mm_set1_ps(this->M1.v0.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(this->M1.v1.x);
	Y._m = _mm_set1_ps(this->M1.v1.y);
	Z._m = _mm_set1_ps(this->M1.v1.z);
	W._m = _mm_set1_ps(this->M1.v1.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(this->M1.v2.x);
	Y._m = _mm_set1_ps(this->M1.v2.y);
	Z._m = _mm_set1_ps(this->M1.v2.z);
	W._m = _mm_set1_ps(this->M1.v2.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(this->M1.v3.x);
	Y._m = _mm_set1_ps(this->M1.v3.y);
	Z._m = _mm_set1_ps(this->M1.v3.z);
	W._m = _mm_set1_ps(this->M1.v3.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	// m2

	X._m = _mm_set1_ps(A.v0.x);
	Y._m = _mm_set1_ps(A.v0.y);
	Z._m = _mm_set1_ps(A.v0.z);
	W._m = _mm_set1_ps(A.v0.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v0 = Z;

	X._m = _mm_set1_ps(A.v1.x);
	Y._m = _mm_set1_ps(A.v1.y);
	Z._m = _mm_set1_ps(A.v1.z);
	W._m = _mm_set1_ps(A.v1.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v1 = Z;

	X._m = _mm_set1_ps(A.v2.x);
	Y._m = _mm_set1_ps(A.v2.y);
	Z._m = _mm_set1_ps(A.v2.z);
	W._m = _mm_set1_ps(A.v2.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v2 = Z;

	X._m = _mm_set1_ps(A.v3.x);
	Y._m = _mm_set1_ps(A.v3.y);
	Z._m = _mm_set1_ps(A.v3.z);
	W._m = _mm_set1_ps(A.v3.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v3 = Z;

	// m3

	X._m = _mm_set1_ps(B.v0.x);
	Y._m = _mm_set1_ps(B.v0.y);
	Z._m = _mm_set1_ps(B.v0.z);
	W._m = _mm_set1_ps(B.v0.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(B.v1.x);
	Y._m = _mm_set1_ps(B.v1.y);
	Z._m = _mm_set1_ps(B.v1.z);
	W._m = _mm_set1_ps(B.v1.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(B.v2.x);
	Y._m = _mm_set1_ps(B.v2.y);
	Z._m = _mm_set1_ps(B.v2.z);
	W._m = _mm_set1_ps(B.v2.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(B.v3.x);
	Y._m = _mm_set1_ps(B.v3.y);
	Z._m = _mm_set1_ps(B.v3.z);
	W._m = _mm_set1_ps(B.v3.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	return A;

}

MmulM4::operator Matrix_Col_SIMD ()
{
	Matrix_Col_SIMD A, B;
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_set1_ps(this->M1.v0.x);
	Y._m = _mm_set1_ps(this->M1.v0.y);
	Z._m = _mm_set1_ps(this->M1.v0.z);
	W._m = _mm_set1_ps(this->M1.v0.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(this->M1.v1.x);
	Y._m = _mm_set1_ps(this->M1.v1.y);
	Z._m = _mm_set1_ps(this->M1.v1.z);
	W._m = _mm_set1_ps(this->M1.v1.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(this->M1.v2.x);
	Y._m = _mm_set1_ps(this->M1.v2.y);
	Z._m = _mm_set1_ps(this->M1.v2.z);
	W._m = _mm_set1_ps(this->M1.v2.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(this->M1.v3.x);
	Y._m = _mm_set1_ps(this->M1.v3.y);
	Z._m = _mm_set1_ps(this->M1.v3.z);
	W._m = _mm_set1_ps(this->M1.v3.w);
	X._m = _mm_mul_ps(X._m, this->M2.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M2.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M2.v2._m);
	W._m = _mm_mul_ps(W._m, this->M2.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	// m2

	X._m = _mm_set1_ps(A.v0.x);
	Y._m = _mm_set1_ps(A.v0.y);
	Z._m = _mm_set1_ps(A.v0.z);
	W._m = _mm_set1_ps(A.v0.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v0 = Z;

	X._m = _mm_set1_ps(A.v1.x);
	Y._m = _mm_set1_ps(A.v1.y);
	Z._m = _mm_set1_ps(A.v1.z);
	W._m = _mm_set1_ps(A.v1.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v1 = Z;

	X._m = _mm_set1_ps(A.v2.x);
	Y._m = _mm_set1_ps(A.v2.y);
	Z._m = _mm_set1_ps(A.v2.z);
	W._m = _mm_set1_ps(A.v2.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v2 = Z;

	X._m = _mm_set1_ps(A.v3.x);
	Y._m = _mm_set1_ps(A.v3.y);
	Z._m = _mm_set1_ps(A.v3.z);
	W._m = _mm_set1_ps(A.v3.w);
	X._m = _mm_mul_ps(X._m, this->M3.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M3.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M3.v2._m);
	W._m = _mm_mul_ps(W._m, this->M3.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v3 = Z;

	// m3

	X._m = _mm_set1_ps(B.v0.x);
	Y._m = _mm_set1_ps(B.v0.y);
	Z._m = _mm_set1_ps(B.v0.z);
	W._m = _mm_set1_ps(B.v0.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v0 = Z;

	X._m = _mm_set1_ps(B.v1.x);
	Y._m = _mm_set1_ps(B.v1.y);
	Z._m = _mm_set1_ps(B.v1.z);
	W._m = _mm_set1_ps(B.v1.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v1 = Z;

	X._m = _mm_set1_ps(B.v2.x);
	Y._m = _mm_set1_ps(B.v2.y);
	Z._m = _mm_set1_ps(B.v2.z);
	W._m = _mm_set1_ps(B.v2.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v2 = Z;

	X._m = _mm_set1_ps(B.v3.x);
	Y._m = _mm_set1_ps(B.v3.y);
	Z._m = _mm_set1_ps(B.v3.z);
	W._m = _mm_set1_ps(B.v3.w);
	X._m = _mm_mul_ps(X._m, this->M4.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M4.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M4.v2._m);
	W._m = _mm_mul_ps(W._m, this->M4.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	A.v3 = Z;

	// m4

	X._m = _mm_set1_ps(A.v0.x);
	Y._m = _mm_set1_ps(A.v0.y);
	Z._m = _mm_set1_ps(A.v0.z);
	W._m = _mm_set1_ps(A.v0.w);
	X._m = _mm_mul_ps(X._m, this->M5.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M5.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M5.v2._m);
	W._m = _mm_mul_ps(W._m, this->M5.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v0 = Z;

	X._m = _mm_set1_ps(A.v1.x);
	Y._m = _mm_set1_ps(A.v1.y);
	Z._m = _mm_set1_ps(A.v1.z);
	W._m = _mm_set1_ps(A.v1.w);
	X._m = _mm_mul_ps(X._m, this->M5.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M5.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M5.v2._m);
	W._m = _mm_mul_ps(W._m, this->M5.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v1 = Z;

	X._m = _mm_set1_ps(A.v2.x);
	Y._m = _mm_set1_ps(A.v2.y);
	Z._m = _mm_set1_ps(A.v2.z);
	W._m = _mm_set1_ps(A.v2.w);
	X._m = _mm_mul_ps(X._m, this->M5.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M5.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M5.v2._m);
	W._m = _mm_mul_ps(W._m, this->M5.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v2 = Z;

	X._m = _mm_set1_ps(A.v3.x);
	Y._m = _mm_set1_ps(A.v3.y);
	Z._m = _mm_set1_ps(A.v3.z);
	W._m = _mm_set1_ps(A.v3.w);
	X._m = _mm_mul_ps(X._m, this->M5.v0._m);
	Y._m = _mm_mul_ps(Y._m, this->M5.v1._m);
	Z._m = _mm_mul_ps(Z._m, this->M5.v2._m);
	W._m = _mm_mul_ps(W._m, this->M5.v3._m);

	X._m = _mm_add_ps(X._m, Z._m);
	Y._m = _mm_add_ps(Y._m, W._m);
	Z._m = _mm_add_ps(X._m, Y._m);

	B.v3 = Z;

	return B;

}

MmulM4mulV::operator Vect_Col_SIMD ()
{
	
	// v
	
	Vect_Col_SIMD X, Y, Z, W;

	X._m = _mm_mul_ps(this->M5.v0._m, this->V._m);
	Y._m = _mm_mul_ps(this->M5.v1._m, this->V._m);
	Z._m = _mm_mul_ps(this->M5.v2._m, this->V._m);
	W._m = _mm_mul_ps(this->M5.v3._m, this->V._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	W._m = _mm_hadd_ps(X._m, Z._m);
	
	// m2

	X._m = _mm_mul_ps(this->M4.v0._m, W._m);
	Y._m = _mm_mul_ps(this->M4.v1._m, W._m);
	Z._m = _mm_mul_ps(this->M4.v2._m, W._m);
	W._m = _mm_mul_ps(this->M4.v3._m, W._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	W._m = _mm_hadd_ps(X._m, Z._m);

	// m3

	X._m = _mm_mul_ps(this->M3.v0._m, W._m);
	Y._m = _mm_mul_ps(this->M3.v1._m, W._m);
	Z._m = _mm_mul_ps(this->M3.v2._m, W._m);
	W._m = _mm_mul_ps(this->M3.v3._m, W._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	W._m = _mm_hadd_ps(X._m, Z._m);

	// m4

	X._m = _mm_mul_ps(this->M2.v0._m, W._m);
	Y._m = _mm_mul_ps(this->M2.v1._m, W._m);
	Z._m = _mm_mul_ps(this->M2.v2._m, W._m);
	W._m = _mm_mul_ps(this->M2.v3._m, W._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	W._m = _mm_hadd_ps(X._m, Z._m);

	// m5

	X._m = _mm_mul_ps(this->M1.v0._m, W._m);
	Y._m = _mm_mul_ps(this->M1.v1._m, W._m);
	Z._m = _mm_mul_ps(this->M1.v2._m, W._m);
	W._m = _mm_mul_ps(this->M1.v3._m, W._m);

	X._m = _mm_hadd_ps(X._m, Y._m);
	Z._m = _mm_hadd_ps(Z._m, W._m);

	W._m = _mm_hadd_ps(X._m, Z._m);

	return W;

}

// ---  End of File ---------------
