//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Matrix.h"
#include "Matrix_Col_SIMD.h"

int Col_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Col_Tests, TestConfig::ALL)
{
#if Col_Tests

	// ---------------------------------------------------
	// Col major tests
	// ---------------------------------------------------
	{
		{
			Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, -0.500000f, -0.866025f, 0.000000f),
					  Vect4D(0.000000f, 0.866025f, -0.500000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Ry(Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Rz(Vect4D(0.500000f, 0.866025f, 0.000000f, 0.000000f),
					  Vect4D(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 4.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 5.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 6.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.000000f),
					  Vect4D(0.200000f, 0.300000f, 0.500000f, 0.130000f));

			Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect4D vOut;

			vOut = T * Rz * Ry * Rx * S * v;

			CHECK(S.m0 == 1.0f);

			Vect4D Ans;
			Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}

		{
			Matrix_Col_SIMD Rx(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, -0.500000f, -0.866025f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.866025f, -0.500000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD Ry(Vect_Col_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD Rz(Vect_Col_SIMD(0.500000f, 0.866025f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD  T(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 4.000000f),
							   Vect_Col_SIMD(0.000000f, 1.000000f, 0.000000f, 5.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 1.000000f, 6.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD  S(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 2.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.500000f, 0.000000f),
							   Vect_Col_SIMD(0.200000f, 0.300000f, 0.500000f, 0.130000f));

			Vect_Col_SIMD v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect_Col_SIMD vOut;

			vOut = T * Rz * Ry * Rx * S * v;

			Vect_Col_SIMD Ans;
			Ans = Vect_Col_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));

			Col_unit_result = 1;
		}

	}

#endif
} TEST_END

// ---  End of File ---
