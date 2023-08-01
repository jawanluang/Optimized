//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

#ifndef NODE_H
#define NODE_H

#include "Vect.h"
#include "Matrix.h"

class Node
{
public:
	static const unsigned int NAME_SIZE = 128;

public:
	// big four
	Node();
	Node(const Node &) = default;
	Node & operator = (const Node &) = default;
	~Node() = default;

private:
	void privSetRandFloat(float & var) const;
	void privSetRandInt(int & var) const;
	void privSetRandVect(Vect & var) const;
	void privSetRandMatrix(Matrix & var) const ;
	void privSetRandName(char * p, const int size) const;
	char privSetRandChar() const;
	void privSetRandChar(char& var) const;

public:  
	// Treating as SIMPLE DATA, so public is OK
	// You CANNOT add additional data to this class
	Node	*pNext;
	Node	*pPrev;
	char    aa;
	float	x;
	Vect	A;
	float	y;
	Vect	B;
	Vect	C;
	float	z;
	Vect    D;
	Matrix	MA;
	char    bb;
	Matrix	MB;
	float	w;
	Matrix	MC;
	Matrix	MD;
	char    cc;
	char	name[NAME_SIZE];
	Matrix  ME;
	int		key;
	char    dd;
};

#endif 

// ---  End of File ---

