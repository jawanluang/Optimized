//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef NO_IMPLICIT_H
#define NO_IMPLICIT_H

class Vect_No_Protection
{
public:
	Vect_No_Protection();
	Vect_No_Protection(const Vect_No_Protection &tmp);
	const Vect_No_Protection & operator = (const Vect_No_Protection &tmp);
	~Vect_No_Protection();

	Vect_No_Protection(const float inX, const float inY, const float inZ);

	void setX(const float inX);
	void setY(const float inY);
	void setZ(const float inZ);

	void set(const float inX, const float inY, const float inZ);

	float getX() const;
	float getY() const;
	float getZ() const;

	Vect_No_Protection operator + (const Vect_No_Protection tmp) const;

private:
	float x;
	float y;
	float z;

};

#endif

// ---  End of File ---------------
