#pragma once
#define DECIMAL_PLACES 4
struct intVector2_t
{
public:
	int x;
	int y;
	intVector2_t(int _x, int _y) :x(_x), y(_y){}
	intVector2_t operator+(intVector2_t&);
	intVector2_t operator-(intVector2_t&);
	intVector2_t& operator+=(intVector2_t&);
	intVector2_t& operator-=(intVector2_t&);
	Vector2_t toFloat();
};

struct Vector2_t
{
public:
	float x;
	float y;
	Vector2_t(float _x, float _y) :x(_x), y(_y) {}
	Vector2_t operator+(intVector2_t&);
	Vector2_t operator-(intVector2_t&);
	Vector2_t& operator+=(intVector2_t&);
	Vector2_t& operator-=(intVector2_t&);
	Vector2_t operator+(Vector2_t&);
	Vector2_t operator-(Vector2_t&);
	Vector2_t& operator+=(Vector2_t&);
	Vector2_t& operator-=(Vector2_t&);
	intVector2_t ToInt();
	intVector2_t Round();

private:
	static void DecimalRound(Vector2_t&);
};



