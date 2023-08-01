//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

// locals
#include "Bloated.h"
#include "Node.h"

Node::Node()
{
	this->privSetRandChar(aa);
	this->privSetRandChar(bb);
	this->privSetRandChar(cc);
	this->privSetRandChar(dd);
	this->privSetRandFloat(x);
	this->privSetRandFloat(y);
	this->privSetRandFloat(z);
	this->privSetRandFloat(w);
	this->privSetRandVect(A);
	this->privSetRandVect(B);
	this->privSetRandVect(C);
	this->privSetRandVect(D);
	this->privSetRandMatrix(MA);
	this->privSetRandMatrix(MB);
	this->privSetRandMatrix(MC);
	this->privSetRandMatrix(MD);
	this->privSetRandMatrix(ME);
	this->privSetRandName(name, NAME_SIZE);
	this->privSetRandInt(key);
}

void Node::privSetRandFloat(float & var) const
{
	float real = static_cast<float> (rand());
	float decimal = static_cast< float > (rand());
	var = real + (decimal / RAND_MAX);
}

void Node::privSetRandInt(int & var) const
{
	int high = rand();
	int low = rand();
	var = high << 16 | low;
}

void Node::privSetRandVect(Vect & var) const
{
	this->privSetRandFloat(var.x);
	this->privSetRandFloat(var.y);
	this->privSetRandFloat(var.z);
}

void Node::privSetRandChar(char& var) const
{
	var = static_cast<char> (rand() % 255);
}

char Node::privSetRandChar() const
{
	// Generate 0x00-0xFE
	char var = static_cast<char> (rand() % 255);
	return var;
}

void Node::privSetRandMatrix(Matrix & var) const
{
	this->privSetRandFloat(var.m00);
	this->privSetRandFloat(var.m01);
	this->privSetRandFloat(var.m02);
	this->privSetRandFloat(var.m03);
		 
	this->privSetRandFloat(var.m10);	
	this->privSetRandFloat(var.m11);	
	this->privSetRandFloat(var.m12);	
	this->privSetRandFloat(var.m13);	
	
	this->privSetRandFloat(var.m20);	
	this->privSetRandFloat(var.m21);
	this->privSetRandFloat(var.m22);
	this->privSetRandFloat(var.m23);
		
	this->privSetRandFloat(var.m30);
	this->privSetRandFloat(var.m31);
	this->privSetRandFloat(var.m32);
	this->privSetRandFloat(var.m33);
}

void Node::privSetRandName(char *p, const int size) const
{
	// Fill the string with random data
	for( int i = 0; i<size; i++)
	{
		*p++ = this->privSetRandChar()+1;
	}
	// terminate the last character
	*--p = 0;
}

// ---  End of File ---

