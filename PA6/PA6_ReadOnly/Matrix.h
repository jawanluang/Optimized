//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H

#include "Vect4D.h"

// ------------------------------
// DO NOT MODIFY 
// ------------------------------

class Matrix
{
public:

	Matrix() = default;
	Matrix(const Matrix &tmp) = default;
	Matrix &operator=(const Matrix &tmp) = default;
	~Matrix() = default;

	Matrix(const Vect4D &tv0, const Vect4D &tv1, const Vect4D &tv2, const Vect4D &tv3);

	Vect4D operator * (const Vect4D &v) const;
	Matrix operator * (const Matrix &t) const;

	union
	{
		struct
		{
			Vect4D v0;
			Vect4D v1;
			Vect4D v2;
			Vect4D v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

#endif

// ---  End of File ---------------
