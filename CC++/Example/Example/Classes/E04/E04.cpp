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

void E04(int argc, char ** args)
{
	int nValueA = 0;
	int nValueB = 0;
	//0은 거짓 나머지수는 참이다
	printf("정수(2개 입력) : ");
	scanf("%d %d", &nValueA, &nValueB);

	if (nValueB == 0)
	{
		printf("b의 값을 0으로 입력할 수 없습니다.\n");
	}
	else
	{
		printf("결과\n");
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
		printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
	}
}
