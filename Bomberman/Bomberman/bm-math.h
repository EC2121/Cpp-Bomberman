#pragma once
#include <math.h>
struct Vector2i
{
	Vector2i()
		: x(0)
		, y(0)
	{}
	Vector2i(const int in_x, const int in_y)
		: x(in_x)
		, y(in_y)
	{}

	~Vector2i() = default;
	int x;
	int y;
};

struct Vector2f
{
	Vector2f()
		: x(0)
		, y(0)
	{}
	Vector2f(const float in_x, const float in_y)
		: x(in_x)
		, y(in_y)
	{}
	~Vector2f() = default;
	Vector2f(const Vector2f& in_other)
	{
		x = in_other.x;
		y = in_other.y;
	}
	Vector2f& operator=(const Vector2f& in_other);
	Vector2f operator+(const Vector2f& in_other);
	Vector2f operator*(const Vector2f& in_other);
	Vector2f operator*(const float& in_float);
	Vector2f& operator+=(const Vector2f& in_other);
	Vector2f& operator*=(const float in_other);
	Vector2f& operator-();
	bool operator>(Vector2f& in_other);
	float Magnitude() { return fabs(sqrt(powf(this->x, 2)) + sqrt(powf(this->y, 2))); }
	float x;
	float y;
	static const Vector2f zero;
};