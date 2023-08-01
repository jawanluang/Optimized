//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_TRIANGLE_SIMD.h"



Vect_TRIANGLE_SIMD::Vect_TRIANGLE_SIMD(const float tx, const float ty, const float tz, const float tw)
	:x(tx),y(ty),z(tz),w(tw)
{

}

float Vect_TRIANGLE_SIMD::Length() const
{
	Vect_TRIANGLE_SIMD A;

	A._m = _mm_mul_ps(this->_m, this->_m);

	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);

	A._m = _mm_sqrt_ss(A._m);

	return A.x;
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::Cross(const Vect_TRIANGLE_SIMD &R) const
{
	Vect_TRIANGLE_SIMD A;
	Vect_TRIANGLE_SIMD B;
	Vect_TRIANGLE_SIMD C;

	A._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));
	B._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));
	A._m = _mm_mul_ps(A._m, B._m);

	C._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	B._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 1, 0, 2));
	C._m = _mm_mul_ps(C._m, B._m);

	B._m = _mm_sub_ps(A._m, C._m);

	return B;
}

float Vect_TRIANGLE_SIMD::Area(const Vect_TRIANGLE_SIMD &T, const Vect_TRIANGLE_SIMD &R) 
{
	Vect_TRIANGLE_SIMD A;
	Vect_TRIANGLE_SIMD B;
	Vect_TRIANGLE_SIMD C;

	A._m = _mm_shuffle_ps(T._m, T._m, _MM_SHUFFLE(3, 0, 2, 1));
	B._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));
	A._m = _mm_mul_ps(A._m, B._m);

	C._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	B._m = _mm_shuffle_ps(T._m, T._m, _MM_SHUFFLE(3, 1, 0, 2));
	C._m = _mm_mul_ps(C._m, B._m);

	B._m = _mm_sub_ps(A._m, C._m);

	//Len Use B

	B._m = _mm_mul_ps(B._m, B._m);
	
	B._m = _mm_hadd_ps(B._m, B._m);
	B._m = _mm_hadd_ps(B._m, B._m);
	
	B._m = _mm_sqrt_ss(B._m);

	return 0.5f * B.x;
}


// ---  End of File ---

