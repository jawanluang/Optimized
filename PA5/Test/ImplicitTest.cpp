//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration_Implicit_Timing.h"

#include "No_Implicit.h"
#include "Implicit.h"

#if NDEBUG
	#define COUNT 9999999
#else
	#define COUNT 2433333
#endif

#define eq(a,b) UnitUtility::AreEqual(a,b)

Vect  Implicit_No_Conversion()
{
	volatile float I_ValueX(2.0f);
	volatile float I_ValueY(3.0f);
	volatile float I_ValueZ(4.0f);
	volatile float C_ValueX(6.0f);
	volatile float C_ValueY(8.0f);
	volatile float C_ValueZ(9.0f);
	volatile float D_ValueX(11.0f/10.0f);
	volatile float D_ValueY(12.0f/10.0f);
	volatile float D_ValueZ(13.0f/10.0f);

	Vect A;

	A.setX(I_ValueX);
	A.setY(I_ValueY);
	A.setZ(I_ValueZ);

	Vect B(D_ValueX, I_ValueY, D_ValueZ);

	Vect C(C_ValueX, C_ValueY, C_ValueZ);

	C = A + B;

	Vect D(C);

	D.setX(D_ValueZ);

	C.setZ(I_ValueX);

	Vect E = A + B;

	A.set(I_ValueX, D_ValueY, C_ValueX);

	B = A + B + C + D;
	C = B + E;

	E.setZ(I_ValueX);

	Vect F;

	F.setX(C_ValueY);

	Vect G(F.getX(), A.getY(), B.getZ());
	Vect H;
	H.set(C.getZ(), C_ValueZ, F.getX());

	Vect I;
	I.set(D_ValueX, D_ValueY, D_ValueZ);
	I = G + H + F + E + C;

	return I;
}

Vect_No_Protection Implicit_With_Conversion()
{
// Disable warning message (simulating bad users)
#pragma warning( push )
#pragma warning( disable : 4244 )

	volatile int I_ValueX(2.0f);
	volatile int I_ValueY(3.0f);
	volatile int I_ValueZ(4.0f);
	volatile char C_ValueX(6.0f);
	volatile char C_ValueY(8.0f);
	volatile char C_ValueZ(9.0f);
	volatile double D_ValueX(11.0f/10.0f);
	volatile double D_ValueY(12.0f/10.0f);
	volatile double D_ValueZ(13.0f/10.0f);

	// Disable warning message (simulating bad users)
	#pragma warning( disable : 4244 )

	Vect_No_Protection A;

	A.setX(I_ValueX);
	A.setY(I_ValueY);
	A.setZ(I_ValueZ);

	Vect_No_Protection B(D_ValueX, I_ValueY, D_ValueZ);

	Vect_No_Protection C(C_ValueX, C_ValueY, C_ValueZ);

	C = A + B;

	Vect_No_Protection D(C);

	D.setX(D_ValueZ);

	C.setZ(I_ValueX);

	Vect_No_Protection E = A + B;

	A.set(I_ValueX, D_ValueY, C_ValueX);

	B = A + B + C + D;
	C = B + E;

	E.setZ(I_ValueX);

	Vect_No_Protection F;

	F.setX(C_ValueY);

	Vect_No_Protection G(F.getX(), A.getY(), B.getZ());
	Vect_No_Protection H;
	H.set(C.getZ(), C_ValueZ, F.getX());

	Vect_No_Protection I;
	I.set(D_ValueX, D_ValueY, D_ValueZ);
	I = G + H + F + E + C;

#pragma warning( pop ) 
	return I;

}


TEST(Implicit_Timing, TestConfig::ALL)
{
#if Implicit_Timing

	// Create a timer objects
	PerformanceTimer t2;

	Vect_No_Protection AA;

	// start timer
	t2.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect_No_Protection BB = Implicit_With_Conversion();
		AA = AA + BB;
	}

	// stop timer
	t2.Toc();


#ifdef _DEBUG
	CHECK(eq(AA.getX(), 118065640.000f));
	CHECK(eq(AA.getY(),  95675296.000f));
	CHECK(eq(AA.getZ(), 110802000.000f));
#else
	CHECK(eq(AA.getX(), 552208960.000f));
	CHECK(eq(AA.getY(), 345517088.000f));
	CHECK(eq(AA.getZ(), 405479808.000f));
#endif

	// Create a timer objects
	PerformanceTimer t1;

	Vect A;

	// start timer
	t1.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect B = Implicit_No_Conversion();
		A = A + B;
	}

	// stop timer
	t1.Toc();

#ifdef _DEBUG
	CHECK(eq(A.getX(), 118065640.000f));
	CHECK(eq(A.getY(), 95675296.000f));
	CHECK(eq(A.getZ(), 110802000.000f));
#else		  
	CHECK(eq(A.getX(), 552208960.000f));
	CHECK(eq(A.getY(), 345517088.000f));
	CHECK(eq(A.getZ(), 405479808.000f));
#endif

	Trace::out2("\n");
	Trace::out2("  A: %f %f %f\n", A.getX(), A.getY(), A.getZ());
	Trace::out2(" AA: %f %f %f\n", AA.getX(), AA.getY(), AA.getZ());
	Trace::out2("\n");
	Trace::out2("Implicit_With_Conversion: %f s  (should be slower)\n", t2.TimeInSeconds());
	Trace::out2("  Implicit_No_Conversion: %f s\n", t1.TimeInSeconds());
	Trace::out2("                   Ratio: %f    (faster than implict conversion)\n", (t2.TimeInSeconds() / t1.TimeInSeconds()));
	Trace::out2("\n");

#endif
} TEST_END


// ---  End of File ---
