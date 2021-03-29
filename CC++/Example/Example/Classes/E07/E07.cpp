#include "E07.h"
//#include는 헤더 파일 내용을 전부 복사
//#define P07_FUNC_A		1
#define P07_FUNC_B		2
#define P07_FUNC_C		3


#if P07_FUNC_A
//! 덧셈 결과를 반환한다
int P07GetSumValue(int a_nLhs, int a_nRhs)//a = 전달값이라는 의미 nLhs 좌항  nRhs 우항
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
int P07GetSubValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//! 곱셈 결과를 반환한다
int P07GetMultiplyValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs * a_nRhs;
}
//! 나누셈 결과를 반환한다
float P07GetDivideValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs / (float)a_nRhs;
}
#elif P07_FUNC_B

#endif //#if P07_FUNC_A

void E07(int argc, char ** args)
{
#if P07_FUNC_A
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null 문자 문자형 변수 초기화용

	printf("수식입력 + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		int nResult = P07GetSumValue(nValueA, nValueB);
		printf("%d + %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '-')
	{
		int nResult = P07GetSubValue(nValueA, nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '*')
	{
		int nResult = P07GetMultiplyValue(nValueA, nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '/')
	{
		float fResult = P07GetDivideValue(nValueA, nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, fResult);
	}
	else
	{
		printf("잘못된 수식을 입력하였습니다.");
	}
#elif P07_FUNC_B
#elif P07_FUNC_C
#endif // P07_FUNC_A

}
