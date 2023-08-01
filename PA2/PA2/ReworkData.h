//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

struct DataA // 16
{
	double r; // 8 byte : 8 byte aligned
	char a; // 1 byte
	char pad0;
	char pad1;
	char pad2;
	char b; // 1 byte
	char pad3;
	char pad4;
	char pad5;
};

struct DataB // 24
{
	DataA da; // 16 byte : 8 byte aligned
	int i; // 4 byte
	char a; // 1 byte
	char b; // 1 byte
	char pad0;
	char pad1;
};

struct DataC // 12
{
	int j; // 4 byte : 4 byte aligned
	int i; // 4 byte
	bool f; // 1 byte
	char a; // 1 byte
	char pad0;
	char pad1;
};

struct DataD // 16
{
	double r; // 8 byte : 8 byte aligned
	int i; // 4 byte
	char a; // 1 byte
	char b; // 1 byte
	char pad0;
	char pad1;
};

struct DataE // 32
{
	char name[12]; // 12 byte : 16 byte aligned
	char a; // 1 byte
	char c; // 1 byte
	char pad3;
	char pad4;
	double r; // 8 byte
	int x; // 4 byte
	int* p; // 4 byte
};

struct Vect // 20
{
	float vx; // 4 byte : 4 byte aligned
	float vy; // 4 byte
	float vz; // 4 byte
	float vw; // 4 byte
	char a; // 1 byte
	char b; // 1 byte
	char pad0;
	char pad1;
};

struct DataF // 32
{
	Vect v; // 20 byte : 4 byte aligned
	int i; // 4 byte
	int j; // 4 byte
	char c; // 1 byte
	char b; // 1 byte
	char pad0;
	char pad1;
};

struct DataG // 56
{
	DataA a0; // 16 byte : 8 byte aligned
	Vect  v; // 20 byte : 4 byte aligned
	char  b0; // 1 byte
	char  c0; // 1 byte
	char pad1;
	char pad2;
	double d0; // 8 byte
	double d1; // 8 byte
};



#endif

// ---  End of File ---

