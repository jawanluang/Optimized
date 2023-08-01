//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"

#include "Vect4D.h"
#include "Vect_LERP_SIMD.h"

int Lerp_unit_result = 0;

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))


TEST(Lerp_Tests, TestConfig::ALL)
{
#if Lerp_Tests

	// ---------------------------------------------------
	// LERP tests
	// ---------------------------------------------------
	{

		Vect4D va(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vb(10.0f, 20.0f, 30.0f, 40.0f);
		Vect4D vout;

		vout = Vect4D::Lerp(va, vb, 0.0f);

		CHECK((vout.x == 0.0f));
		CHECK((vout.y == 0.0f));
		CHECK((vout.z == 0.0f));
		CHECK((vout.w == 0.0f));

		Vect4D vc(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vd(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(vc, vd, 0.5f);

		CHECK((vout.x == 5.0f));
		CHECK((vout.y == 10.0f));
		CHECK((vout.z == 15.0f));
		CHECK((vout.w == 20.0f));

		Vect4D ve(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vf(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(ve, vf, 0.25f);

		CHECK((vout.x == 2.5f));
		CHECK((vout.y == 5.0f));
		CHECK((vout.z == 7.50f));
		CHECK((vout.w == 10.0f));

		Vect4D vg(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vh(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(vg, vh, 1.0f);

		CHECK((vout.x == 10.0f));
		CHECK((vout.y == 20.0f));
		CHECK((vout.z == 30.0f));
		CHECK((vout.w == 40.0f));

		Vect_LERP_SIMD va_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vb_simd(10.0f, 20.0f, 30.0f, 40.0f);
		Vect_LERP_SIMD vout_simd;

		vout_simd = Vect_LERP_SIMD::Lerp(va_simd, vb_simd, 0.0f);

		CHECK((vout_simd.x == 0.0f));
		CHECK((vout_simd.y == 0.0f));
		CHECK((vout_simd.z == 0.0f));
		CHECK((vout_simd.w == 0.0f));

		Vect_LERP_SIMD vc_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vd_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(vc_simd, vd_simd, 0.5f);

		CHECK((vout_simd.x == 5.0f));
		CHECK((vout_simd.y == 10.0f));
		CHECK((vout_simd.z == 15.0f));
		CHECK((vout_simd.w == 20.0f));

		Vect_LERP_SIMD ve_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vf_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(ve_simd, vf_simd, 0.25f);

		CHECK((vout_simd.x == 2.5f));
		CHECK((vout_simd.y == 5.0f));
		CHECK((vout_simd.z == 7.50f));
		CHECK((vout_simd.w == 10.0f));

		Vect_LERP_SIMD vg_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vh_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(vg_simd, vh_simd, 1.0f);

		CHECK((vout_simd.x == 10.0f));
		CHECK((vout_simd.y == 20.0f));
		CHECK((vout_simd.z == 30.0f));
		CHECK((vout_simd.w == 40.0f));

		Vect_LERP_SIMD vOut;
		Vect_LERP_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
		Vect_LERP_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);

		vOut = Vect_LERP_SIMD::Lerp(A, B, 0.5f);

		CHECK((vOut.x == 11.0f));
		CHECK((vOut.y == 7.0f));
		CHECK((vOut.z == 13.0f));
		CHECK((vOut.w == 22.0f));

		vOut = Vect_LERP_SIMD::Lerp(A, vOut, 0.5f);

		CHECK((vOut.x == 6.0f));
		CHECK((vOut.y == 4.5f));
		CHECK((vOut.z == 8.0f));
		CHECK((vOut.w == 13.0f));

		Vect_LERP_SIMD vOut_SIMD;
		Vect_LERP_SIMD A_SIMD(1.00f, 2.0f, 3.0f, 4.0f);
		Vect_LERP_SIMD B_SIMD(21.00f, 12.0f, 23.0f, 40.0f);

		vOut_SIMD = Vect_LERP_SIMD::Lerp(A_SIMD, B_SIMD, 0.5f);

		CHECK((vOut_SIMD.x == 11.0f));
		CHECK((vOut_SIMD.y == 7.0f));
		CHECK((vOut_SIMD.z == 13.0f));
		CHECK((vOut_SIMD.w == 22.0f))

		vOut_SIMD = Vect_LERP_SIMD::Lerp(A_SIMD, vOut_SIMD, 0.5f);

		CHECK((vOut_SIMD.x == 6.0f));
		CHECK((vOut_SIMD.y == 4.5f));
		CHECK((vOut_SIMD.z == 8.0f));
		CHECK((vOut_SIMD.w == 13.0f));

		Lerp_unit_result = 1;
	}

#endif
} TEST_END

// ---  End of File ---
