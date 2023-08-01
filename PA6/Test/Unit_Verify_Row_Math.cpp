//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Matrix.h"
#include "Matrix_Row_SIMD.h"

int Row_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Row_Tests, TestConfig::ALL)
{
#if Row_Tests

	// ---------------------------------------------------
	// Row major tests
	// ---------------------------------------------------
	{
		{
			Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, -0.500000f, 0.866025f, 0.000000f),
					  Vect4D(0.000000f, -0.866025f, -0.500000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Ry(Vect4D(0.707107f, 0.000000f, -0.707107f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Rz(Vect4D(0.500000f, -0.866025f, 0.000000f, 0.000000f),
					  Vect4D(0.866025f, 0.500000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(4.000000f, 5.000000f, 6.000000f, 1.000000f));

			Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.200000f),
					  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.300000f),
					  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.500000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 0.130000f));

			Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect4D  vOut;

			vOut = v * S * Rx *Ry * Rz * T;

			CHECK(S.m0 == 1.0f);

			Vect4D Ans;
			Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}
		{
			Matrix_Row_SIMD Rx(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, -0.500000f, 0.866025f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, -0.866025f, -0.500000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD Ry(Vect_Row_SIMD(0.707107f, 0.000000f, -0.707107f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD Rz(Vect_Row_SIMD(0.500000f, -0.866025f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.866025f, 0.500000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD  T(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Row_SIMD(4.000000f, 5.000000f, 6.000000f, 1.000000f));

			Matrix_Row_SIMD  S(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.200000f),
							   Vect_Row_SIMD(0.000000f, 2.000000f, 0.000000f, 0.300000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.500000f, 0.500000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 0.130000f));

			Vect_Row_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect_Row_SIMD  vOut;

			vOut = v * S * Rx *Ry * Rz * T;

			Vect_Row_SIMD Ans;
			Ans = Vect_Row_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));

			Row_unit_result = 1;
		}

	}

#endif
} TEST_END

// ---  End of File ---
