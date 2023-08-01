//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "PerformanceTest.h"

#ifdef _DEBUG
#define FACTOR 1
#else
#define FACTOR 10
#endif

extern int Col_unit_result;
extern int Row_unit_result;
extern int Matrix_matrix_unit_result;
extern int Vect_matrix_unit_result;
extern int Matrix_vect_unit_result;
extern int Lerp_unit_result;
extern int Triangle_unit_result;

void PerformanceTest()
{
	// Performance tests
	Trace::out2("\nPerformance tests: \n    Begin()\n");

	int sum_unit_tests = Col_unit_result + Row_unit_result + Matrix_matrix_unit_result
		+ Vect_matrix_unit_result + Matrix_vect_unit_result + Lerp_unit_result + Triangle_unit_result;

	if ( sum_unit_tests < 1 )
	{
		Trace::out2("\n  ERROR---> didn't pass unit tests\n");
		Trace::out2("\n    Cannot run performance tests\n\n\n");
	}
	else
	{
		float tB_time = 999999.0f;

		//Trace::out2("\n");
		PerformanceTimer tA;
		PerformanceTimer tB;

		// --------------- MATRIX ----------------------------------------------

		Trace::out2("\n---------- Matrix ----------------\n");
		printf("           : Matrix\n");
		tA.Tic();

			Matrix B = matrix_test();

		tA.Toc();

		// --------------- Matrix SIMD ----------------------------------------------

		printf("           : Matrix_SIMD\n");
		tB.Tic();

			Matrix_M_SIMD B_SIMD = matrix_SIMD_test();

		tB.Toc();

		Trace::out2("         Matrix Orig: %2.5f s    :%f %f %f %f\n", tA.TimeInSeconds(), B.v0.x, B.v0.y, B.v0.z, B.v0.w);
		Trace::out2("                                   :%f %f %f %f\n", B.v1.x, B.v1.y, B.v1.z, B.v1.w);
		Trace::out2("                                   :%f %f %f %f\n", B.v2.x, B.v2.y, B.v2.z, B.v2.w);
		Trace::out2("                                   :%f %f %f %f\n", B.v3.x, B.v3.y, B.v3.z, B.v3.w);

		Trace::out2("                SIMD: %2.5f s    :%f %f %f %f\n", tB.TimeInSeconds(), B_SIMD.v0.x, B_SIMD.v0.y, B_SIMD.v0.z, B_SIMD.v0.w);
		Trace::out2("                                   :%f %f %f %f\n", B_SIMD.v1.x, B_SIMD.v1.y, B_SIMD.v1.z, B_SIMD.v1.w);
		Trace::out2("                                   :%f %f %f %f\n", B_SIMD.v2.x, B_SIMD.v2.y, B_SIMD.v2.z, B_SIMD.v2.w);
		Trace::out2("                                   :%f %f %f %f\n", B_SIMD.v3.x, B_SIMD.v3.y, B_SIMD.v3.z, B_SIMD.v3.w);

#if Matrix_Matrix
		if (Matrix_matrix_unit_result)
		{
			Trace::out2("         Matrix SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("         Matrix SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("         Matrix SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// --------------- Vect * Matrix ----------------------------------------------

		Trace::out2("\n---------- Vect * Matrix ----------------\n");
		printf("           : Vect * Matrix\n");
		tA.Tic();

			Vect4D C = vectMultMatrix_test();
	
		tA.Toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		printf("           : Vect * Matrix (SIMD)\n");
		tB.Tic();

			Vect_vM_SIMD C_SIMD = vectMultMatrix_SIMD_test();

		tB.Toc();

		Trace::out2("  Vect * Matrix Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), C.x, C.y, C.z, C.w);
		Trace::out2("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), C_SIMD.x, C_SIMD.y, C_SIMD.z, C_SIMD.w);

#if Vect_Matrix	
		if (Vect_matrix_unit_result)
		{
			Trace::out2("             vM SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("             vM SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("             vM SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// --------------- Matrix * Vector ----------------------------------------------

		Trace::out2("\n---------- Matrix * Vect ----------------\n");
		printf("           : Matrix * Vect\n");
		tA.Tic();

			Vect4D D = matrixMultVect_test();
		
		tA.Toc();

		// --------------- Matrix * Vector (SIMD) ----------------------------------------------

		printf("           : Matrix * Vect (SIMD)\n");
		tB.Tic();

			Vect_Mv_SIMD D_SIMD = matrixMultVect_SIMD_test();
		
		tB.Toc();
		Trace::out2("  Matrix * Vect Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), D.x, D.y, D.z, D.w);
		Trace::out2("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), D_SIMD.x, D_SIMD.y, D_SIMD.z, D_SIMD.w);

#if Matrix_Vect
		if (Matrix_vect_unit_result)
		{
			Trace::out2("             Mv SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("             Mv SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("             Mv SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// --------------- LERP ----------------------------------------------

		Trace::out2("\n---------- LERP ----------------\n");
		printf("           : LERP\n");
		Vect4D LERP_C;
		tA.Tic();

			LERP_C = LERP_Tests();
		
		tA.Toc();

		// --------------- LERP SIMD ----------------------------------------------

		printf("           : LERP SIMD\n");
		Vect_LERP_SIMD LERP_SIMD_C;
		tB.Tic();

			LERP_SIMD_C = LERP_SIMD_Tests();

		tB.Toc();

		Trace::out2("           LERP Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), LERP_C.x, LERP_C.y, LERP_C.z, LERP_C.w);
		Trace::out2("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), LERP_SIMD_C.x, LERP_SIMD_C.y, LERP_SIMD_C.z, LERP_SIMD_C.w);

#if Lerp_Tests
		if (Lerp_unit_result)
		{
			Trace::out2("           LERP SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("           LERP SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("           LERP SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}



		// --------------- TRIANGLE ----------------------------------------------

		Trace::out2("\n---------- TRIANGLE ----------------\n");
		printf("           : TRIANGLE\n");
		double TriangleArea;
		tA.Tic();

		TriangleArea = Triangle_Tests();

		tA.Toc();

		// --------------- TRIANGLE SIMD ----------------------------------------------

		printf("           : TRIANGLE SIMD\n");
		double TriangleAreaSIMD;
		tB.Tic();

		TriangleAreaSIMD = Triangle_SIMD_Tests();

		tB.Toc();

		Trace::out2("       Triangle Orig: %f s   :%f \n", tA.TimeInSeconds(), TriangleArea);
		Trace::out2("                SIMD: %f s   :%f \n", tB.TimeInSeconds(), TriangleAreaSIMD);

#if Triangle
		if (Triangle_unit_result)
		{
			Trace::out2("       Triangle SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("       Triangle SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("       Triangle SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// --------------- RowMajor ----------------------------------------------

		Trace::out2("\n---------- rowMajor ----------------\n");
		printf("           : rowMajor\n");
		Vect4D Row_C;
		tA.Tic();

			Row_C = rowMajor_test();
		
		tA.Toc();

		// --------------- RowMajor SIMD ----------------------------------------------

		printf("           : rowMajor SIMD\n");
		Vect_Row_SIMD Row_SIMD_C;
		tB.Tic();

			Row_SIMD_C = rowMajor_SIMD_test();
	
		tB.Toc();

		Trace::out2("       rowMajor Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), Row_C.x, Row_C.y, Row_C.z, Row_C.w);
		Trace::out2("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), Row_SIMD_C.x, Row_SIMD_C.y, Row_SIMD_C.z, Row_SIMD_C.w);

#if Row_Tests
		if (Row_unit_result)
		{
			Trace::out2("       rowMajor SIMD: %f s ---> Unit Test Passed \n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("       rowMajor SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}

#else
		tB_time = 999999.0f;
		Trace::out2("       rowMajor SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if( tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// --------------- ColMajor ----------------------------------------------

		Trace::out2("\n---------- colMajor ----------------\n");
		printf("           : colMajor\n");
		Vect4D Col_C;
		tA.Tic();

			Col_C = colMajor_test();
		
		tA.Toc();

		// --------------- colMajor SIMD ----------------------------------------------

		printf("           : colMajor SIMD\n");
		Vect_Col_SIMD Col_SIMD_C;
		tB.Tic();

			Col_SIMD_C = colMajor_SIMD_test();
		
		tB.Toc();

		Trace::out2("       colMajor Orig: %f s    :%f %f %f %f\n", tA.TimeInSeconds(), Col_C.x, Col_C.y, Col_C.z, Col_C.w);
		Trace::out2("                SIMD: %f s    :%f %f %f %f\n", tB.TimeInSeconds(), Col_SIMD_C.x, Col_SIMD_C.y, Col_SIMD_C.z, Col_SIMD_C.w);

#if Col_Tests
		if (Col_unit_result)
		{
			Trace::out2("       colMajor SIMD: %f s ---> Unit Test Passed\n", tB.TimeInSeconds());
			tB_time = tB.TimeInSeconds();
		}
		else
		{
			tB_time = 999999.0f;
			Trace::out2("       colMajor SIMD: %2.1f s ---> Unit Test Failed\n", tB_time);
		}
#else
		tB_time = 999999.0f;
		Trace::out2("       colMajor SIMD: %2.1f s ---> NOT ENABLED\n", tB_time);
#endif
		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out2("\n");
			Trace::out2("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out2("               Ratio: %f\n", tA.TimeInSeconds() / tB_time);
		}

		// Tests done
		Trace::out2("\nPerformance tests: done() \n\n");
		printf("\n    done() \n\n");

	}
}

// ---  End of File ---------------
