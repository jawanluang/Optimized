//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef NO_RVO_H
#define NO_RVO_H

// DO NOT CHANGE THIS FILE

class Vect2D_No_RVO
{
public:
	Vect2D_No_RVO();
	~Vect2D_No_RVO();

	Vect2D_No_RVO(const float inX, const float inY);

	void setX(const float inX);
	void setY(const float inY);

	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	Vect2D_No_RVO operator + (const Vect2D_No_RVO &tmp) const;
	Vect2D_No_RVO operator - (const Vect2D_No_RVO &tmp) const;
	Vect2D_No_RVO operator * (const float scale) const;
	Vect2D_No_RVO operator / (const float scale) const;

private:
	float x;
	float y;

};

#endif

// ---  End of File ---------------
