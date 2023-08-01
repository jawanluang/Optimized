//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

double Triangle_Tests()
{

	Vect4D A(1.00f, 2.0f, 3.0f, 0.0f);
	Vect4D B(21.00f, 12.0f, 23.0f, 0.0f);
	Vect4D C(13.00f, 24.0f, 33.0f, 0.0f);
	Vect4D D(0.50f, 22.0f, 43.0f, 0.0f);
	Vect4D E(1.30f, 23.0f, 35.0f, 0.0f);
	Vect4D F(15.00f, 72.0f, 35.0f, 0.0f);
	Vect4D G(21.00f, 92.0f, 33.0f, 0.0f);

	double area = Vect4D::Area(A, B);
	area += 4792046000;
	area -= 273282000;
	for (int i = 0; i < TRIANGLE_COUNT; i++)
	{
		area += Vect4D::Area(A, B);
		area += Vect4D::Area(B, C);
		area += Vect4D::Area(C, D);
		area -= Vect4D::Area(D, E);
		area -= Vect4D::Area(E, F);
		area -= Vect4D::Area(F, G);
		area += Vect4D::Area(G, A);
		area -= Vect4D::Area(A, C);
		area += Vect4D::Area(C, E);
		area -= Vect4D::Area(E, G);
		area += Vect4D::Area(G, B);
		area -= Vect4D::Area(B, D);
		area -= Vect4D::Area(D, F);
	}

	return area;
}

// ---  End of File ---
