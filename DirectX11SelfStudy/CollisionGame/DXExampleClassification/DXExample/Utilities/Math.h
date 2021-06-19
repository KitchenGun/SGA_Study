#pragma once

enum class Direction
{
	NONE=0,
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	//동시 입력 상황
	TL,
	TR,
	BL,
	BR
};

class Math
{
public:
	static bool Intersect(Square *r1, Square *r2);
	static bool IsTouchEdge(Square *r1);
	static Direction TouchEdge(Square *r1);
};