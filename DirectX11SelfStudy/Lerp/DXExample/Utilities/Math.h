#pragma once

class Math
{
	//static �Լ��� ����Ͽ��� ��ü���� ����Ҽ��ֵ��� ����
public:
	static bool Intersect(Square *r1, Square *r2);
	static Vector3 Lerp(Vector3 start, Vector3 end,float time);
};