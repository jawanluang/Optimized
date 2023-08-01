//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef JEDI_REDIRECT_H
#define JEDI_REDIRECT_H

#include "JediHotNode.h"
class JediColdNode;

class JediRedirect
{
public:
	JediRedirect() = default;
	JediRedirect(const JediRedirect&) = delete;
	JediRedirect& operator = (const JediRedirect&) = delete;
	~JediRedirect() = default;

	// You CANNOT add additional data to this class
	JediColdNode *pCold[JediHotNode::KeyMax];
};

#endif

// ---  End of File ---

