#include "bm-math.h"
const Vector2f Vector2f::zero = Vector2f(0, 0);
Vector2f& Vector2f::operator=(const Vector2f& in_other)
{
	x = in_other.x; y = in_other.y; return *this; 
}

Vector2f Vector2f::operator+(const Vector2f& in_other)
{
	 return Vector2f(in_other.x + x, in_other.y + y);
}

Vector2f Vector2f::operator*(const Vector2f& in_other)
{
	return Vector2f(in_other.x * x, in_other.y * y);
}

Vector2f Vector2f::operator*(const float& in_float)
{
	return Vector2f(x * in_float, y * in_float); 
}

Vector2f& Vector2f::operator+=(const Vector2f& in_other)
{
	x += in_other.x;
	y += in_other.y;
	return *this;
}

Vector2f& Vector2f::operator*=(const float in_other)
{
	x *= in_other;
	y *= in_other;
	return *this;
}

Vector2f& Vector2f::operator-()
{
	x = -x;
	y = -y;
	return *this;
}

bool Vector2f::operator>(Vector2f& in_other)
{
	
	float magnitude = this->Magnitude();
	float magnitude2 = in_other.Magnitude();
	return magnitude > magnitude2;
}
