#include "E01/E01.h"

/*
메인 함수는 c 언어로 작성된 프로그램에서 가장 처음으로 실행되는 함수를 의미한다. 
즉 메인 함수가 존재해야지만 프로그램의 시작 위치를 컴퓨터가 알수있기때문에 해당함수는 반드시 정의
메인함수 종료시 프로그램 또한 종료되기 때문에 해당함수를 프로그램의 진입함수라도 한다.
메인함수 실행 == 프로그램 실행
메인함수 종료 == 프로그램 종료
c언어 메인함수의 종류
x의미 : main함수자체의 입력없고 출력 return 이 없음
input o output o int main(int,char**)
input o	output x void main(int, char**)
input x	output o int main(void)
input x	output x void main(void)
*/
int main(int argc, char **args)
{
	E01(argc, args);
	return 0;
}