//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration_Implicit_Prevent.h"

#include "Implicit.h"

Vect Implicit_Prevention()
{
	int I_ValueX(2);
	int I_ValueY(3);
	int I_ValueZ(4);

	char C_ValueX(6);
	char C_ValueY(8);
	char C_ValueZ(9);

	double D_ValueX(11/10);
	double D_ValueY(12/10);
	double D_ValueZ(13/10);

	Vect A;

	A.setX(I_ValueX);
	A.setY(I_ValueY);
	A.setZ(I_ValueZ);

	Vect B;

	B.setX(C_ValueX);
	B.setY(C_ValueY);
	B.setZ(C_ValueZ);

	Vect C;

	C.setX(D_ValueX);
	C.setY(D_ValueY);
	C.setZ(D_ValueZ);

	Vect E(D_ValueX, D_ValueY, D_ValueZ);
	Vect F(C_ValueX, C_ValueY, I_ValueZ);
	Vect G(D_ValueX, I_ValueY, I_ValueZ);
	Vect H(C_ValueX, D_ValueY, C_ValueZ);
	Vect I(I_ValueX, D_ValueY, C_ValueX);

	Vect J;

	J.set(D_ValueX, D_ValueY, D_ValueZ);
	J.set(C_ValueX, C_ValueY, I_ValueZ);
	J.set(D_ValueX, I_ValueY, I_ValueZ);
	J.set(C_ValueX, D_ValueY, C_ValueZ);
	J.set(I_ValueX, D_ValueY, C_ValueX);

	Vect M = A + B + C + E + F + G + H + I + J;

	return M;
}


TEST(Implicit_Prevention_check, TestConfig::ALL)
{
#if Implicit_Prevention_check

	Vect A = Implicit_Prevention();

	Trace::out2("\n");
	Trace::out2("  A: %f %f %f\n", A.getX(), A.getY(), A.getZ());
	Trace::out2("\n");
	Trace::out2(" This should never compile \n");
	Trace::out2("    You should prevent compilation due to the implicit conversions \n");
	Trace::out2("    You will be graded based on the Errors generated \n");

#endif
} TEST_END

// ---  End of File ---
