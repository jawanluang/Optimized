//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef CONDIMENTS_H
#define CONDIMENTS_H

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

enum class Condiments : uint8_t
{
	Plain          = 0x0,
	Ketchup        = 0x01,
	Green_Relish   = 0x02,
	Pickle_Spear   = 0x04,
	Tomato_Wedge   = 0x08,
	Yellow_Mustard = 0x10,
	Sport_Peppers  = 0x20,
	Celery_Salt    = 0x40,
	Chopped_Onions = 0x80,
	Everything     = 0xFE
};

#endif

//---  End of File ---