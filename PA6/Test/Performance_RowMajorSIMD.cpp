//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

Vect_Row_SIMD rowMajor_SIMD_test()
{
	Matrix_Row_SIMD Rx(
		Vect_Row_SIMD(1.000000f,  0.000000f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.000000f, -0.500000f,  0.866025f, 0.000000f),
		Vect_Row_SIMD(0.000000f, -0.866025f, -0.500000f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  0.000000f, 1.000000f));

	Matrix_Row_SIMD Ry(
		Vect_Row_SIMD(0.707107f,  0.000000f, -0.707107f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  1.000000f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.707107f,  0.000000f,  0.707107f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  0.000000f, 1.000000f)
	);							  			  
								  			  
	Matrix_Row_SIMD Rz(			  			  
		Vect_Row_SIMD(0.500000f, -0.866025f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.866025f,  0.500000f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  1.000000f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  0.000000f, 1.000000f)
	);							  			  
								  			  
	Matrix_Row_SIMD  T(			  			  
		Vect_Row_SIMD(1.000000f,  0.000000f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  1.000000f,  0.000000f, 0.000000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  1.000000f, 0.000000f),
		Vect_Row_SIMD(4.000000f,  5.000000f,  6.000000f, 1.000000f)
	);							  			  
								  			  
	Matrix_Row_SIMD  S(			  			  
		Vect_Row_SIMD(1.000000f,  0.000000f,  0.000000f, 0.200000f),
		Vect_Row_SIMD(0.000000f,  2.000000f,  0.000000f, 0.300000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  0.500000f, 0.500000f),
		Vect_Row_SIMD(0.000000f,  0.000000f,  0.000000f, 0.130000f)
	);

	Vect_Row_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect_Row_SIMD  vOut;

	for (int i = 0; i < ROW_MAJOR_COUNT; i++)
	{
		vOut = v * S * Rx *Ry * Rz * T;
	}

	return vOut;
}

// ---  End of File ---------------
