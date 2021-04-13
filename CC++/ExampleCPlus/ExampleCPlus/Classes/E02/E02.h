#pragma once
#include "../Global/Define/KGDefine.h"

/*
함수 오버로딩이란?
c++언어는 c언어와 달리 동일한 이름의 함수를 선언및 구현하는 것이 가능하다 이를 오버로딩이라고 한다
함수 오버로딩이 적용되기 위해서는 각함수의 매개변수 정보가 서로 달라야 한다. 
즉 함수의 반환값은 오버로딩 조건이 아니기 때문에 함수의 이름과 매개변수 정보가 동일하다면 
반환값이 다르다 하더라도 컴파일 애러가 발생한다
ex
void SomeFuncA(int,int);
void SomeFuncB(int,int,int);
위의 경우 매개변수의 개수가 서로 다르기 때문에 오버로딩 조건을 만족한다.
void SomeFuncA(int,int);
void SomeFuncB(int,float);
위의 경우 매개변수의 개수는 같지만 자료형이 다르기때문에 오버로딩 조건을 만족한다
int SomeFuncA(int,int);
void SomeFuncB(int,int);
위의 경우 반환값만 다르고 함수이름 매개변수정보가 동일하기때문에 함수 오버로딩 조건 만족 못함 컴파일 에러임

레퍼런스란?
특정 변수의 별칭을 부여하는 기능
레퍼런스를 사용하면 특정 변수에 여러 이름을 부여하는 것이 가능하다

ex)
int nValue =0;
int &rnValue =nValue;

rnValue = 10; nvalue에 10을 할당한것과 동일한 효과

INLINE 함수란?
일반적인 함수와 달리 함수를 호출했을 경우 해당 함수의 몸체로 함수 호출 구문이 치환되는 함수를 의미한다.
인라인 함수는 함수 호출에 의한 퍼포먼스 저하가 없다.
inline 함수는 함수의 선언과 구현이 동일한 파일에 존재해야한다
EX
inline int GetSumValue(int,int);
*/
namespace E02Space
{
	//합계를 반환한다
	int GetSumValue(int a_nLhs, int a_nRhs);

	void E02(const int argc, const char **args);
}
/*
일반적으로 인라인 함수는 선언과 구현이 같은 파일에 존재 해야하지만 include 명령어를 활용하면 선언과 구현을 서로 다른 파일에 명시하는 것이 가능하다 
즉 코드를 관리하는 것이 좀더 수월해진다 만약 인라인 함수로 처리가 안되도 중복처리가 되지 않는다.
*/
#include "E02.inl"