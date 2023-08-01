//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef HOT_NODE_H
#define HOT_NODE_H

class ColdNode;

class HotNode
{
public:
	HotNode() = default;
	HotNode(const HotNode&) = delete;
	HotNode& operator = (const HotNode&) = delete;
	~HotNode() = default;

	// You CANNOT add additional data to this class
	HotNode		*pNext;
	HotNode		*pPrev;
	int		key;
	ColdNode	*pCold;
};

#endif

// ---  End of File ---

