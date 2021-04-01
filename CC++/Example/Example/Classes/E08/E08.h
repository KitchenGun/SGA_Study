#pragma once



#include "../Global/Define/KGDefine.h"

/*
사용자 정의 자료형이란?
언어에서 제공해주는 자료형을 조합해서 작정 중인 프로그램에 맞는 자료형을 만들어 내는 기능을 의미한다.

즉 사용자 정의 자료형을 사용하면 특정 프로그램에 특화됨 전용 자료형을 만들어 내는 것이 가능하다.

C언어 사용자 정의 자료형의 종류
구조체 : 자료형을 조합해서 그룹화 시킬수있는 기능을 의미한다. 연관성있는 데이터를 관리하기 편하다
공용체 : 구조체와 마찬가지로 기본 자료형을 조합해서 그룹화 시키는 기능을 의미한다 
구조체의 맴버는 서로 다른메모리에 할당되는 반면 공용체의 맴버는 서로 같은 메모리 공유하는 특징이 있다.
즉 해당맴버 뿐만 아니라 다른 맴버들도 영향을 받는다 즉 마지막으로 할당된 맴버의 값만 정상적으로 데이터가 보존된다.
열거형 : 심볼릭 상수를 정의 할수있는 기능을 의미하며 해당 열거형 자체를 자료형으로 사용하는 것 또한 가능하다 
즉 열거형 상수를 사용하면 프로그램을 제작 할때 필요한 여러가지 고유식별자를 수월하게 선언하는 것이 가능하다 

구조체 선언 방법
-struct +구 조체 이름 +구조체 맴버(맴버 1 ,맴버 2,...)
ex)
struct STPlayer
{
	int m_nID;
	int m_nHP;
	int m_nLevel;
};
//c언어에서는 
typedef struct STPlayer 
{
	int m_nID;
	int m_nHP;
	int m_nLevel;
}stPlayer;
STPlayer stPlayer;
 . 을 사용하여서 사용하면 된다. 구조체는 변수 그룹의 개념이다.
stPlayer.m_nID =10;
stPlayer.m_nHP =20;
stPlayer.m_nLevel=30;

공용체 선언 방법
-union + 공용체 이름 + 공용체 맴버(맴버 1 ,맴버 2,...)
ex)
union UNData
{
	int m_nData;
	float m_fData;
};

UNData unData;
unData.m_nData=0;
unData.m_fData=10.0f;

식별자 선언 방법
//c언어에서 사용하는법
enum 열거형 이름 + 상수(상수 1 상수 2 ,....)

ex)
enum EItemType
{
  NONE = -1,
  GOLD,
  WEAPON,
  MAX_VALUE
}
*/

void E08(int argc, char **args);