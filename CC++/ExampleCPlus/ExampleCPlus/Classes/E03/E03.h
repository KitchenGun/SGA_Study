#pragma once
#include "../Global/Define/KGDefine.h"
/*
클래스란?
객체를 생성하기 위한 틀을 의미하며 프로그래밍 관점에서 클래스는 변수와 함수를 그룹화 시켜놓은 것이다.
즉 구조체가 일반적인 구조체는 변수 만을 그룹화 시킬수있던 것과 달리 클래스는 함수 또한 그룹화 시키는 것이 가능하다.

ex
class CPlayer
{
	int m_nHP;
	int m_nATK;

	//공격 
	void Attack(CPlayer *a_pOtherPlayer);
};

CPlayer oPlayerA;
CPlayer oPlayerB;

oPlayerA.Attack(&oPlayerB);
*/
namespace E03Space
{
	void E03(const int argc, const char **args);
}