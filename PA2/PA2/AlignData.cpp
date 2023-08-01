//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "AlignData.h"

// Insert code
A::A()
{
	a0 = 0;
	a1 = 0;
	pad0 = '\xAA';
	pad1 = '\xAA';
	pad2 = '\xAA';
};

B::B()
{
	b0 = 0; 
	b1 = 0; 
	b2 = 0;
	pad0 = '\xAA';
	pad1 = '\xAA';
	pad2 = '\xAA';
	b3 = 0;
}

C::C()
{
	c0 = 0;
	pad0 = '\xAA';
	pad1 = '\xAA';
	pad2 = '\xAA';
	pad3 = '\xAA';
	pad4 = '\xAA';
	pad5 = '\xAA';
	pad6 = '\xAA';
	c1 = 0;
	c2 = 0;
	pad7 = '\xAA';
	pad8 = '\xAA';
	pad9 = '\xAA';
	pad10 = '\xAA';
	pad11 = '\xAA';
	pad12 = '\xAA';
	pad13 = '\xAA';
}

D::D()
{
	d0 = A(); 
	d1 = 0; 
	d2 = B(); 
	d3 = 0; 
	pad0 = '\xAA';
	pad1 = '\xAA';
	pad2 = '\xAA';
	pad3 = '\xAA';
	pad4 = '\xAA';
	pad5 = '\xAA';
	pad6 = '\xAA';
	d4 = C();
}

E::E()
{
	a0 = A(); 
	c0 = C(); 
	aa = 0; 
	pad0 = '\xAA';
	pad1 = '\xAA';
	pad2 = '\xAA';
	b0 = B(); 
	pad3 = '\xAA';
	pad4 = '\xAA';
	pad5 = '\xAA';
	pad6 = '\xAA';
}

// ---  End of File ---
