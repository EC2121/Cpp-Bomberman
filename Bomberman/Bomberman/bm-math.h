#pragma once

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
	int x;
	int y;
};