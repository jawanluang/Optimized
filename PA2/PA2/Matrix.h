//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef MATRIX_H
#define MATRIX_H

struct Matrix
{
	Matrix() = default;
	Matrix(const Matrix&) = default;
	Matrix& operator = (const Matrix&);
	~Matrix();

	// You CANNOT add additional data to this class
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
	float m30;
	float m31;
	float m32;
	float m33;
};

#endif

// ---  End of File ---

