//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Vect2D.h"

Vect2D MathTest( void )
{
	float v1 = 2.0f;
	float v2 = 3.0f;
	float v3 = 7.0f;
	float v4 = -5.7f;
	float v5 = 9.0f;	
	float v6 = 4.0f;
	float v7 = 22.23f;
	float v8 = 0.234f;

	Vect2D A;

	Vect2D B;
	B.setX(v1);
	B.setY(v2);

	Vect2D C;
	C.set(v3,v4);

	Vect2D D;
	D.set(v5, v6);

	Vect2D sum;

	sum = A + B + C + D;

	Vect2D ScaledA = B * v7;
    Vect2D ScaledB = C / v8;
	Vect2D DiffVect = ScaledB - ScaledA;

	sum.setX( v1 );
	DiffVect.setX( v7 );

	A = DiffVect + sum;
	B = DiffVect - C;
	D = DiffVect / ScaledA.getY();

	A = B + C;
	A = A * 0.1111f;
	A = A * v4;
	A = A / v5;

	return A;

}

// ---  End of File ---------------
