//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Matrix.h"

// ------------------------------
// DO NOT MODIFY 
// ------------------------------


Matrix::Matrix(const Vect4D &tv0, const Vect4D &tv1, const Vect4D &tv2, const Vect4D &tv3)
	:v0(tv0), v1(tv1), v2(tv2), v3(tv3)
{
};

Vect4D Matrix::operator * (const Vect4D &v) const
{
	Vect4D vOut;

	vOut.x = m0 * v.x + m1 * v.y + m2 * v.z + m3 * v.w;
	vOut.y = m4 * v.x + m5 * v.y + m6 * v.z + m7 * v.w;
	vOut.z = m8 * v.x + m9 * v.y + m10 * v.z + m11 * v.w;
	vOut.w = m12 * v.x + m13 * v.y + m14 * v.z + m15 * v.w;

	return vOut;
}

Matrix Matrix::operator * (const Matrix &t) const
{
	Matrix A;

	A.m0 = m0 * t.m0 + m1 * t.m4 + m2 * t.m8 + m3 * t.m12;
	A.m1 = m0 * t.m1 + m1 * t.m5 + m2 * t.m9 + m3 * t.m13;
	A.m2 = m0 * t.m2 + m1 * t.m6 + m2 * t.m10 + m3 * t.m14;
	A.m3 = m0 * t.m3 + m1 * t.m7 + m2 * t.m11 + m3 * t.m15;

	A.m4 = m4 * t.m0 + m5 * t.m4 + m6 * t.m8 + m7 * t.m12;
	A.m5 = m4 * t.m1 + m5 * t.m5 + m6 * t.m9 + m7 * t.m13;
	A.m6 = m4 * t.m2 + m5 * t.m6 + m6 * t.m10 + m7 * t.m14;
	A.m7 = m4 * t.m3 + m5 * t.m7 + m6 * t.m11 + m7 * t.m15;

	A.m8 = m8 * t.m0 + m9 * t.m4 + m10 * t.m8 + m11 * t.m12;
	A.m9 = m8 * t.m1 + m9 * t.m5 + m10 * t.m9 + m11 * t.m13;
	A.m10 = m8 * t.m2 + m9 * t.m6 + m10 * t.m10 + m11 * t.m14;
	A.m11 = m8 * t.m3 + m9 * t.m7 + m10 * t.m11 + m11 * t.m15;

	A.m12 = m12 * t.m0 + m13 * t.m4 + m14 * t.m8 + m15 * t.m12;
	A.m13 = m12 * t.m1 + m13 * t.m5 + m14 * t.m9 + m15 * t.m13;
	A.m14 = m12 * t.m2 + m13 * t.m6 + m14 * t.m10 + m15 * t.m14;
	A.m15 = m12 * t.m3 + m13 * t.m7 + m14 * t.m11 + m15 * t.m15;

	return A;
}

// ---  End of File ---------------
