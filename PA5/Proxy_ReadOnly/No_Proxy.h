//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef NO_PROXY_H
#define NO_PRoxy_H

class Vect2D_No_Proxy
{
public:
	Vect2D_No_Proxy() = default;
	Vect2D_No_Proxy(const Vect2D_No_Proxy &tmp) = default;
	Vect2D_No_Proxy &operator =(const Vect2D_No_Proxy &tmp) = default;
	~Vect2D_No_Proxy() = default;

	void setX(const float inX);
	void setY(const float inY);
	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	Vect2D_No_Proxy operator + (const Vect2D_No_Proxy &tmp) const;

private:
	float x;
	float y;

};

#endif

// ---  End of File ---------------
