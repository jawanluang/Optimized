//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef JEDI_HOTCOLD_H
#define JEDI_HOTCOLD_H

#include "JediColdNode.h"
#include "JediHotNode.h"
class Bloated;

class JediHotCold
{
public:
	JediHotCold() = delete;
	JediHotCold(const JediHotCold &) = delete;
	JediHotCold &operator = (const JediHotCold &) = delete;

	JediHotCold(const Bloated *const pBloated);
	~JediHotCold();

	bool FindKey(int key, JediColdNode *&pFoundColdNode, JediHotNode *&pFoundHotNode);
	JediHotNode *GetHotHead() const;

private:
	// -----------------------------------------------------------------
	// NO varaibles that have Count or number of nodes in list allowed
	// -----------------------------------------------------------------
	// You CANNOT add additional data to this class
	JediHotNode *pHotHead;
	JediRedirect *pRedirectHead;
	JediColdNode *pColdHead;
};

#endif

// ---  End of File ---

