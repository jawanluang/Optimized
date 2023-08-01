//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include <Math.h>
#include "Vect4d.h"
#include "Matrix.h"

Matrix::Matrix()
	: v0(Vect4D()), v1(Vect4D()), v2(Vect4D()), v3(Vect4D())
{	
}

Matrix::Matrix(const Vect4D& tv0, const Vect4D& tv1, const Vect4D& tv2, const Vect4D& tv3)
	:v0(tv0), v1(tv1), v2(tv2), v3(tv3)
{
};

Matrix::Matrix(const Matrix& t)
{
	this->v0 = t.v0;
	this->v1 = t.v1;
	this->v2 = t.v2;
	this->v3 = t.v3;
}

Matrix::~Matrix()
{
	
}

void Matrix::setIdentMatrix()
{ 
	this->v0 = Vect4D(1.0f, 0.0f, 0.0f, 0.0f);

	this->v1 = Vect4D(0.0f, 1.0f, 0.0f, 0.0f);

	this->v2 = Vect4D(0.0f, 0.0f, 1.0f, 0.0f);
	
	this->v3 = Vect4D(0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix::setTransMatrix(Vect4D *t)
{ 
	this->v0 = Vect4D(1.0f, 0.0f, 0.0f, 0.0f);

	this->v1 = Vect4D(0.0f, 1.0f, 0.0f, 0.0f);

	this->v2 = Vect4D(0.0f, 0.0f, 1.0f, 0.0f);
	
	this->v3 = Vect4D(t->x, t->y, t->z, 1.0f);
}

void Matrix::set( MatrixRow row, Vect4D *t )
{
	switch( row )
	{
	case MatrixRow::MATRIX_ROW_0:
		this->v0 = *t;
		break;

	case MatrixRow::MATRIX_ROW_1:
		this->v1 = *t;
		break;

	case MatrixRow::MATRIX_ROW_2:
		this->v2 = *t;
		break;

	case MatrixRow::MATRIX_ROW_3:
		this->v3 = *t;
		break;

	default:
		// should never get here, if we are here something bad has happened
		assert(0);
	}
}

float &Matrix::operator[](Index e)
{
	// get the individual elements
	switch(e)
	{
	case Index::m0:
		return m0;
		break;
	case Index::m1:
		return m1;
		break;
	case Index::m2:
		return m2;
		break;
	case Index::m3:
		return m3;
		break;
	case Index::m4:
		return m4;
		break;
	case Index::m5:
		return m5;
		break;
	case Index::m6:
		return m6;
		break;
	case Index::m7:
		return m7;
		break;
	case Index::m8:
		return m8;
		break;
	case Index::m9:
		return m9;
		break;	
	case Index::m10:
		return m10;
		break;
	case Index::m11:
		return m11;
		break;	
	case Index::m12:
		return m12;
		break;	
	case Index::m13:
		return m13;
		break;	
	case Index::m14:
		return m14;
		break;
	case Index::m15:
		return m15;
		break;
	default:
		assert(0);
		return m0;
		break;
	}
}

Vect4D Matrix::get(MatrixRow row)
{ // get a row of the matrix
	switch( row )
	{
	case MatrixRow::MATRIX_ROW_0:
		return v0;
		break;

	case MatrixRow::MATRIX_ROW_1:
		return v1;
		break;

	case MatrixRow::MATRIX_ROW_2:
		return v2;
		break;

	case MatrixRow::MATRIX_ROW_3:
		return v3;
		break;

	default:
		assert(0);
		return Vect4D();
	}
}

MmulM::operator Matrix()
{
	Matrix tmp;

	tmp.m0 = (this->M1.m0 * this->M2.m0) + (this->M1.m1 * this->M2.m4) + (this->M1.m2 * this->M2.m8) + (this->M1.m3 * this->M2.m12);
	tmp.m1 = (this->M1.m0 * this->M2.m1) + (this->M1.m1 * this->M2.m5) + (this->M1.m2 * this->M2.m9) + (this->M1.m3 * this->M2.m13);
	tmp.m2 = (this->M1.m0 * this->M2.m2) + (this->M1.m1 * this->M2.m6) + (this->M1.m2 * this->M2.m10) + (this->M1.m3 * this->M2.m14);
	tmp.m3 = (this->M1.m0 * this->M2.m3) + (this->M1.m1 * this->M2.m7) + (this->M1.m2 * this->M2.m11) + (this->M1.m3 * this->M2.m15);
	
	tmp.m4 = (this->M1.m4 * this->M2.m0) + (this->M1.m5 * this->M2.m4) + (this->M1.m6 * this->M2.m8) + (this->M1.m7 * this->M2.m12);
	tmp.m5 = (this->M1.m4 * this->M2.m1) + (this->M1.m5 * this->M2.m5) + (this->M1.m6 * this->M2.m9) + (this->M1.m7 * this->M2.m13);
	tmp.m6 = (this->M1.m4 * this->M2.m2) + (this->M1.m5 * this->M2.m6) + (this->M1.m6 * this->M2.m10) + (this->M1.m7 * this->M2.m14);
	tmp.m7 = (this->M1.m4 * this->M2.m3) + (this->M1.m5 * this->M2.m7) + (this->M1.m6 * this->M2.m11) + (this->M1.m7 * this->M2.m15);

	tmp.m8 = (this->M1.m8 * this->M2.m0) + (this->M1.m9 * this->M2.m4) + (this->M1.m10 * this->M2.m8) + (this->M1.m11 * this->M2.m12);
	tmp.m9 = (this->M1.m8 * this->M2.m1) + (this->M1.m9 * this->M2.m5) + (this->M1.m10 * this->M2.m9) + (this->M1.m11 * this->M2.m13);
	tmp.m10 = (this->M1.m8 * this->M2.m2) + (this->M1.m9 * this->M2.m6) + (this->M1.m10 * this->M2.m10) + (this->M1.m11 * this->M2.m14);
	tmp.m11 = (this->M1.m8 * this->M2.m3) + (this->M1.m9 * this->M2.m7) + (this->M1.m10 * this->M2.m11) + (this->M1.m11 * this->M2.m15);

	tmp.m12 = (this->M1.m12 * this->M2.m0) + (this->M1.m13 * this->M2.m4) + (this->M1.m14 * this->M2.m8) + (this->M1.m15 * this->M2.m12);
	tmp.m13 = (this->M1.m12 * this->M2.m1) + (this->M1.m13 * this->M2.m5) + (this->M1.m14 * this->M2.m9) + (this->M1.m15 * this->M2.m13);
	tmp.m14 = (this->M1.m12 * this->M2.m2) + (this->M1.m13 * this->M2.m6) + (this->M1.m14 * this->M2.m10) + (this->M1.m15 * this->M2.m14);
	tmp.m15 = (this->M1.m12 * this->M2.m3) + (this->M1.m13 * this->M2.m7) + (this->M1.m14 * this->M2.m11) + (this->M1.m15 * this->M2.m15);

	return tmp;
}

MmulM2::operator Matrix()
{
	Matrix tmp;

	// M1 * M2

	tmp.m0 = (this->M1.m0 * this->M2.m0) + (this->M1.m1 * this->M2.m4) + (this->M1.m2 * this->M2.m8) + (this->M1.m3 * this->M2.m12);
	tmp.m1 = (this->M1.m0 * this->M2.m1) + (this->M1.m1 * this->M2.m5) + (this->M1.m2 * this->M2.m9) + (this->M1.m3 * this->M2.m13);
	tmp.m2 = (this->M1.m0 * this->M2.m2) + (this->M1.m1 * this->M2.m6) + (this->M1.m2 * this->M2.m10) + (this->M1.m3 * this->M2.m14);
	tmp.m3 = (this->M1.m0 * this->M2.m3) + (this->M1.m1 * this->M2.m7) + (this->M1.m2 * this->M2.m11) + (this->M1.m3 * this->M2.m15);

	tmp.m4 = (this->M1.m4 * this->M2.m0) + (this->M1.m5 * this->M2.m4) + (this->M1.m6 * this->M2.m8) + (this->M1.m7 * this->M2.m12);
	tmp.m5 = (this->M1.m4 * this->M2.m1) + (this->M1.m5 * this->M2.m5) + (this->M1.m6 * this->M2.m9) + (this->M1.m7 * this->M2.m13);
	tmp.m6 = (this->M1.m4 * this->M2.m2) + (this->M1.m5 * this->M2.m6) + (this->M1.m6 * this->M2.m10) + (this->M1.m7 * this->M2.m14);
	tmp.m7 = (this->M1.m4 * this->M2.m3) + (this->M1.m5 * this->M2.m7) + (this->M1.m6 * this->M2.m11) + (this->M1.m7 * this->M2.m15);

	tmp.m8 = (this->M1.m8 * this->M2.m0) + (this->M1.m9 * this->M2.m4) + (this->M1.m10 * this->M2.m8) + (this->M1.m11 * this->M2.m12);
	tmp.m9 = (this->M1.m8 * this->M2.m1) + (this->M1.m9 * this->M2.m5) + (this->M1.m10 * this->M2.m9) + (this->M1.m11 * this->M2.m13);
	tmp.m10 = (this->M1.m8 * this->M2.m2) + (this->M1.m9 * this->M2.m6) + (this->M1.m10 * this->M2.m10) + (this->M1.m11 * this->M2.m14);
	tmp.m11 = (this->M1.m8 * this->M2.m3) + (this->M1.m9 * this->M2.m7) + (this->M1.m10 * this->M2.m11) + (this->M1.m11 * this->M2.m15);

	tmp.m12 = (this->M1.m12 * this->M2.m0) + (this->M1.m13 * this->M2.m4) + (this->M1.m14 * this->M2.m8) + (this->M1.m15 * this->M2.m12);
	tmp.m13 = (this->M1.m12 * this->M2.m1) + (this->M1.m13 * this->M2.m5) + (this->M1.m14 * this->M2.m9) + (this->M1.m15 * this->M2.m13);
	tmp.m14 = (this->M1.m12 * this->M2.m2) + (this->M1.m13 * this->M2.m6) + (this->M1.m14 * this->M2.m10) + (this->M1.m15 * this->M2.m14);
	tmp.m15 = (this->M1.m12 * this->M2.m3) + (this->M1.m13 * this->M2.m7) + (this->M1.m14 * this->M2.m11) + (this->M1.m15 * this->M2.m15);

	// M3

	tmp.m0 = (tmp.m0 * this->M3.m0) + (tmp.m1 * this->M3.m4) + (tmp.m2 * this->M3.m8) + (tmp.m3 * this->M3.m12);
	tmp.m1 = (tmp.m0 * this->M3.m1) + (tmp.m1 * this->M3.m5) + (tmp.m2 * this->M3.m9) + (tmp.m3 * this->M3.m13);
	tmp.m2 = (tmp.m0 * this->M3.m2) + (tmp.m1 * this->M3.m6) + (tmp.m2 * this->M3.m10) + (tmp.m3 * this->M3.m14);
	tmp.m3 = (tmp.m0 * this->M3.m3) + (tmp.m1 * this->M3.m7) + (tmp.m2 * this->M3.m11) + (tmp.m3 * this->M3.m15);

	tmp.m4 = (tmp.m4 * this->M3.m0) + (tmp.m5 * this->M3.m4) + (tmp.m6 * this->M3.m8) + (tmp.m7 * this->M3.m12);
	tmp.m5 = (tmp.m4 * this->M3.m1) + (tmp.m5 * this->M3.m5) + (tmp.m6 * this->M3.m9) + (tmp.m7 * this->M3.m13);
	tmp.m6 = (tmp.m4 * this->M3.m2) + (tmp.m5 * this->M3.m6) + (tmp.m6 * this->M3.m10) + (tmp.m7 * this->M3.m14);
	tmp.m7 = (tmp.m4 * this->M3.m3) + (tmp.m5 * this->M3.m7) + (tmp.m6 * this->M3.m11) + (tmp.m7 * this->M3.m15);

	tmp.m8 = (tmp.m8 * this->M3.m0) + (tmp.m9 * this->M3.m4) + (tmp.m10 * this->M3.m8) + (tmp.m11 * this->M3.m12);
	tmp.m9 = (tmp.m8 * this->M3.m1) + (tmp.m9 * this->M3.m5) + (tmp.m10 * this->M3.m9) + (tmp.m11 * this->M3.m13);
	tmp.m10 = (tmp.m8 * this->M3.m2) + (tmp.m9 * this->M3.m6) + (tmp.m10 * this->M3.m10) + (tmp.m11 * this->M3.m14);
	tmp.m11 = (tmp.m8 * this->M3.m3) + (tmp.m9 * this->M3.m7) + (tmp.m10 * this->M3.m11) + (tmp.m11 * this->M3.m15);

	tmp.m12 = (tmp.m12 * this->M3.m0) + (tmp.m13 * this->M3.m4) + (tmp.m14 * this->M3.m8) + (tmp.m15 * this->M3.m12);
	tmp.m13 = (tmp.m12 * this->M3.m1) + (tmp.m13 * this->M3.m5) + (tmp.m14 * this->M3.m9) + (tmp.m15 * this->M3.m13);
	tmp.m14 = (tmp.m12 * this->M3.m2) + (tmp.m13 * this->M3.m6) + (tmp.m14 * this->M3.m10) + (tmp.m15 * this->M3.m14);
	tmp.m15 = (tmp.m12 * this->M3.m3) + (tmp.m13 * this->M3.m7) + (tmp.m14 * this->M3.m11) + (tmp.m15 * this->M3.m15);

	return tmp;
}

MmulM3::operator Matrix()
{
	Matrix tmp, tmp2;

	// M1 * M2

	tmp.m0 = (this->M1.m0 * this->M2.m0) + (this->M1.m1 * this->M2.m4) + (this->M1.m2 * this->M2.m8) + (this->M1.m3 * this->M2.m12);
	tmp.m1 = (this->M1.m0 * this->M2.m1) + (this->M1.m1 * this->M2.m5) + (this->M1.m2 * this->M2.m9) + (this->M1.m3 * this->M2.m13);
	tmp.m2 = (this->M1.m0 * this->M2.m2) + (this->M1.m1 * this->M2.m6) + (this->M1.m2 * this->M2.m10) + (this->M1.m3 * this->M2.m14);
	tmp.m3 = (this->M1.m0 * this->M2.m3) + (this->M1.m1 * this->M2.m7) + (this->M1.m2 * this->M2.m11) + (this->M1.m3 * this->M2.m15);

	tmp.m4 = (this->M1.m4 * this->M2.m0) + (this->M1.m5 * this->M2.m4) + (this->M1.m6 * this->M2.m8) + (this->M1.m7 * this->M2.m12);
	tmp.m5 = (this->M1.m4 * this->M2.m1) + (this->M1.m5 * this->M2.m5) + (this->M1.m6 * this->M2.m9) + (this->M1.m7 * this->M2.m13);
	tmp.m6 = (this->M1.m4 * this->M2.m2) + (this->M1.m5 * this->M2.m6) + (this->M1.m6 * this->M2.m10) + (this->M1.m7 * this->M2.m14);
	tmp.m7 = (this->M1.m4 * this->M2.m3) + (this->M1.m5 * this->M2.m7) + (this->M1.m6 * this->M2.m11) + (this->M1.m7 * this->M2.m15);

	tmp.m8 = (this->M1.m8 * this->M2.m0) + (this->M1.m9 * this->M2.m4) + (this->M1.m10 * this->M2.m8) + (this->M1.m11 * this->M2.m12);
	tmp.m9 = (this->M1.m8 * this->M2.m1) + (this->M1.m9 * this->M2.m5) + (this->M1.m10 * this->M2.m9) + (this->M1.m11 * this->M2.m13);
	tmp.m10 = (this->M1.m8 * this->M2.m2) + (this->M1.m9 * this->M2.m6) + (this->M1.m10 * this->M2.m10) + (this->M1.m11 * this->M2.m14);
	tmp.m11 = (this->M1.m8 * this->M2.m3) + (this->M1.m9 * this->M2.m7) + (this->M1.m10 * this->M2.m11) + (this->M1.m11 * this->M2.m15);

	tmp.m12 = (this->M1.m12 * this->M2.m0) + (this->M1.m13 * this->M2.m4) + (this->M1.m14 * this->M2.m8) + (this->M1.m15 * this->M2.m12);
	tmp.m13 = (this->M1.m12 * this->M2.m1) + (this->M1.m13 * this->M2.m5) + (this->M1.m14 * this->M2.m9) + (this->M1.m15 * this->M2.m13);
	tmp.m14 = (this->M1.m12 * this->M2.m2) + (this->M1.m13 * this->M2.m6) + (this->M1.m14 * this->M2.m10) + (this->M1.m15 * this->M2.m14);
	tmp.m15 = (this->M1.m12 * this->M2.m3) + (this->M1.m13 * this->M2.m7) + (this->M1.m14 * this->M2.m11) + (this->M1.m15 * this->M2.m15);

	// M3

	tmp.m0 = (tmp.m0 * this->M3.m0) + (tmp.m1 * this->M3.m4) + (tmp.m2 * this->M3.m8) + (tmp.m3 * this->M3.m12);
	tmp.m1 = (tmp.m0 * this->M3.m1) + (tmp.m1 * this->M3.m5) + (tmp.m2 * this->M3.m9) + (tmp.m3 * this->M3.m13);
	tmp.m2 = (tmp.m0 * this->M3.m2) + (tmp.m1 * this->M3.m6) + (tmp.m2 * this->M3.m10) + (tmp.m3 * this->M3.m14);
	tmp.m3 = (tmp.m0 * this->M3.m3) + (tmp.m1 * this->M3.m7) + (tmp.m2 * this->M3.m11) + (tmp.m3 * this->M3.m15);

	tmp.m4 = (tmp.m4 * this->M3.m0) + (tmp.m5 * this->M3.m4) + (tmp.m6 * this->M3.m8) + (tmp.m7 * this->M3.m12);
	tmp.m5 = (tmp.m4 * this->M3.m1) + (tmp.m5 * this->M3.m5) + (tmp.m6 * this->M3.m9) + (tmp.m7 * this->M3.m13);
	tmp.m6 = (tmp.m4 * this->M3.m2) + (tmp.m5 * this->M3.m6) + (tmp.m6 * this->M3.m10) + (tmp.m7 * this->M3.m14);
	tmp.m7 = (tmp.m4 * this->M3.m3) + (tmp.m5 * this->M3.m7) + (tmp.m6 * this->M3.m11) + (tmp.m7 * this->M3.m15);

	tmp.m8 = (tmp.m8 * this->M3.m0) + (tmp.m9 * this->M3.m4) + (tmp.m10 * this->M3.m8) + (tmp.m11 * this->M3.m12);
	tmp.m9 = (tmp.m8 * this->M3.m1) + (tmp.m9 * this->M3.m5) + (tmp.m10 * this->M3.m9) + (tmp.m11 * this->M3.m13);
	tmp.m10 = (tmp.m8 * this->M3.m2) + (tmp.m9 * this->M3.m6) + (tmp.m10 * this->M3.m10) + (tmp.m11 * this->M3.m14);
	tmp.m11 = (tmp.m8 * this->M3.m3) + (tmp.m9 * this->M3.m7) + (tmp.m10 * this->M3.m11) + (tmp.m11 * this->M3.m15);

	tmp.m12 = (tmp.m12 * this->M3.m0) + (tmp.m13 * this->M3.m4) + (tmp.m14 * this->M3.m8) + (tmp.m15 * this->M3.m12);
	tmp.m13 = (tmp.m12 * this->M3.m1) + (tmp.m13 * this->M3.m5) + (tmp.m14 * this->M3.m9) + (tmp.m15 * this->M3.m13);
	tmp.m14 = (tmp.m12 * this->M3.m2) + (tmp.m13 * this->M3.m6) + (tmp.m14 * this->M3.m10) + (tmp.m15 * this->M3.m14);
	tmp.m15 = (tmp.m12 * this->M3.m3) + (tmp.m13 * this->M3.m7) + (tmp.m14 * this->M3.m11) + (tmp.m15 * this->M3.m15);

	// M4

	tmp2.m0 = (tmp.m0 * this->M4.m0) + (tmp.m1 * this->M4.m4) + (tmp.m2 * this->M4.m8) + (tmp.m3 * this->M4.m12);
	tmp2.m1 = (tmp.m0 * this->M4.m1) + (tmp.m1 * this->M4.m5) + (tmp.m2 * this->M4.m9) + (tmp.m3 * this->M4.m13);
	tmp2.m2 = (tmp.m0 * this->M4.m2) + (tmp.m1 * this->M4.m6) + (tmp.m2 * this->M4.m10) + (tmp.m3 * this->M4.m14);
	tmp2.m3 = (tmp.m0 * this->M4.m3) + (tmp.m1 * this->M4.m7) + (tmp.m2 * this->M4.m11) + (tmp.m3 * this->M4.m15);
	   
	tmp2.m4 = (tmp.m4 * this->M4.m0) + (tmp.m5 * this->M4.m4) + (tmp.m6 * this->M4.m8) + (tmp.m7 * this->M4.m12);
	tmp2.m5 = (tmp.m4 * this->M4.m1) + (tmp.m5 * this->M4.m5) + (tmp.m6 * this->M4.m9) + (tmp.m7 * this->M4.m13);
	tmp2.m6 = (tmp.m4 * this->M4.m2) + (tmp.m5 * this->M4.m6) + (tmp.m6 * this->M4.m10) + (tmp.m7 * this->M4.m14);
	tmp2.m7 = (tmp.m4 * this->M4.m3) + (tmp.m5 * this->M4.m7) + (tmp.m6 * this->M4.m11) + (tmp.m7 * this->M4.m15);
	   
	tmp2.m8 = (tmp.m8 * this->M4.m0) + (tmp.m9 * this->M4.m4) + (tmp.m10 * this->M4.m8) + (tmp.m11 * this->M4.m12);
	tmp2.m9 = (tmp.m8 * this->M4.m1) + (tmp.m9 * this->M4.m5) + (tmp.m10 * this->M4.m9) + (tmp.m11 * this->M4.m13);
	tmp2.m10 = (tmp.m8 * this->M4.m2) + (tmp.m9 * this->M4.m6) + (tmp.m10 * this->M4.m10) + (tmp.m11 * this->M4.m14);
	tmp2.m11 = (tmp.m8 * this->M4.m3) + (tmp.m9 * this->M4.m7) + (tmp.m10 * this->M4.m11) + (tmp.m11 * this->M4.m15);
	   
	tmp2.m12 = (tmp.m12 * this->M4.m0) + (tmp.m13 * this->M4.m4) + (tmp.m14 * this->M4.m8) + (tmp.m15 * this->M4.m12);
	tmp2.m13 = (tmp.m12 * this->M4.m1) + (tmp.m13 * this->M4.m5) + (tmp.m14 * this->M4.m9) + (tmp.m15 * this->M4.m13);
	tmp2.m14 = (tmp.m12 * this->M4.m2) + (tmp.m13 * this->M4.m6) + (tmp.m14 * this->M4.m10) + (tmp.m15 * this->M4.m14);
	tmp2.m15 = (tmp.m12 * this->M4.m3) + (tmp.m13 * this->M4.m7) + (tmp.m14 * this->M4.m11) + (tmp.m15 * this->M4.m15);

	return tmp2;
}

MmulM4::operator Matrix()
{
	Matrix tmp, tmp2;

	// M1 * M2

	tmp.m0 = (this->M1.m0 * this->M2.m0) + (this->M1.m1 * this->M2.m4) + (this->M1.m2 * this->M2.m8) + (this->M1.m3 * this->M2.m12);
	tmp.m1 = (this->M1.m0 * this->M2.m1) + (this->M1.m1 * this->M2.m5) + (this->M1.m2 * this->M2.m9) + (this->M1.m3 * this->M2.m13);
	tmp.m2 = (this->M1.m0 * this->M2.m2) + (this->M1.m1 * this->M2.m6) + (this->M1.m2 * this->M2.m10) + (this->M1.m3 * this->M2.m14);
	tmp.m3 = (this->M1.m0 * this->M2.m3) + (this->M1.m1 * this->M2.m7) + (this->M1.m2 * this->M2.m11) + (this->M1.m3 * this->M2.m15);

	tmp.m4 = (this->M1.m4 * this->M2.m0) + (this->M1.m5 * this->M2.m4) + (this->M1.m6 * this->M2.m8) + (this->M1.m7 * this->M2.m12);
	tmp.m5 = (this->M1.m4 * this->M2.m1) + (this->M1.m5 * this->M2.m5) + (this->M1.m6 * this->M2.m9) + (this->M1.m7 * this->M2.m13);
	tmp.m6 = (this->M1.m4 * this->M2.m2) + (this->M1.m5 * this->M2.m6) + (this->M1.m6 * this->M2.m10) + (this->M1.m7 * this->M2.m14);
	tmp.m7 = (this->M1.m4 * this->M2.m3) + (this->M1.m5 * this->M2.m7) + (this->M1.m6 * this->M2.m11) + (this->M1.m7 * this->M2.m15);

	tmp.m8 = (this->M1.m8 * this->M2.m0) + (this->M1.m9 * this->M2.m4) + (this->M1.m10 * this->M2.m8) + (this->M1.m11 * this->M2.m12);
	tmp.m9 = (this->M1.m8 * this->M2.m1) + (this->M1.m9 * this->M2.m5) + (this->M1.m10 * this->M2.m9) + (this->M1.m11 * this->M2.m13);
	tmp.m10 = (this->M1.m8 * this->M2.m2) + (this->M1.m9 * this->M2.m6) + (this->M1.m10 * this->M2.m10) + (this->M1.m11 * this->M2.m14);
	tmp.m11 = (this->M1.m8 * this->M2.m3) + (this->M1.m9 * this->M2.m7) + (this->M1.m10 * this->M2.m11) + (this->M1.m11 * this->M2.m15);

	tmp.m12 = (this->M1.m12 * this->M2.m0) + (this->M1.m13 * this->M2.m4) + (this->M1.m14 * this->M2.m8) + (this->M1.m15 * this->M2.m12);
	tmp.m13 = (this->M1.m12 * this->M2.m1) + (this->M1.m13 * this->M2.m5) + (this->M1.m14 * this->M2.m9) + (this->M1.m15 * this->M2.m13);
	tmp.m14 = (this->M1.m12 * this->M2.m2) + (this->M1.m13 * this->M2.m6) + (this->M1.m14 * this->M2.m10) + (this->M1.m15 * this->M2.m14);
	tmp.m15 = (this->M1.m12 * this->M2.m3) + (this->M1.m13 * this->M2.m7) + (this->M1.m14 * this->M2.m11) + (this->M1.m15 * this->M2.m15);

	// M3

	tmp.m0 = (tmp.m0 * this->M3.m0) + (tmp.m1 * this->M3.m4) + (tmp.m2 * this->M3.m8) + (tmp.m3 * this->M3.m12);
	tmp.m1 = (tmp.m0 * this->M3.m1) + (tmp.m1 * this->M3.m5) + (tmp.m2 * this->M3.m9) + (tmp.m3 * this->M3.m13);
	tmp.m2 = (tmp.m0 * this->M3.m2) + (tmp.m1 * this->M3.m6) + (tmp.m2 * this->M3.m10) + (tmp.m3 * this->M3.m14);
	tmp.m3 = (tmp.m0 * this->M3.m3) + (tmp.m1 * this->M3.m7) + (tmp.m2 * this->M3.m11) + (tmp.m3 * this->M3.m15);

	tmp.m4 = (tmp.m4 * this->M3.m0) + (tmp.m5 * this->M3.m4) + (tmp.m6 * this->M3.m8) + (tmp.m7 * this->M3.m12);
	tmp.m5 = (tmp.m4 * this->M3.m1) + (tmp.m5 * this->M3.m5) + (tmp.m6 * this->M3.m9) + (tmp.m7 * this->M3.m13);
	tmp.m6 = (tmp.m4 * this->M3.m2) + (tmp.m5 * this->M3.m6) + (tmp.m6 * this->M3.m10) + (tmp.m7 * this->M3.m14);
	tmp.m7 = (tmp.m4 * this->M3.m3) + (tmp.m5 * this->M3.m7) + (tmp.m6 * this->M3.m11) + (tmp.m7 * this->M3.m15);

	tmp.m8 = (tmp.m8 * this->M3.m0) + (tmp.m9 * this->M3.m4) + (tmp.m10 * this->M3.m8) + (tmp.m11 * this->M3.m12);
	tmp.m9 = (tmp.m8 * this->M3.m1) + (tmp.m9 * this->M3.m5) + (tmp.m10 * this->M3.m9) + (tmp.m11 * this->M3.m13);
	tmp.m10 = (tmp.m8 * this->M3.m2) + (tmp.m9 * this->M3.m6) + (tmp.m10 * this->M3.m10) + (tmp.m11 * this->M3.m14);
	tmp.m11 = (tmp.m8 * this->M3.m3) + (tmp.m9 * this->M3.m7) + (tmp.m10 * this->M3.m11) + (tmp.m11 * this->M3.m15);

	tmp.m12 = (tmp.m12 * this->M3.m0) + (tmp.m13 * this->M3.m4) + (tmp.m14 * this->M3.m8) + (tmp.m15 * this->M3.m12);
	tmp.m13 = (tmp.m12 * this->M3.m1) + (tmp.m13 * this->M3.m5) + (tmp.m14 * this->M3.m9) + (tmp.m15 * this->M3.m13);
	tmp.m14 = (tmp.m12 * this->M3.m2) + (tmp.m13 * this->M3.m6) + (tmp.m14 * this->M3.m10) + (tmp.m15 * this->M3.m14);
	tmp.m15 = (tmp.m12 * this->M3.m3) + (tmp.m13 * this->M3.m7) + (tmp.m14 * this->M3.m11) + (tmp.m15 * this->M3.m15);

	// M4

	tmp2.m0 = (tmp.m0 * this->M4.m0) + (tmp.m1 * this->M4.m4) + (tmp.m2 * this->M4.m8) + (tmp.m3 * this->M4.m12);
	tmp2.m1 = (tmp.m0 * this->M4.m1) + (tmp.m1 * this->M4.m5) + (tmp.m2 * this->M4.m9) + (tmp.m3 * this->M4.m13);
	tmp2.m2 = (tmp.m0 * this->M4.m2) + (tmp.m1 * this->M4.m6) + (tmp.m2 * this->M4.m10) + (tmp.m3 * this->M4.m14);
	tmp2.m3 = (tmp.m0 * this->M4.m3) + (tmp.m1 * this->M4.m7) + (tmp.m2 * this->M4.m11) + (tmp.m3 * this->M4.m15);

	tmp2.m4 = (tmp.m4 * this->M4.m0) + (tmp.m5 * this->M4.m4) + (tmp.m6 * this->M4.m8) + (tmp.m7 * this->M4.m12);
	tmp2.m5 = (tmp.m4 * this->M4.m1) + (tmp.m5 * this->M4.m5) + (tmp.m6 * this->M4.m9) + (tmp.m7 * this->M4.m13);
	tmp2.m6 = (tmp.m4 * this->M4.m2) + (tmp.m5 * this->M4.m6) + (tmp.m6 * this->M4.m10) + (tmp.m7 * this->M4.m14);
	tmp2.m7 = (tmp.m4 * this->M4.m3) + (tmp.m5 * this->M4.m7) + (tmp.m6 * this->M4.m11) + (tmp.m7 * this->M4.m15);

	tmp2.m8 = (tmp.m8 * this->M4.m0) + (tmp.m9 * this->M4.m4) + (tmp.m10 * this->M4.m8) + (tmp.m11 * this->M4.m12);
	tmp2.m9 = (tmp.m8 * this->M4.m1) + (tmp.m9 * this->M4.m5) + (tmp.m10 * this->M4.m9) + (tmp.m11 * this->M4.m13);
	tmp2.m10 = (tmp.m8 * this->M4.m2) + (tmp.m9 * this->M4.m6) + (tmp.m10 * this->M4.m10) + (tmp.m11 * this->M4.m14);
	tmp2.m11 = (tmp.m8 * this->M4.m3) + (tmp.m9 * this->M4.m7) + (tmp.m10 * this->M4.m11) + (tmp.m11 * this->M4.m15);

	tmp2.m12 = (tmp.m12 * this->M4.m0) + (tmp.m13 * this->M4.m4) + (tmp.m14 * this->M4.m8) + (tmp.m15 * this->M4.m12);
	tmp2.m13 = (tmp.m12 * this->M4.m1) + (tmp.m13 * this->M4.m5) + (tmp.m14 * this->M4.m9) + (tmp.m15 * this->M4.m13);
	tmp2.m14 = (tmp.m12 * this->M4.m2) + (tmp.m13 * this->M4.m6) + (tmp.m14 * this->M4.m10) + (tmp.m15 * this->M4.m14);
	tmp2.m15 = (tmp.m12 * this->M4.m3) + (tmp.m13 * this->M4.m7) + (tmp.m14 * this->M4.m11) + (tmp.m15 * this->M4.m15);

	// M5

	tmp.m0 = (tmp2.m0 * this->M5.m0) + (tmp2.m1 * this->M5.m4) + (tmp2.m2 * this->M5.m8) + (tmp2.m3 * this->M5.m12);
	tmp.m1 = (tmp2.m0 * this->M5.m1) + (tmp2.m1 * this->M5.m5) + (tmp2.m2 * this->M5.m9) + (tmp2.m3 * this->M5.m13);
	tmp.m2 = (tmp2.m0 * this->M5.m2) + (tmp2.m1 * this->M5.m6) + (tmp2.m2 * this->M5.m10) + (tmp2.m3 * this->M5.m14);
	tmp.m3 = (tmp2.m0 * this->M5.m3) + (tmp2.m1 * this->M5.m7) + (tmp2.m2 * this->M5.m11) + (tmp2.m3 * this->M5.m15);

	tmp.m4 = (tmp2.m4 * this->M5.m0) + (tmp2.m5 * this->M5.m4) + (tmp2.m6 * this->M5.m8) + (tmp2.m7 * this->M5.m12);
	tmp.m5 = (tmp2.m4 * this->M5.m1) + (tmp2.m5 * this->M5.m5) + (tmp2.m6 * this->M5.m9) + (tmp2.m7 * this->M5.m13);
	tmp.m6 = (tmp2.m4 * this->M5.m2) + (tmp2.m5 * this->M5.m6) + (tmp2.m6 * this->M5.m10) + (tmp2.m7 * this->M5.m14);
	tmp.m7 = (tmp2.m4 * this->M5.m3) + (tmp2.m5 * this->M5.m7) + (tmp2.m6 * this->M5.m11) + (tmp2.m7 * this->M5.m15);

	tmp.m8 = (tmp2.m8 * this->M5.m0) + (tmp2.m9 * this->M5.m4) + (tmp2.m10 * this->M5.m8) + (tmp2.m11 * this->M5.m12);
	tmp.m9 = (tmp2.m8 * this->M5.m1) + (tmp2.m9 * this->M5.m5) + (tmp2.m10 * this->M5.m9) + (tmp2.m11 * this->M5.m13);
	tmp.m10 = (tmp2.m8 * this->M5.m2) + (tmp2.m9 * this->M5.m6) + (tmp2.m10 * this->M5.m10) + (tmp2.m11 * this->M5.m14);
	tmp.m11 = (tmp2.m8 * this->M5.m3) + (tmp2.m9 * this->M5.m7) + (tmp2.m10 * this->M5.m11) + (tmp2.m11 * this->M5.m15);

	tmp.m12 = (tmp2.m12 * this->M5.m0) + (tmp2.m13 * this->M5.m4) + (tmp2.m14 * this->M5.m8) + (tmp2.m15 * this->M5.m12);
	tmp.m13 = (tmp2.m12 * this->M5.m1) + (tmp2.m13 * this->M5.m5) + (tmp2.m14 * this->M5.m9) + (tmp2.m15 * this->M5.m13);
	tmp.m14 = (tmp2.m12 * this->M5.m2) + (tmp2.m13 * this->M5.m6) + (tmp2.m14 * this->M5.m10) + (tmp2.m15 * this->M5.m14);
	tmp.m15 = (tmp2.m12 * this->M5.m3) + (tmp2.m13 * this->M5.m7) + (tmp2.m14 * this->M5.m11) + (tmp2.m15 * this->M5.m15);

	return tmp;
}

Matrix& Matrix::operator/=(float rhs)
{ 
	// possible SIMD transfer
	
	// divide each element by a value
	// using inverse multiply trick, faster that individual divides
	float inv_rhs = 1.0f/rhs;

	m0 *= inv_rhs;
	m1 *= inv_rhs;
	m2 *= inv_rhs;
	m3 *= inv_rhs;
	m4 *= inv_rhs;
	m5 *= inv_rhs;
	m6 *= inv_rhs;
	m7 *= inv_rhs;
	m8 *= inv_rhs;
	m9 *= inv_rhs;
	m10 *= inv_rhs;
	m11 *= inv_rhs;
	m12 *= inv_rhs;
	m13 *= inv_rhs;
	m14 *= inv_rhs;
	m15 *= inv_rhs;

	return *this;
}

float Matrix::Determinant() 
{
	// Possible SIMD operation transfer

	float ta = (m10 * m15) - (m11 * m14);
	// tb = (kq - mo)
	float tb = (m9 * m15) - (m11 * m13);
	// tc = (kp - lo)
	float tc = (m9 * m14) - (m10 * m13);
	// td = (jq - mn)
	float td = (m8 * m15) - (m11 * m12);
	// te = (jo - kn)
	float te = (m8 * m13) - (m9 *  m12);
	// tf = (jp - ln)
	float tf = (m8 * m14) - (m10 * m12);
	
	return ((m0 * ((m5 * ta) - (m6 * tb) + (m7 * tc)))
			- (m1 * ((m4 * ta) - (m6 * td) + (m7 * tf)))
			+ (m2 * ((m4 * tb) - (m5 * td) + (m7 * te)))
			- (m3 * ((m4 * tc) - (m5 * tf) + (m6 * te))));
	
}

Matrix Matrix::GetAdjugate() 
{
	// Possible SIMD operation transfer (Although I don't want to do it)
	
	Matrix tmp;
	
	// load		ABC		(3)		ABC--
	float t1 = (m10*m15) - (m11*m14);
	float t2 = (m9*m15) - (m11*m13);
	float t3 = (m9*m14) - (m10*m13);
	
	// a = f(ta) - g(tb) + h(tc)
	tmp.m0 = (m5*t1) - (m6*t2) + (m7*t3);
	// b = -( b(ta) - c(tb) + d(tc))
	tmp.m1 = -((m1*t1) - (m2*t2) + (m3*t3));
	
	// load		JK		(5)		ABCJK
	float t4 = (m8*m15) - (m11*m12);
	float t5 = (m8*m14) - (m10*m12);
	// e = - ( e(ta) - g(tj) + h(tk))
	tmp.m4 = -( (m4*t1) - (m6*t4) + (m7*t5));
	// f = a(ta) - c(tj) + d(tk)
	tmp.m5 = (m0*t1) - (m2*t4) + (m3*t5);
	
	// unload	AJ		(3)		-BC-K
	// load		P		(4)		PBC-K
	t1 = (m8*m13) - (m9*m12);
	// n = -( e(tc) - f(tk) + g(tp))
	tmp.m12 = -((m4*t3) - (m5*t5) + (m6*t1));
	// o = a(tc) - b(tk) + c(tp)
	tmp.m13 = (m0*t3) - (m1*t5) + (m2*t1);
	
	// unload	KC		(2)		PB---
	// load		J		(3)		PBJ--
	t3 = (m8*m15) - (m11*m12);
	
	// j = e(tb) - f(tj) + h(tp)
	tmp.m8 = (m4*t2) - (m5*t3) + (m7*t1);
	// k = - ( a(tb) - b(tj) + d(tp))
	tmp.m9 = -((m0*t2) - (m1*t3) + (m3*t1));
	
	// unload	BPJ		(0)		-----
	// load		DLM		(3)		DLM--
	t1 = (m6*m15) - (m7*m14);
	t2 = (m4*m15) - (m7*m12);
	t3 = (m4*m14) - (m6*m12);
	
	// g = - ( a(td) - c(tl) + d(tm))
	tmp.m6 = -((m0*t1) - (m2*t2) + (m3*t3));
	
	// load		FR		(5)		DLMFR
	t4 = (m5*m14) - (m6*m13);
	t5 = (m4*m13) - (m5*m12);
	
	// p = - ( a(tf) - b(tm) + c(tr))
	tmp.m14 = -( (m0*t4) - (m1*t3) + (m3*t5));
	
	// unload	M		(4)		DL-FR
	// load		E		(5)		DLEFR
	t3 = (m5*m15) - (m7*m13);
	
	// l = a(te) - b(tl) + d(tr)
	tmp.m10 = (m0*t3) - (m1*t2) + (m3*t5);
	
	// unload	LR		(3)		D-EF-
	// c = b(td) - c(te) + d(tf)
	tmp.m2 = (m1*t1) - (m2*t3) + (m3*t4);
	
	// unload	DEF		(0)		-----
	// load		GHI		(3)		GHI--
	t1 = (m6*m11) - (m7*m10);
	t2 = (m5*m11) - (m7*m9);
	t3 = (m5*m10) - (m6*m9);
	
	// d = -( b(tg) - c(th) + d(ti) )
	tmp.m3 = -( (m1*t1) - (m2*t2) + (m3*t3));
	
	// load		NO		(5)		GHINO
	t4 = (m4*m11) - (m7*m8);
	t5 = (m4*m10) - (m6*m8);
	
	// h = a(tg) - c(tn) + d(to)
	tmp.m7 = (m0*t1) - (m2*t4) + (m3*t5);
	
	// unload	G		(4)		-HINO
	// load		Q		(5)		QHINO
	t1 = (m4*m9) - (m5*m8);
	
	// m = -( a(th) - b(tn) + d(tq))
	tmp.m11 = -((m0*t2) - (m1*t4) + (m3*t1));
	
	// unload	HN		(3)		Q-I-O
	// q = a(ti) - b(to) + c(tq)
	tmp.m15 = (m0*t3) - (m1*t5) + (m2*t1);
	
	return tmp;
}

void Matrix::Inverse( Matrix &out ) 
{
	Matrix tmp;
	float det = Determinant();
	if(fabs(det) < 0.0001f)
	{
		// do nothing, Matrix is not invertable
	}
	else
	{
		tmp = GetAdjugate();
		tmp /= det;
	}

	out = tmp;
}

void Matrix::setScaleMatrix(Vect4D *scale)
{
	//	{	sx		0		0		0	}
	//	{	0		sy		0		0	}
	//	{	0		0		sz		0	}
	//	{	0		0		0		1	}
	
	this->v0 = Vect4D(scale->x, 0.0f, 0.0f, 0.0f);
	
	this->v1 = Vect4D(0.0f, scale->y, 0.0f, 0.0f);
	
	this->v2 = Vect4D(0.0f, 0.0f, scale->z, 0.0f);
	
	this->v3 = Vect4D(0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix::setRotZMatrix(float az)
{
	//	{	cos		-sin	0		0	}
	//	{	sin		cos		0		0	}
	//	{	0		0		1		0	}
	//	{	0		0		0		1	}
	
	this->v0 = Vect4D(cosf(az), -sinf(az), 0.0f, 0.0f);
	
	this->v1 = Vect4D(sinf(az), cosf(az), 0.0f, 0.0f);
	
	this->v2 = Vect4D(0.0f, 0.0f, 1.0f, 0.0f);
	
	this->v3 = Vect4D(0.0f, 0.0f, 0.0f, 1.0f);
}

// --- End of File ---
