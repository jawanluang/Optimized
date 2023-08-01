///----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef PERFORMANCE_TEST_H
#define PERFORMANCE_TEST_H

#include "Vect4D.h"
#include "Matrix.h"

// --------------------------------------------
// ROW MAJOR 
// --------------------------------------------

	#ifdef _DEBUG
	#define ROW_MAJOR_COUNT 20000000
	#else
	#define ROW_MAJOR_COUNT 150000000
	#endif

	#include "Vect_Row_SIMD.h"
	#include "Matrix_Row_SIMD.h"

	Vect4D rowMajor_test();
	Vect_Row_SIMD rowMajor_SIMD_test();

// --------------------------------------------
// COL MAJOR 
// --------------------------------------------

	#ifdef _DEBUG
	#define COL_MAJOR_COUNT 15000000
	#else
	#define COL_MAJOR_COUNT 150000000
	#endif

	#include "Vect_Col_SIMD.h"
	#include "Matrix_Col_SIMD.h"

	Vect4D colMajor_test();
	Vect_Col_SIMD colMajor_SIMD_test();

// --------------------------------------------
// Vect * Matrix
// --------------------------------------------

	#ifdef _DEBUG
	#define VM_COUNT 40000000
	#else
	#define VM_COUNT 100000000
	#endif

	#include "Vect_vM_SIMD.h"
	#include "Matrix_vM_SIMD.h"

	Vect4D vectMultMatrix_test();
	Vect_vM_SIMD vectMultMatrix_SIMD_test();

// --------------------------------------------
// Matrix * Vect
// --------------------------------------------

	#ifdef _DEBUG
	#define MV_COUNT 40000000
	#else
	#define MV_COUNT 100000000
	#endif

	#include "Vect_Mv_SIMD.h"
	#include "Matrix_Mv_SIMD.h"

	Vect4D matrixMultVect_test();
	Vect_Mv_SIMD matrixMultVect_SIMD_test();

// --------------------------------------------
// Matrix * Matrix
// --------------------------------------------

	#ifdef _DEBUG
	#define MATRIX_COUNT 30000000
	#else
	#define MATRIX_COUNT 200000000
	#endif

	#include "Vect_M_SIMD.h"
	#include "Matrix_M_SIMD.h"

	Matrix matrix_test();
	Matrix_M_SIMD matrix_SIMD_test();

// --------------------------------------------
// LERP
// --------------------------------------------

	#ifdef _DEBUG
	#define LERP_COUNT 2000000
	#else
	#define LERP_COUNT 5000000
	#endif

	#include "Vect_LERP_SIMD.h"

	Vect4D LERP_Tests();
	Vect_LERP_SIMD LERP_SIMD_Tests();

// --------------------------------------------
// Triangle
// --------------------------------------------

	#ifdef _DEBUG
	#define TRIANGLE_COUNT 2000000
	#else
	#define TRIANGLE_COUNT 10000000
	#endif

	#include "Vect_Triangle_SIMD.h"

	double Triangle_Tests();
	double Triangle_SIMD_Tests();

// --------------------------------------------

void PerformanceTest();

#endif

// ---  End of File ---------------
