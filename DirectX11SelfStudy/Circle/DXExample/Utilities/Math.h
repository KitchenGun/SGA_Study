#pragma once

#define VK_00 48//���ǵ��� ���� ����Ű ����
#define VK_01 49
#define VK_02 50
#define VK_03 51
#define VK_04 52
#define VK_05 53
#define VK_06 54
#define VK_07 55
#define VK_08 56
#define VK_09 57


enum class Direction
{
	NONE = 0,
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	//���� �Է� ��Ȳ
	TL,
	TR,
	BL,
	BR
};

class Math
{
	//static �Լ��� ����Ͽ��� ��ü���� ����Ҽ��ֵ��� ����
public:
	static bool Intersect(Square *r1, Square *r2);
	static bool CircleIntersect(Ball* c1, Square*r1);
	static bool PlayerIntersect(Ball* c1, Square*r1);
	static void CircleWallIntersect(Ball* c1);
	static Direction TouchEdge(Square *r1);
};