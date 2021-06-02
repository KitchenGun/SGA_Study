#pragma once

#include "../Global/Define/KGDefine.h"
/*
템플릿이란?
함수 또는 클래스를 선언및 구현할때 자료형을 지정하지 않고 해당 행위를 할수있게 해주는 기능을 의미한다 
이렇게 선언된 템플릿은 실제 해당 함수의 호출하는 시점 또는 객체를 생성하는 시점에 자료형을 결정하는 것이 가능하다
템플릿을 활용하면 동일한 역할을 수행하는 함수 또는 클래스를 자료형 별로 만들지 않아도 된다

따라서 템플릿은 자료형에 상관없이 동일한 역할을 수행하는 함수 또는 클래스를 제작할때 유용하게 사용하는 것이 가능하다

ex
template <typename T>
void Swap(T &a_rtLhs,T &a_rtRhs)
{
	T tTemp = a_rtLhs;
	a_rtLhs=a_rtRhs;
	a_rtRhs =tTemp;
}

*/
namespace E07Space
{
	void E07(const int argc, const char **args);
}