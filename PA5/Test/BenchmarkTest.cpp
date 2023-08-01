//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration_Benchmark.h"

#include "Bloated.h"
#include "Vect2D.h"

void MemoryTest();
Vect2D MathTest();

#define MEMORY_COUNT 100000
#define MATH_COUNT 20000000

#define eq(a,b) UnitUtility::AreEqual(a,b)

TEST(Benchmark_Timing, TestConfig::ALL)
{
#if Benchmark_Timing
	
	// Create a timer objects
	PerformanceTimer t1;

	// start timer
	t1.Tic();

		Bloated *pBloated = new Bloated();

	// stop timer
	t1.Toc();

	// Create a timer objects
	PerformanceTimer t2;
	
	CHECK(pBloated != nullptr);

	// start timer
	t2.Tic();

		OriginalNode foundNode;
		bool foundFlag = Bloated::findKey(0x30431daa, foundNode);

	// stop timer
	t2.Toc();

	CHECK(foundFlag == true);
	delete pBloated;


	// Create a timer objects
	PerformanceTimer t3;

	// start timer
	t3.Tic();

	for (int i = 0; i < MEMORY_COUNT; i++)
	{
		MemoryTest();
	}

	// stop timer
	t3.Toc();

	// Create a timer objects
	PerformanceTimer t4;
	
	Vect2D A;

	// start timer
	t4.Tic();

	for (int i = 0; i < MATH_COUNT; i++)
	{
		Vect2D B = MathTest();
		A = A + B;
	}

	// stop timer
	t4.Toc();

	CHECK(eq(A.getX(), -33554432.000f));
	CHECK(eq(A.getY(), 134217728.000f));

	// If this fails.. you turned off exceptions... 
	//  Enable C++ exceptions: Yes /EHsc needs to be set
	CHECK(t4.TimeInSeconds() > 0.10f);

	Trace::out2("\n");
	Trace::out2("A: %f %f  \n", A.getX(), A.getY());
	Trace::out2("\n");
	Trace::out2("Benchmarks: \n");
	Trace::out2("    ---Bloated---\n");
	Trace::out2("          Create Bloated: %f s\n", t1.TimeInSeconds());
	double convertMS = 1000.0f*t2.TimeInSeconds();
	Trace::out2("                Find Key: %f ms\n", convertMS);
	Trace::out2("    ---Memory---\n");
	Trace::out2("           Memory Stress: %f s\n", t3.TimeInSeconds());
	Trace::out2("    ---Math----\n");
	Trace::out2("             Math Stress: %f s\n", t4.TimeInSeconds());
	Trace::out2("\n");

#endif
} TEST_END

// ---  End of File ----
