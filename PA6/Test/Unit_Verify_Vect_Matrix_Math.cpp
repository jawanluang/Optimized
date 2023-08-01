//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Matrix.h"
#include "Matrix_vM_SIMD.h"

int Vect_matrix_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Vect_Matrix, TestConfig::ALL)
{
#if Vect_Matrix	

	// ---------------------------------------------------
	// Vect * Matrix tests
	// ---------------------------------------------------
	{

		Vect4D A(1, 2, 3, 4);
		Vect4D B(11, 12, 13, 14);
		Vect4D C(21, 22, 23, 24);

		Vect4D MV0(1, 2, 3, 4);
		Vect4D MV1(5, 6, 7, 8);
		Vect4D MV2(9, 10, 11, 12);
		Vect4D MV3(13, 14, 15, 16);

		Matrix M(MV0, MV1, MV2, MV3);

		Vect4D vout1;
		Vect4D vout2;
		Vect4D vout3;

		vout1 = A * M;
		vout2 = B * M;
		vout3 = C * M;

		Vect_vM_SIMD A_simd;
		A_simd = Vect_vM_SIMD(1, 2, 3, 4);
		Vect_vM_SIMD B_simd;
		B_simd = Vect_vM_SIMD(11, 12, 13, 14);
		Vect_vM_SIMD C_simd;
		C_simd = Vect_vM_SIMD(21, 22, 23, 24);

		Vect_vM_SIMD MV0_simd(1, 2, 3, 4);
		Vect_vM_SIMD MV1_simd(5, 6, 7, 8);
		Vect_vM_SIMD MV2_simd(9, 10, 11, 12);
		Vect_vM_SIMD MV3_simd(13, 14, 15, 16);

		CHECK(M.v0.x == 1.0f);

		Matrix_vM_SIMD M_simd;
		M_simd = Matrix_vM_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

		Vect_vM_SIMD vout1_simd;
		Vect_vM_SIMD vout2_simd;
		Vect_vM_SIMD vout3_simd;

		vout1_simd = A_simd * M_simd;
		vout2_simd = B_simd * M_simd;
		vout3_simd = C_simd * M_simd;

		CHECK(V_EQ(M.v0, M_simd.v0));
		CHECK(V_EQ(M.v1, M_simd.v1));
		CHECK(V_EQ(M.v2, M_simd.v2));
		CHECK(V_EQ(M.v3, M_simd.v3));

		CHECK(V_EQ(A, A_simd));
		CHECK(V_EQ(B, B_simd));
		CHECK(V_EQ(C, C_simd));

		CHECK(V_EQ(vout1, vout1_simd));
		CHECK(V_EQ(vout2, vout2_simd));
		CHECK(V_EQ(vout3, vout3_simd));

		Vect_matrix_unit_result = 1;
	}

#endif
} TEST_END

// ---  End of File ---
