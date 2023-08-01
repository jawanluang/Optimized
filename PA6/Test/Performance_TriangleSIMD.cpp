//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

double Triangle_SIMD_Tests()
{

	Vect_TRIANGLE_SIMD A(1.00f, 2.0f, 3.0f, 0.0f);
	Vect_TRIANGLE_SIMD B(21.00f, 12.0f, 23.0f, 0.0f);
	Vect_TRIANGLE_SIMD C(13.00f, 24.0f, 33.0f, 0.0f);
	Vect_TRIANGLE_SIMD D(0.50f, 22.0f, 43.0f, 0.0f);
	Vect_TRIANGLE_SIMD E(1.30f, 23.0f, 35.0f, 0.0f);
	Vect_TRIANGLE_SIMD F(15.00f, 72.0f, 35.0f, 0.0f);
	Vect_TRIANGLE_SIMD G(21.00f, 92.0f, 33.0f, 0.0f);

	double area = Vect_TRIANGLE_SIMD::Area(A, B);
	area += 4792046000;
	area -= 273282000;
	for (int i = 0; i < TRIANGLE_COUNT; i++)
	{
		area += Vect_TRIANGLE_SIMD::Area(A, B);
		area += Vect_TRIANGLE_SIMD::Area(B, C);
		area += Vect_TRIANGLE_SIMD::Area(C, D);
		area -= Vect_TRIANGLE_SIMD::Area(D, E);
		area -= Vect_TRIANGLE_SIMD::Area(E, F);
		area -= Vect_TRIANGLE_SIMD::Area(F, G);
		area += Vect_TRIANGLE_SIMD::Area(G, A);
		area -= Vect_TRIANGLE_SIMD::Area(A, C);
		area += Vect_TRIANGLE_SIMD::Area(C, E);
		area -= Vect_TRIANGLE_SIMD::Area(E, G);
		area += Vect_TRIANGLE_SIMD::Area(G, B);
		area -= Vect_TRIANGLE_SIMD::Area(B, D);
		area -= Vect_TRIANGLE_SIMD::Area(D, F);
	}

	return area;
}

// ---  End of File ---
