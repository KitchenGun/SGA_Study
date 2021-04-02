#include "E01/E01.h"
#include "E02/E02.h"
#include "E03/E03.h"
#include "E04/E04.h"
#include "E05/E05.h"
#include "E06/E06.h"
#include "E07/E07.h"
#include "E08/E08.h"
#include "E09/E09.h"


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

//extern int g_nGValue;
//extern 키워드를 사용하면 다른 파일의 전역 변수를 사용 가능하다  컴파일러에게 알리는 역할 수행

int main(int argc, char **args)
{
	srand((unsigned int)time(NULL));
	//unsigned  +-를 표현하는 비트를 데이터 표현하는데 사용함 
	//즉 4비트에서 3비트를 값 표현에 사용하면 1비트는 +-를 표현하는데 사용함
	/*
	컴퓨터는 기본적으로 난수를 생성 불가능 특정 공식에 의해서 산출된 결과를 난수로 사용하며 이런 난수를 의사 난수라고 한다 
	시드가 바뀌지 않는 이상 매번 같은 패턴으로 난수가 생성되기 때문에 이를 방지하기 위해서 srand 함수 시드값 변경이 필요함
	메르센 트위스트 방식을 사용하면
	*/

	/*
	/전처리
	c언어로작성된 소스파일이 컴파일되기 이전에 소스 파일전처리에 의해서 튜닝되는 단계를 의미한다 c언어와는 다른 문법을 지니며 해당명령어는 #으로 시작된다.
	/컴파일
	컴퍼일러에 의해서 실제 컴퓨터에게 명령을 내리기위한 네이티브코드로 번역되는 단계 각 파일간에 개별적으로 수행된다.
	/링크
	컴파일이 완료된 파일을 하나로 조합해서 최종적으로 프로그램을 만들어주는 단계
	컴파일은 파일마다 수행되기때문에 결과 파일도 파일 개수만큼 생성된다.
	*/
	//g_nGValue = 100;
	//E01(argc, args);
	//E02(argc, args);
	//E03(argc, args);
	//E04(argc, args);
	//E05(argc, args);
	//E06(argc, args);
	//E07(argc, args);
	//E08(argc, args);
	E09(argc, args);
	return 0;
}