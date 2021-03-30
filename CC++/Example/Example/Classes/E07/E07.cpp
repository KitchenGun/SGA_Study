#include "E07.h"
//#include는 헤더 파일 내용을 전부 복사
//#define E07_FUNC_A		1
//#define E07_FUNC_B		2
#define E07_FUNC_C		3


#if E07_FUNC_A
//! 덧셈 결과를 반환한다
int E07GetSumValue(int a_nLhs, int a_nRhs)//a = 전달값이라는 의미 nLhs 좌항  nRhs 우항
{
	/*
	return 키워드는 함수의 흐름을 종료하고 해당함수를 호출한 곳으로 되돌아가는 역할을 수행한다 또한 해당 함수가 반환 값이 존재 할 경우 해당 키워드에 
	명시된 결과 값을 호출한 곳으로 반환한다.
	void 일 경우 
	return;
	*/
	return a_nLhs + a_nRhs;
}
//! 뺄셈 결과를 반환한다
int E07GetSubValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//! 곱셈 결과를 반환한다
int E07GetMultiplyValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs * a_nRhs;
}
//! 나누셈 결과를 반환한다
float E07GetDivideValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs / (float)a_nRhs;
}
#elif E07_FUNC_B
static int g_nGValue = 0;

void E07IncrValue(int a_nValue)
{
	static int nLValue=0;
	//지역변수는 해당함수에서만 접근가능함 해당지역 종료시 메모리에서 사라짐 값누적 X
	g_nGValue += a_nValue;
	nLValue += a_nValue;
	printf("누적 결과\n");
	printf("지역  %d\n", nLValue);
	printf("전역  %d\n", g_nGValue);
}
#elif E07_FUNC_C
//팩토리얼 값을 반환 3! = 3*2*1
int E07GetFactorial(int a_nValue)
{
	//꼬리 재귀일 경우
	if (a_nValue <= 1)
	{
		return 1;
	}
	return a_nValue * E07GetFactorial(a_nValue - 1);
}

#endif //#if E07_FUNC_A

void E07(int argc, char ** args)
{
#if E07_FUNC_A
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null 문자 문자형 변수 초기화용

	printf("수식입력 + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		int nResult = E07GetSumValue(nValueA, nValueB);
		printf("%d + %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '-')
	{
		int nResult = E07GetSubValue(nValueA, nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '*')
	{
		int nResult = E07GetMultiplyValue(nValueA, nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '/')
	{
		float fResult = E07GetDivideValue(nValueA, nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, fResult);
	}
	else
	{
		printf("잘못된 수식을 입력하였습니다.");
	}
#elif E07_FUNC_B
	//전역변수
	//값 증가
	int nValue = 0;
	//g_nGValue = 0; 
	//전역변수라서 프로그램 어디서든지 접근이 가능함
	do
	{
		printf("정수 입력");
		printf("\n");
		scanf("%d", &nValue);
		E07IncrValue(nValue);
		printf("\n");

	} while (nValue!=0);
#elif E07_FUNC_C
	/*printf("난수 최대값 %d\n", RAND_MAX);
	std::random_device oRandom;//하드웨어에 의존한 시드값을 기반으로 함
	
	for (int i = 0; i < 10; i++)
	{
		//printf("%d\n",rand()%100);
		printf("%d\n", oRandom() % 100);
	}*/

	int nValue = 0;
	{
		//c/c++ 영역이 다르면 같은 이름 변수 선언가능 최대한 가까운 영역의 변수가 우선순위가 높음
		int nValue = 0;
		nValue = 100;
	}
	

	printf("정수 입력\n");
	scanf("%d",&nValue);
	int nResult = E07GetFactorial(nValue);
	printf("%d! = %d\n", nValue, nResult);
#endif // E07_FUNC_A

}
