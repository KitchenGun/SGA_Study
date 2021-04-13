#include "E01/E01.h"
#include "E02/E02.h"
#include "E03/E03.h"


//메인함수
int main(const int argc, const char **args)
{
	/*
	범위 지정 연산자를 사용하면 특정 지역 하위에 존재하는 함수 및 변수등에 접근하는 것이 가능하다. 
	즉 해당 연산자를 사용하면 특정 이름 공간에 선언되어있는 함수 등을 제어 할 수 있다
	*/
	//E01Space::E01(argc, args);
	//E02Space::E02(argc, args);
	E03Space::E03(argc, args);
	return 0;
}