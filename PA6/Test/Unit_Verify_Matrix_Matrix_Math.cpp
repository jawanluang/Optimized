//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Matrix.h"
#include "Matrix_M_SIMD.h"

int Matrix_matrix_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Matrix_Matrix, TestConfig::ALL)
{
#if Matrix_Matrix

	// ---------------------------------------------------
	// Matrix * Matrix tests
	// ---------------------------------------------------
	{

		Vect4D VA0(-1.0f, -2.0f, -3.0f, -4.0f);
		Vect4D VA1(4.0f, 5.0f, 6.0f, 7.0f);
		Vect4D VA2(1.0f, 2.0f, 3.0f, 4.0f);
		Vect4D VA3(-4.0f, -3.0f, -2.0f, -1.0f);
		Vect4D VB0(-0.1f, -0.2f, -0.3f, -0.4f);
		Vect4D VB1(0.4f, 0.5f, 0.6f, 0.7f);
		Vect4D VB2(0.1f, 0.2f, 0.3f, 0.4f);
		Vect4D VB3(-0.4f, -0.3f, -0.2f, -0.1f);

		CHECK(VA0.x == -1.0f);
		CHECK(VA0.y == -2.0f);
		CHECK(VA0.z == -3.0f);
		CHECK(VA0.w == -4.0f);

		Matrix A(VA0, VA1, VA2, VA3);
		Matrix B(VB0, VB1, VB2, VB3);
		Matrix C;

		C = A * B;

		Vect_M_SIMD VA0_simd(-1.0f, -2.0f, -3.0f, -4.0f);
		Vect_M_SIMD VA1_simd(4.0f, 5.0f, 6.0f, 7.0f);
		Vect_M_SIMD VA2_simd(1.0f, 2.0f, 3.0f, 4.0f);
		Vect_M_SIMD VA3_simd(-4.0f, -3.0f, -2.0f, -1.0f);
		Vect_M_SIMD VB0_simd(-0.1f, -0.2f, -0.3f, -0.4f);
		Vect_M_SIMD VB1_simd(0.4f, 0.5f, 0.6f, 0.7f);
		Vect_M_SIMD VB2_simd(0.1f, 0.2f, 0.3f, 0.4f);
		Vect_M_SIMD VB3_simd(-0.4f, -0.3f, -0.2f, -0.1f);

		Matrix_M_SIMD A_simd(VA0_simd, VA1_simd, VA2_simd, VA3_simd);
		Matrix_M_SIMD B_simd(VB0_simd, VB1_simd, VB2_simd, VB3_simd);
		Matrix_M_SIMD C_simd;

		CHECK(VA0_simd.x == -1.0f);
		CHECK(VA0_simd.y == -2.0f);
		CHECK(VA0_simd.z == -3.0f);
		CHECK(VA0_simd.w == -4.0f);

		C_simd = A_simd * B_simd;

		CHECK(V_EQ(A.v0, A_simd.v0));
		CHECK(V_EQ(A.v1, A_simd.v1));
		CHECK(V_EQ(A.v2, A_simd.v2));
		CHECK(V_EQ(A.v3, A_simd.v3));

		CHECK(V_EQ(B.v0, B_simd.v0));
		CHECK(V_EQ(B.v1, B_simd.v1));
		CHECK(V_EQ(B.v2, B_simd.v2));
		CHECK(V_EQ(B.v3, B_simd.v3));

		CHECK(V_EQ(C.v0, C_simd.v0));
		CHECK(V_EQ(C.v1, C_simd.v1));
		CHECK(V_EQ(C.v2, C_simd.v2));
		CHECK(V_EQ(C.v3, C_simd.v3));

		Matrix_matrix_unit_result = 1;
	}

#endif
} TEST_END

// ---  End of File ---
