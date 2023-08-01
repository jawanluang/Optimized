//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------------------- 

#ifndef IMPLICIT_H
#define IMPLICIT_H

// ------------------------------------------------------------------------
//   Modify This File - to generate Errors to prevent implicit conversions
// ------------------------------------------------------------------------

class Vect
{
public:
	Vect();
	Vect(const Vect &tmp);
	const Vect & operator = (const Vect &tmp);
	~Vect();

	Vect(const float inX, const float inY, const float inZ);

	void setX(const float inX);
	void setY(const float inY);
	void setZ(const float inZ);

	void set(const float inX, const float inY, const float inZ);

	float getX() const;
	float getY() const;
	float getZ() const;

	Vect operator + (const Vect tmp) const;


private:
	float x;
	float y;
	float z;

	template <typename T1, typename T2, typename T3> Vect(const T1 x, const T2 y, const T3 z);

	template <typename T> void setX(T x);
	template <typename T> void setY(T y);
	template <typename T> void setZ(T z);

	template <typename T1, typename T2, typename T3> void set(const T1 x, const T2 y, const T3 z);

	template <typename T> Vect operator + (const T tmp);
};

#endif

// ---  End of File ---------------
