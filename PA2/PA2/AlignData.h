//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ALIGN_DATA_H
#define ALIGN_DATA_H

// -----------------------------------------------------------
// Add default constructor to each structure
// Initialize all variables to 0
// Do NOT rearrange any data layout...
// These are the classes used with Align::PrintMe();
// -----------------------------------------------------------

struct A
{
// Hint add the default constructor and set variables to zero
	A();
	int  a0; // 4 byte : 4 byte aligned
	char a1; // 1 byte
	char pad0;
	char pad1;
	char pad2;
};

struct B
{
	B();
	float b0; // 4 byte : 4 byte aligned
	float b1; // 4 byte
	bool  b2; // 1 byte
	char pad0;
	char pad1;
	char pad2;
	float b3; // 4 byte
};

struct C
{
	C();
	char   c0; // 1 byte
	char pad0;
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;
	char pad6;
	double c1; // 8 byte : 8 byte aligned
	char   c2; // 1 byte
	char pad7;
	char pad8;
	char pad9;
	char pad10;
	char pad11;
	char pad12;
	char pad13;
};

struct D
{
	D();
	A      d0; // 8 byte
	double d1; // 8 byte
	B      d2; // 16 byte
	char   d3; // 1 byte
	char pad0;
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;
	char pad6;
	C      d4; // 24 byte : 32 byte aligned
};

struct E
{
	E();
	A    a0; // 8 byte
	C    c0; // 24 byte : 32 byte aligned?
	char aa; // 1 byte
	char pad0;
	char pad1;
	char pad2;
	B    b0; // 16 byte
	char pad3;
	char pad4;
	char pad5;
	char pad6;
};

#endif

// ---  End of File ---

