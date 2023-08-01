//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

#ifndef ALIGN_H
#define ALIGN_H

class Align
{
public:
	struct Info
	{
		int NumTotalBytes;
		int NumBytesOfPadding;
	};

	static Info PrintME(void *p, int StructSize, char *s);
};

#endif

// ---  End of File ---

