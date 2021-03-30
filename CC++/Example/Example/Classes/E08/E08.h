#pragma once

#include "../Global/Define/KGDefine.h"

/*
사용자 정의 자료형이란?
언어에서 제공해주는 자료형을 조합해서 작정 중인 프로그램에 맞는 자료형을 만들어 내는 기능을 의미한다.

즉 사용자 정의 자료형을 사용하면 특정 프로그램에 특화됨 전용 자료형을 만들어 내는 것이 가능하다.

C언어 사용자 정의 자료형의 종류
구조체 : 자료형을 조합해서 그룹화 시킬수있는 기능을 의미한다. 연관성있는 데이터를 관리하기 편하다
공용체 : 
열거형 :

구조체 선언 방법
-struct +구조체 이름 +구조체 맴버(맴버 1 ,맴버 2,...)
ex)
struct STPlayer
{
	int m_nID;
	int m_nHP;
	int m_nLevel;
};

STPlayer stPlayer;
 . 을 사용하여서 사용하면 된다. 구조체는 변수 그룹의 개념이다.
stPlayer.m_nID =10;
stPlayer.m_nHP =20;
stPlayer.m_nLevel=30;
*/

void E08(int argc, char **args);