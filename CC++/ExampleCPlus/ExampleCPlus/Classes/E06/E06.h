#pragma once

#include "../Global/Define/KGDefine.h"
/*
연산자 오버로딩이란?

객체를 대상으로 연산자를 사용할수있게 하는 기능을 의미한다
즉 연산자 오버로딩을 사용하면 객체를 변수와 유사하게 제어하는 것이 가능하다

c++컴파일러는 기본적으로 객체를 대상으로 산술 연산과 같은 기능은 제공하지 않지만
연산자 오버로딩을 사용하면 특정 객체에 연산자를 사용했을때 특수한 이름을 지닌 맴버 함수 및 전역 함수를 
호출 함으로써 객체를 대상으로 하는 연산자를 사용하는 것이 가능하게 해준다
*/
namespace E06Space
{
	void E06(const int argc, const char **args);
}