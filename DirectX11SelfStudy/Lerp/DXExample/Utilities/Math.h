#pragma once

class Math
{
	//static 함수를 사용하여서 객체없이 사용할수있도록 제작
public:
	static bool Intersect(Square *r1, Square *r2);
	static Vector3 Lerp(Vector3 start, Vector3 end,float time);
};