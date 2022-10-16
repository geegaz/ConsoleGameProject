#pragma once
#define DECIMAL_PLACES 4

struct floatVector2_t;

struct intVector2_t
{
public:
	int x;
	int y;
	intVector2_t() :x(0), y(0) {};
	intVector2_t(int _x, int _y) :x(_x), y(_y){}
	intVector2_t operator+(intVector2_t&);
	intVector2_t operator-(intVector2_t&);
	intVector2_t& operator+=(intVector2_t&);
	intVector2_t& operator-=(intVector2_t&);
	floatVector2_t toFloat();
};

struct floatVector2_t
{
public:
	float x;
	float y;
	floatVector2_t() :x(0.0f), y(0.0f) {};
	floatVector2_t(float _x, float _y) :x(_x), y(_y) {}
	floatVector2_t operator+(intVector2_t&);
	floatVector2_t operator-(intVector2_t&);
	floatVector2_t& operator+=(intVector2_t&);
	floatVector2_t& operator-=(intVector2_t&);
	floatVector2_t operator+(floatVector2_t&);
	floatVector2_t operator-(floatVector2_t&);
	floatVector2_t& operator+=(floatVector2_t&);
	floatVector2_t& operator-=(floatVector2_t&);
	intVector2_t ToInt();
	intVector2_t Round();

private:
	static floatVector2_t& DecimalRound(floatVector2_t&);
};



