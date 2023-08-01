//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Vect4D.h"
#include "Vect_Triangle_SIMD.h"

int Triangle_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Triangle, TestConfig::ALL)
{
#if Triangle

	// ---------------------------------------------------
	// Triangle tests
	// ---------------------------------------------------
	{

		Vect4D va(4.0f, 5.0f, 6.0f, 0.0f);
		Vect4D vb(10.0f, 20.0f, 30.0f, 0.0f);
		Vect4D vout;

		float lenA = va.Length();
		float lenB = vb.Length();

		CHECK (f_eq(lenA, 8.775f) );
		CHECK( f_eq(lenB, 37.416f));

		vout = va.Cross(vb);
		Vect4D vRef(30.0f ,-60.0f, 30.0f, 0.0f);

		CHECK(V_EQ(vout, vRef));

		float area = Vect4D::Area(va, vb);
		CHECK(f_eq(area, 36.742f));

		Vect_TRIANGLE_SIMD va2(4.0f, 5.0f, 6.0f, 0.0f);
		Vect_TRIANGLE_SIMD vb2(10.0f, 20.0f, 30.0f, 0.0f);
		Vect_TRIANGLE_SIMD vout2;

		float lenA2 = va2.Length();
		float lenB2 = vb2.Length();

		CHECK(f_eq(lenA2, 8.775f));
		CHECK(f_eq(lenB2, 37.416f));

		vout2 = va2.Cross(vb2);
		Vect_TRIANGLE_SIMD vRef2(30.0f, -60.0f, 30.0f, 0.0f);

		CHECK(V_EQ(vout2, vRef2));

		float area2 = Vect_TRIANGLE_SIMD::Area(va2, vb2);
		CHECK(f_eq(area2, 36.742f));

		Triangle_unit_result = 1;
	}

#endif
} TEST_END

// ---  End of File ---
