#include "E01/E01.h"
#include "E02/E02.h"

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
	/*
	/전처리
	c언어로작성된 소스파일이 컴파일되기 이전에 소스 파일전처리에 의해서 튜닝되는 단계를 의미한다 c언어와는 다른 문법을 지니며 해당명령어는 #으로 시작된다.
	/컴파일
	컴퍼일러에 의해서 실제 컴퓨터에게 명령을 내리기위한 네이티브코드로 번역되는 단계 각 파일간에 개별적으로 수행된다.
	/링크
	컴파일이 완료된 파일을 하나로 조합해서 최종적으로 프로그램을 만들어주는 단계
	컴파일은 파일마다 수행되기때문에 결과 파일도 파일 개수만큼 생성된다.
	*/

	//E01(argc, args);
	E02(argc, args);
	return 0;
}