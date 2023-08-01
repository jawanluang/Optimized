//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Vect_Row_SIMD_H
#define Vect_Row_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_Row_SIMD;

// -----------------------------------------------------------------------
// Rules: 
//    Implement for Row Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline vM operator * (const Vect_Row_SIMD &v, const Matrix_Row_SIMD &m)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Vect_Row_SIMD
{
public:
	Vect_Row_SIMD() = default;
	Vect_Row_SIMD(const Vect_Row_SIMD &tmp) = default;
	Vect_Row_SIMD &operator = (const Vect_Row_SIMD &tmp) = default;
	~Vect_Row_SIMD() = default;

	Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw);

	// Using Proxy
	// Vect_Row_SIMD operator * ( const Matrix_Row_SIMD &ma);

public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

struct VmulM
{
	const Vect_Row_SIMD& vector;
	const Matrix_Row_SIMD& matrix;

	VmulM(const Vect_Row_SIMD& vector, const Matrix_Row_SIMD& matrix)
		: vector(vector), matrix(matrix) {};

	operator Vect_Row_SIMD ();
};

inline VmulM operator * (const Vect_Row_SIMD& v, const Matrix_Row_SIMD& m)
{
	return VmulM(v, m);
}

struct VmulM2
{
	const Vect_Row_SIMD& vector;
	const Matrix_Row_SIMD& M1;
	const Matrix_Row_SIMD& M2;

	VmulM2(const VmulM& vm, const Matrix_Row_SIMD& m2)
		: vector(vm.vector), M1(vm.matrix), M2(m2) {};

	operator Vect_Row_SIMD ();
};

inline VmulM2 operator * (const VmulM& vm, const Matrix_Row_SIMD& m2)
{
	return VmulM2(vm, m2);
}

struct VmulM3
{
	const Vect_Row_SIMD& vector;
	const Matrix_Row_SIMD& M1;
	const Matrix_Row_SIMD& M2;
	const Matrix_Row_SIMD& M3;

	VmulM3(const VmulM2& vm, const Matrix_Row_SIMD& m)
		: vector(vm.vector), M1(vm.M1), M2(vm.M2), M3(m) {};

	operator Vect_Row_SIMD ();
};

inline VmulM3 operator * (const VmulM2& vm, const Matrix_Row_SIMD& m)
{
	return VmulM3(vm, m);
}

struct VmulM4
{
	const Vect_Row_SIMD& vector;
	const Matrix_Row_SIMD& M1;
	const Matrix_Row_SIMD& M2;
	const Matrix_Row_SIMD& M3;
	const Matrix_Row_SIMD& M4;

	VmulM4(const VmulM3& vm, const Matrix_Row_SIMD& m)
		: vector(vm.vector), M1(vm.M1), M2(vm.M2), M3(vm.M3), M4(m) {};

	operator Vect_Row_SIMD ();
};

inline VmulM4 operator * (const VmulM3& vm, const Matrix_Row_SIMD& m)
{
	return VmulM4(vm, m);
}

struct VmulM5
{
	const Vect_Row_SIMD& vector;
	const Matrix_Row_SIMD& M1;
	const Matrix_Row_SIMD& M2;
	const Matrix_Row_SIMD& M3;
	const Matrix_Row_SIMD& M4;
	const Matrix_Row_SIMD& M5;

	VmulM5(const VmulM4& vm, const Matrix_Row_SIMD& m)
		: vector(vm.vector), M1(vm.M1), M2(vm.M2), M3(vm.M3), M4(vm.M4), M5(m) {};

	operator Vect_Row_SIMD ();
};

inline VmulM5 operator * (const VmulM4& vm, const Matrix_Row_SIMD& m)
{
	return VmulM5(vm, m);
}

#endif

// ---  End of File ---------------
