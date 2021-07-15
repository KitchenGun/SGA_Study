#pragma once

#define VK_00 48//정의되지 않은 가상키 정의
#define VK_01 49
#define VK_02 50
#define VK_03 51
#define VK_04 52
#define VK_05 53
#define VK_06 54
#define VK_07 55
#define VK_08 56
#define VK_09 57


class Math
{
	//static 함수를 사용하여서 객체없이 사용할수있도록 제작
public:
	static bool Intersect(Square *r1, Square *r2);
	static bool GroundIntersect(TextureRect* r1);
	static float Lerpf(float min, float max, float target);
};