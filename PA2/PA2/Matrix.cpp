//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Matrix.h"

// Insert code if desired
Matrix& Matrix::operator=(const Matrix& r)
{
	this->m00 = r.m00;
	this->m01 = r.m01;
	this->m02 = r.m02;
	this->m03 = r.m03;
	this->m10 = r.m10;
	this->m11 = r.m11;
	this->m12 = r.m12;
	this->m13 = r.m13;
	this->m20 = r.m20;
	this->m21 = r.m21;
	this->m22 = r.m22;
	this->m23 = r.m23;
	this->m30 = r.m30;
	this->m31 = r.m31;
	this->m32 = r.m32;
	this->m33 = r.m33;

	return *this;
}

Matrix::~Matrix() 
{
	// do nothing?
}

// ---  End of File ---

