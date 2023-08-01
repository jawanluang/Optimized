//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"
   
// -----------------------------------------------------------------------
// Rules: 
//    Implement for Col Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline MM operator * (const Matrix_Col_SIMD &m, const Matrix_Col_SIMD &n)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
					const Vect_Col_SIMD &tV1,
					const Vect_Col_SIMD &tV2,
					const Vect_Col_SIMD &tV3);
 
	// Using Proxy
	// Matrix_Col_SIMD operator * (const Matrix_Col_SIMD &n);
	// Vect_Col_SIMD operator * (const Vect_Col_SIMD &n);

	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
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

struct MmulV
{
	const Matrix_Col_SIMD& M1;
	const Vect_Col_SIMD& V;

	MmulV(const Matrix_Col_SIMD& m1, Vect_Col_SIMD& v)
		: M1(m1), V(v) {};

	operator Vect_Col_SIMD ();
};

inline MmulV operator * (const Matrix_Col_SIMD& m1, Vect_Col_SIMD& v)
{
	return MmulV(m1, v);
}

struct MmulM
{
	const Matrix_Col_SIMD& M1;
	const Matrix_Col_SIMD& M2;

	MmulM(const Matrix_Col_SIMD& m1, Matrix_Col_SIMD& m2)
		: M1(m1), M2(m2) {};

	operator Matrix_Col_SIMD ();
};

inline MmulM operator * (const Matrix_Col_SIMD& m1, Matrix_Col_SIMD& m2)
{
	return MmulM(m1, m2);
}

struct MmulM2
{
	const Matrix_Col_SIMD& M1;
	const Matrix_Col_SIMD& M2;
	const Matrix_Col_SIMD& M3;

	MmulM2(const MmulM& MM, Matrix_Col_SIMD& m)
		: M1(MM.M1), M2(MM.M2), M3(m) {};

	operator Matrix_Col_SIMD ();
};

inline MmulM2 operator * (const MmulM& MM, Matrix_Col_SIMD& m)
{
	return MmulM2(MM, m);
}

struct MmulM3
{
	const Matrix_Col_SIMD& M1;
	const Matrix_Col_SIMD& M2;
	const Matrix_Col_SIMD& M3;
	const Matrix_Col_SIMD& M4;

	MmulM3(const MmulM2& MM, Matrix_Col_SIMD& m)
		: M1(MM.M1), M2(MM.M2), M3(MM.M3), M4(m) {};

	operator Matrix_Col_SIMD ();
};

inline MmulM3 operator * (const MmulM2& MM, Matrix_Col_SIMD& m)
{
	return MmulM3(MM, m);
}

struct MmulM4
{
	const Matrix_Col_SIMD& M1;
	const Matrix_Col_SIMD& M2;
	const Matrix_Col_SIMD& M3;
	const Matrix_Col_SIMD& M4;
	const Matrix_Col_SIMD& M5;

	MmulM4(const MmulM3& MM, Matrix_Col_SIMD& m)
		: M1(MM.M1), M2(MM.M2), M3(MM.M3), M4(MM.M4), M5(m) {};

	operator Matrix_Col_SIMD ();
};

inline MmulM4 operator * (const MmulM3& MM, Matrix_Col_SIMD& m)
{
	return MmulM4(MM, m);
}

struct MmulM4mulV
{
	const Matrix_Col_SIMD& M1;
	const Matrix_Col_SIMD& M2;
	const Matrix_Col_SIMD& M3;
	const Matrix_Col_SIMD& M4;
	const Matrix_Col_SIMD& M5;
	const Vect_Col_SIMD& V;

	MmulM4mulV(const MmulM4& MM, Vect_Col_SIMD& v)
		: M1(MM.M1), M2(MM.M2), M3(MM.M3), M4(MM.M4), M5(MM.M5), V(v) {};

	operator Vect_Col_SIMD ();
};

inline MmulM4mulV operator * (const MmulM4& MM, Vect_Col_SIMD& v)
{
	return MmulM4mulV(MM, v);
}

#endif

// ---  End of File ---------------
