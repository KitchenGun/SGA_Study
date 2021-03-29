#pragma once

#include "../Global/Define/KGDefine.h"

/*
 함수란 프로그램의 전체 또는 일부분을 그룹화 시켜서 따로 분리 시킬수있는 기능을 의미한다
 이렇게 따로 그룹화 된 코드는 필요할때 불러와서 재사용 하는 것이 가능하다
 즉 함수를 활용하면 프로그램 로직을 반복적으로 작성필요가 사라진다.

c언어 함수 선언법
반환형 함수이름 (매개변수1,매개변수2,매개변수3,...)

ex)
int SumFuncA(int a_nLhs, int a_nRhs);	input o output o
void SumFuncA(int a_nLhs, int a_nRhs);  input o output x
int SomeFuncC(void);					input x output o
void SomeFuncD(void);					input x output x

c언어 함수 구현법
int SumFuncA(int a_nLhs, int a_nRhs){}
void SumFuncA(int a_nLhs, int a_nRhs){}
int SomeFuncC(void){}
void SomeFuncD(void){}

함수 선언 vs 함수 구현
선언은 컴파일러에게 함수의 존재 사실을 알리는 역할  명시역할(중복가능)
구현은 컴파일러에게 함수의 동작 방식을 알리는 역할	서술역할(중복불가능)

공간(영역) 이란 ?
C언어는 전역 공간과 지역 공간이라는 개념이 존재하며, 지역 공간은 {} (중괄호 연산자)를 사용해서 명시 가능하며
특정 지역에 속해 있지 않는 모든 영역을 전역 공간이라고 한다
함수는 선언 및 구현은 전역 공간에만 명시가능 지역 공간에는 주로 컴퓨터가 수행할 명령문들이 위치하게 된다.
 c언어 변수 종류 
 -지역 변수 : 특정 지역 내부에서만 사용가능 하고 해당 지역이 끝나면 메모리에서 사라진다
 -전역 변수 : 전역 공간에 선언되는 변수 프로그램 전체에서 사용이 가능하다 프로그램 전체에 공유되는 변수를 의미 한다 프로그램 종료시 메모리에서 사라짐
 -정적 지역 변수
 -정적 전역 변수
 */
void E07(int argc, char **args);


