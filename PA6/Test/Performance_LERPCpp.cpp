//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

Vect4D LERP_Tests()
{
	Vect4D vOut;
	Vect4D A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D B(21.00f, 12.0f, 23.0f, 40.0f);
	Vect4D C(13.00f, 24.0f, 33.0f, 40.0f);
	Vect4D D(0.50f, 22.0f, 43.0f, 40.0f);
	Vect4D E(1.30f, 23.0f, 35.0f, 40.0f);
	Vect4D F(15.00f, 72.0f, 35.0f, 40.0f);
	Vect4D G(21.00f, 92.0f, 33.0f, 40.0f);

	vOut = Vect4D::Lerp(A, B, 0.65f);

	for (int i = 0; i < LERP_COUNT; i++)
	{
		vOut = Vect4D::Lerp(A, vOut, 0.65f);
		vOut = Vect4D::Lerp(B, vOut, 0.15f);
		vOut = Vect4D::Lerp(C, vOut, 0.25f);
		vOut = Vect4D::Lerp(D, vOut, 0.35f);
		vOut = Vect4D::Lerp(E, vOut, 0.45f);
		vOut = Vect4D::Lerp(F, vOut, 0.55f);
		vOut = Vect4D::Lerp(G, vOut, 0.65f);
		vOut = Vect4D::Lerp(A, vOut, 0.75f);
		vOut = Vect4D::Lerp(A, vOut, 0.85f);
		vOut = Vect4D::Lerp(B, vOut, 0.95f);
		vOut = Vect4D::Lerp(C, vOut, 0.05f);
		vOut = Vect4D::Lerp(D, vOut, 0.15f);
		vOut = Vect4D::Lerp(E, vOut, 0.25f);
		vOut = Vect4D::Lerp(F, vOut, 0.35f);
		vOut = Vect4D::Lerp(G, vOut, 0.45f);
		vOut = Vect4D::Lerp(A, vOut, 0.65f);
		vOut = Vect4D::Lerp(B, vOut, 0.15f);
		vOut = Vect4D::Lerp(C, vOut, 0.25f);
		vOut = Vect4D::Lerp(D, vOut, 0.35f);
		vOut = Vect4D::Lerp(E, vOut, 0.45f);
		vOut = Vect4D::Lerp(F, vOut, 0.55f);
		vOut = Vect4D::Lerp(G, vOut, 0.65f);
		vOut = Vect4D::Lerp(A, vOut, 0.75f);
		vOut = Vect4D::Lerp(A, vOut, 0.85f);
		vOut = Vect4D::Lerp(B, vOut, 0.95f);
		vOut = Vect4D::Lerp(C, vOut, 0.05f);
		vOut = Vect4D::Lerp(D, vOut, 0.15f);
		vOut = Vect4D::Lerp(E, vOut, 0.25f);
		vOut = Vect4D::Lerp(F, vOut, 0.35f);
		vOut = Vect4D::Lerp(G, vOut, 0.45f);
		vOut = Vect4D::Lerp(A, vOut, 0.65f);
		vOut = Vect4D::Lerp(B, vOut, 0.15f);
		vOut = Vect4D::Lerp(C, vOut, 0.25f);
		vOut = Vect4D::Lerp(D, vOut, 0.35f);
		vOut = Vect4D::Lerp(E, vOut, 0.45f);
		vOut = Vect4D::Lerp(F, vOut, 0.55f);
		vOut = Vect4D::Lerp(G, vOut, 0.65f);
		vOut = Vect4D::Lerp(A, vOut, 0.75f);
		vOut = Vect4D::Lerp(A, vOut, 0.85f);
		vOut = Vect4D::Lerp(B, vOut, 0.95f);
		vOut = Vect4D::Lerp(C, vOut, 0.05f);
		vOut = Vect4D::Lerp(D, vOut, 0.15f);
		vOut = Vect4D::Lerp(E, vOut, 0.25f);
		vOut = Vect4D::Lerp(F, vOut, 0.35f);
		vOut = Vect4D::Lerp(G, vOut, 0.45f);
	}

	return vOut;
}

// ---  End of File ---------------
