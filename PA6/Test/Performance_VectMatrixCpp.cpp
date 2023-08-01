//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

Vect4D vectMultMatrix_test(void)
{
	Vect4D A(0.010f, 0.020f, 00.30f, 0.040f);

	Vect4D VA0(0.556670f, -0.321394f, -0.766044f, 0.000000f);
	Vect4D VA1(0.696747f,  0.682796f,  0.219846f, 0.000000f);
	Vect4D VA2(0.452395f, -0.656121f,  0.604023f, 0.000000f);
	Vect4D VA3(1.000000f,  2.000000f,  3.000000f, 1.000000f);

	Matrix M(VA0, VA1, VA2, VA3);

	Vect4D v1;
	Vect4D v2;

	for (int i = 0; i < VM_COUNT; i++)
	{
		v1 = A * M;
		v2 = v1 * M;
		A = v2 * M;
	}

	return A;
}

// ---  End of File ---------------
