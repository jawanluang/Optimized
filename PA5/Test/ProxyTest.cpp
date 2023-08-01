//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration_Proxy.h"

#include "Proxy.h"
#include "No_Proxy.h"

#if NDEBUG
#define COUNT 70000000
#else
#define COUNT 3000000
#endif

#define eq(a,b) UnitUtility::AreEqual(a,b)

TEST(Proxy_Timing, TestConfig::ALL)
{
#if Proxy_Timing

	// Create a timer objects
	PerformanceTimer t1;

	Vect2D_No_Proxy R;
	R.set(0.0f, 0.0f);

	{
		volatile float v1 = 2.0f;
		volatile float v2 = 3.0f;
		volatile float v3 = 7.0f;
		volatile float v4 = -5.3f;
		volatile float v5 = 9.0f;
		volatile float v6 = 4.0f;
		volatile float v7 = 22.23f;
		volatile float v8 = 0.234f;

		Vect2D_No_Proxy A;
		A.set(0.0f, 0.0f);

		Vect2D_No_Proxy B;
		B.setX(v1);
		B.setY(v2);

		Vect2D_No_Proxy C;
		C.set(v3, v4);

		Vect2D_No_Proxy D;
		D.set(v5, v6);

		Vect2D_No_Proxy E;
		E.set(v3, -v5);

		Vect2D_No_Proxy sum;
		sum.set(0.0f, 0.0f);

		Vect2D_No_Proxy A1;
		A1.set(0.0f, 0.0f);

		Vect2D_No_Proxy B1;
		B1.setX(v4);
		B1.setY(v5);

		Vect2D_No_Proxy C1;
		C1.set(v2, v7);

		Vect2D_No_Proxy D1;
		D1.set(v3, v8);

		Vect2D_No_Proxy E1;
		E1.set(v5, -v2);

		// start timer
		t1.Tic();

		for (int i = 0; i < COUNT; i++)
		{
			sum = A + B + C + D + E + A1 + B1 + C1 + D1 + E1;

			R = R + sum;
		}

		// stop timer
		t1.Toc();

	}

	#ifdef _DEBUG
		CHECK(eq(R.getX(), 118601536.000f));
		CHECK(eq(R.getY(), 62361676.000f));
	#else
		CHECK(eq(R.getX(), 1073741824.000f));
		CHECK(eq(R.getY(), 536870912.000f));
	#endif
	
	// Create a timer objects
	PerformanceTimer t2;

	Vect2D RR;
	RR.set(0.0f, 0.0f);

	{
		volatile float v1 = 2.0f;
		volatile float v2 = 3.0f;
		volatile float v3 = 7.0f;
		volatile float v4 = -5.3f;
		volatile float v5 = 9.0f;
		volatile float v6 = 4.0f;
		volatile float v7 = 22.23f;
		volatile float v8 = 0.234f;

		Vect2D A;
		A.set(0.0f, 0.0f);

		Vect2D B;
		B.setX(v1);
		B.setY(v2);

		Vect2D C;
		C.set(v3, v4);

		Vect2D D;
		D.set(v5, v6);

		Vect2D E;
		E.set(v3, -v5);

		Vect2D sum;
		sum.set(0.0f, 0.0f);

		Vect2D A1;
		A1.set(0.0f, 0.0f);

		Vect2D B1;
		B1.setX(v4);
		B1.setY(v5);

		Vect2D C1;
		C1.set(v2, v7);

		Vect2D D1;
		D1.set(v3, v8);

		Vect2D E1;
		E1.set(v5, -v2);

		// start timer
		t2.Tic();

		for (int i = 0; i < COUNT; i++)
		{
			sum = A + B + C + D + E + A1 + B1 + C1 + D1 + E1;

			RR = RR + sum;
		}

		// stop timer
		t2.Toc();
	}

	#ifdef _DEBUG
		CHECK(eq(RR.getX(), 118601536.000f));
		CHECK(eq(RR.getY(), 62361676.000f));
	#else
		CHECK(eq(RR.getX(), 1073741824.000f));
		CHECK(eq(RR.getY(), 536870912.000f));
	#endif

	Trace::out2("\n");
	Trace::out2(" A: %f %f \n", R.getX(), R.getY());
	Trace::out2("AA: %f %f \n", RR.getX(), RR.getY());
	Trace::out2("\n");
	Trace::out2("   No_Proxy: %f s\n", t1.TimeInSeconds());
	Trace::out2("using_Proxy: %f s\n", t2.TimeInSeconds());
	Trace::out2("      Ratio: %f \n", (t1.TimeInSeconds() / t2.TimeInSeconds()));
	Trace::out2("\n");

#endif
} TEST_END

// ---  End of File ---
