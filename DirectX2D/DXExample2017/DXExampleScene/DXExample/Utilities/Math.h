#pragma once

class Math
{
	//static �Լ��� ����Ͽ��� ��ü���� ����Ҽ��ֵ��� ����
public:
	static bool Intersect(Square *r1, Square *r2);
	static bool CircleIntersect(Circle *c1, Square *r2);
};