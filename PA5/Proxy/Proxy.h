//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PROXY_H
#define PROXY_H

// Modify This File

class Vect2D
{
public:
	Vect2D(const Vect2D &tmp) = default;
	Vect2D &operator =( const Vect2D &tmp) = default;
	Vect2D() = default;
	~Vect2D() = default;

	Vect2D(const float inX, const float inY);

	void setX(const float inX);
	void setY(const float inY);
	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	//-----------------------------------------------
	// Rules   this function cannot be inlined 
	//         or implemented directly
	//-----------------------------------------------
	//  Vect2D operator + (const Vect2D &tmp) const;
	//-----------------------------------------------


private:
	float x;
	float y;

	//-----------------------------------------------
	// Add friends here... if you want (hint)
	//-----------------------------------------------
	friend struct VaddV;
	friend struct V3V;
	friend struct V4V;
	friend struct V5V;
	friend struct V6V;
	friend struct V7V;
	friend struct V8V;
	friend struct V9V;
	friend struct V10V;

};

struct VaddV
{
	const Vect2D& v1;
	const Vect2D& v2;

	VaddV(const Vect2D& t1, const Vect2D& t2)
		:v1(t1), v2(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x, v1.y + v2.y);
	}
};

inline VaddV operator + (const Vect2D& a1, const Vect2D& a2)
{
	return VaddV(a1, a2);
}

struct V3V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;

	V3V(const VaddV& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x, v1.y + v2.y + v3.y);
	}
};

inline V3V operator + (const VaddV& a1, const Vect2D& a2)
{
	return V3V(a1, a2);
}

struct V4V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;

	V4V(const V3V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x, v1.y + v2.y + v3.y + v4.y);
	}
};

inline V4V operator + (const V3V& a1, const Vect2D& a2)
{
	return V4V(a1, a2);
}

struct V5V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;

	V5V(const V4V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x,
			v1.y + v2.y + v3.y + v4.y + v5.y);
	}
};

inline V5V operator + (const V4V& a1, const Vect2D& a2)
{
	return V5V(a1, a2);
}

struct V6V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;

	V6V(const V5V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y);
	}
};

inline V6V operator + (const V5V& a1, const Vect2D& a2)
{
	return V6V(a1, a2);
}

struct V7V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;

	V7V(const V6V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t1.v6), v7(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y);
	}
};

inline V7V operator + (const V6V& a1, const Vect2D& a2)
{
	return V7V(a1, a2);
}


struct V8V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;

	V8V(const V7V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4),
		v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y);
	}
};

inline V8V operator + (const V7V& a1, const Vect2D& a2)
{
	return V8V(a1, a2);
}


struct V9V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;
	const Vect2D& v9;

	V9V(const V8V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4),
		v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t1.v8), v9(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x + v9.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y + v9.y);
	}
};

inline V9V operator + (const V8V& a1, const Vect2D& a2)
{
	return V9V(a1, a2);
}

struct V10V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;
	const Vect2D& v9;
	const Vect2D& v10;

	V10V(const V9V& t1, const Vect2D& t2)
		:v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4),
		v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t1.v8), v9(t1.v9), v10(t2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x + v9.x + v10.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y + v9.y + v10.y);
	}
};

inline V10V operator + (const V9V& a1, const Vect2D& a2)
{
	return V10V(a1, a2);
}

#endif

// ---  End of File ---------------