#include "E04.h"

//조건문 = 특정 조건에 따라 프로그램 여러 흐름중 하나를 실행 할수있게 만드는 기능

/*
조건문의 종류 
if ~ else
ex)
if(조건a)
{
}
else if(조건b)
{
}
else
{
}
switch ~ case
switch()
{
case:
}

*/

//#define E04_IF_ELSE		1	
#define E04_SWITCH_CASE 2

void E04(int argc, char ** args)
{/*
 #if~ #endif 는 전처리기에 의해 처리되는 조건문이다. 
컴파일 되기전에 해당구문이 처리되기 때문에 특정코드를 활성/비활성화 가능

해당 조건문은 c의 조건문과 달리 중괄호 연산자를 통해서 영역을 구분하는 것이 불가능하기 때문에 #if 명령어로 시작했으면 받드시 #endif로 영역 구분이 필요하다
*/
#if E04_IF_ELSE
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null 문자 문자형 변수 초기화용

	printf("수식입력 + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	}
	else if (chOperator == '-')
	{
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	}
	else if (chOperator == '*')
	{
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	}
	else if (chOperator == '/')
	{
		printf("%d / %d = %d\n", nValueA, nValueB, nValueA / nValueB);
	}
	else
	{
		printf("잘못된 수식을 입력하였습니다.");
	}
#elif E04_SWITCH_CASE
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null 문자 문자형 변수 초기화용

	printf("수식입력 + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	//오로지 정수로 제한됨  정의 = 흐름을 여기서 부터 시작한다 break를 사용하여서 흐름을 짜르는거임
	//원래 내부에서 변수 선언 불가능 중괄호가 있으면 변수 선언이 가능함
	//범위 비교 불가능 
	//실수비교 방법
	{
		float fValue = 10.0f;
		//엔진에서는 함수가 있음 
		if (fValue >= 9.0f - FLT_EPSILON && fValue <= 15.0f + FLT_EPSILON)
		{
			printf("실수 범위 연산");
		}
	}


	switch (chOperator)
	{
	case'+':
	{
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	}
	break;
	case'-':
	{
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	}
	break;
	case'*':
	{
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	}
	break;
	case'/':
	{
		printf("%d / %d = %d\n", nValueA, nValueB, nValueA / nValueB);
	}
	break;
	default:
	{
		printf("잘못된 수식을 입력하였습니다.");
	}
	break;
	}

#endif//if E04_IF_ELSE

	/*
	퍼포먼스적으로 if else가 switch case 보다 더 빠름
	명확한 동등비교에서 유리함 코드가 깔끔함
	팀의 분위기에 맞춰야한다
	*/
}
