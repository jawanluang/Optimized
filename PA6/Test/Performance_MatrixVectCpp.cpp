//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

Vect4D matrixMultVect_test(void)
{
	Vect4D A(0.01f, 0.02f, 0.03f, 0.04f);

	Vect4D VA0( 0.556670f, 0.696747f,  0.452395f, 1.000000f);
	Vect4D VA1(-0.321394f, 0.682796f, -0.656121f, 2.000000f);
	Vect4D VA2(-0.766044f, 0.219846f,  0.604023f, 3.000000f);
	Vect4D VA3( 0.000000f, 0.000000f,  0.000000f, 1.000000f);

	Matrix M(VA0, VA1, VA2, VA3);

	Vect4D v1;
	Vect4D v2;

	for (int i = 0; i < MV_COUNT; i++)
	{
		v1 = M * A;
		v2 = M * v1;
		A  = M * v2;
	}

	return A;
}

// ---  End of File ---------------
