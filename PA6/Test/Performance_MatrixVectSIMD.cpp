//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

Vect_Mv_SIMD matrixMultVect_SIMD_test(void)
{
	Vect_Mv_SIMD A(0.01f, 0.02f, 0.03f, 0.04f);
		
	Vect_Mv_SIMD VA0( 0.556670f, 0.696747f,  0.452395f, 1.000000f);
	Vect_Mv_SIMD VA1(-0.321394f, 0.682796f, -0.656121f, 2.000000f);
	Vect_Mv_SIMD VA2(-0.766044f, 0.219846f,  0.604023f, 3.000000f);
	Vect_Mv_SIMD VA3( 0.000000f, 0.000000f,  0.000000f, 1.000000f);
	
	Matrix_Mv_SIMD M(VA0, VA1, VA2, VA3);
	
	Vect_Mv_SIMD v1;
	Vect_Mv_SIMD v2;

	for (int i = 0; i < MV_COUNT; i++)
	{
		v1 = M * A;
		v2 = M * v1;
		A = M * v2;
	}

	return A;
}

// ---  End of File ---------------
