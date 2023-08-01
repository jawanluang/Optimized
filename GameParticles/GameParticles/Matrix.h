//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"
#include "Vect4d.h"

// forward declare
class Vect4D;

// class
class Matrix
{
public:

	// local enumerations
	enum class MatrixRow
	{
		MATRIX_ROW_0,
		MATRIX_ROW_1,
		MATRIX_ROW_2,
		MATRIX_ROW_3
	};

	Matrix();	
	Matrix( const Matrix& t );	
	Matrix& operator = (const Matrix& r) = default;
	~Matrix();

	Matrix(const Vect4D& tv0, const Vect4D& tv1, const Vect4D& tv2, const Vect4D& tv3);

	void set( MatrixRow row, Vect4D *t );
	Vect4D get(MatrixRow row);

	void setIdentMatrix();
	void setTransMatrix(Vect4D *t );
	void setScaleMatrix(Vect4D *s );
	void setRotZMatrix( float Z_Radians );

	float &operator[]( Index e);

	float Determinant();
	
	Matrix GetAdjugate();
	Matrix& operator/=(float t);
	
	void Inverse( Matrix &out );
	
private:

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
			// ROW 0
			float m0;
			float m1;
			float m2;
			float m3;

			// ROW 1
			float m4;
			float m5;
			float m6;
			float m7;

			// ROW 2
			float m8;
			float m9;
			float m10;
			float m11;

			// ROW 3
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};

	// Add Friends Here
	friend struct MmulM;
	friend struct MmulM2;
	friend struct MmulM3;
	friend struct MmulM4;
};

struct MmulM
{
	const Matrix& M1;
	const Matrix& M2;

	MmulM(const Matrix& m1, const Matrix& m2)
		: M1(m1), M2(m2) {};

	operator Matrix();
};

inline MmulM operator * (const Matrix& m1, const Matrix& m2)
{
	return MmulM(m1, m2);
}

struct MmulM2
{
	const Matrix& M1;
	const Matrix& M2;
	const Matrix& M3;

	MmulM2(const MmulM& m1, const Matrix& m2)
		: M1(m1.M1), M2(m1.M2), M3(m2) {};

	operator Matrix();
};

inline MmulM2 operator * (const MmulM& MM, const Matrix& m2)
{
	return MmulM2(MM, m2);
}

struct MmulM3
{
	const Matrix& M1;
	const Matrix& M2;
	const Matrix& M3;
	const Matrix& M4;

	MmulM3(const MmulM2& m1, const Matrix& m2)
		: M1(m1.M1), M2(m1.M2), M3(m1.M3), M4(m2) {};

	operator Matrix();
};

inline MmulM3 operator * (const MmulM2& MM, const Matrix& m2)
{
	return MmulM3(MM, m2);
}

struct MmulM4
{
	const Matrix& M1;
	const Matrix& M2;
	const Matrix& M3;
	const Matrix& M4;
	const Matrix& M5;

	MmulM4(const MmulM3& m1, const Matrix& m2)
		: M1(m1.M1), M2(m1.M2), M3(m1.M3), M4(m1.M4), M5(m2) {};

	operator Matrix();
};

inline MmulM4 operator * (const MmulM3& MM, const Matrix& m2)
{
	return MmulM4(MM, m2);
}

#endif  

// --- End of File ---
