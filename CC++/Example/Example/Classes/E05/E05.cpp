#include "E05.h"

//#define E05_WHILE		1
#define E05_FOR			2	
//#define E05_DO_WHILE	3

void E05(int argc, char ** args)
{
	//반복문이란
	/*
		주어진 조건을 만족할동안 실행하는 기능을 의미 한다

		반복문 종류
		-while
		-for
		-do~while
	ex)
	while(조건식)
	{
	조건 만족할때까지 실행
	}
	
	for(초기절;조건절;반복절)
	{
	조건 만족할때까지 실행
	}

	do
	{
	실행먼저 하고 조건과 비교
	}
	while(조건식)
	*/
#if E05_WHILE
	int i = 0;
	int nTimes = 0;
	printf("반복 횟수입력\n");
	scanf("%d", &nTimes);
	/*
		반복문의 조건을 깰수 없어서 특정 구문을 무한으로 실행하는 반복문을 무한 루프라고 한다.
	*/
	while (i < nTimes)
	{
		printf("%d, ", ++i);
	}

	while (1)
	{
		if (i > 5)
		{
			break;
			// 반복문 내부 break를 명시했을 경우 현재 반복문을 중단ㄴ하고 반복문 밖으로 프로그램의 흐름 이동 가능
		}
	}

	printf("\n");
#elif E05_FOR
	int nTimes = 0;
	printf("for 반복 횟수입력\n");
	scanf("%d", &nTimes);

	for (int i = 0; i < nTimes; ++i)
	{//숫자를 비교할때는 for문을 사용하는 것이 좋음
		//짝수 일 경우
		if ((i + 1) % 2 == 0)
		{
			continue;
		}
		printf("%d, ", i + 1);
	}

	printf("\n");
	
	int i = 0;
	nTimes = 0;
	printf("while 반복 횟수입력\n");
	scanf("%d", &nTimes);

	while (i < nTimes)
	{//상태비교에 많이 쓰임
		//짝수 일 경우
		if ((i + 1) % 2 == 0)
		{
			i++;
			continue;
			//의미 = 다음흐름으로 넘어가라  반복문 안에서만 사용간
			//조건을 깨기 위한 구문이 실행되었는지 확인하고 continue를 명시해야함
			//for 반복문 내부에서 해당 키워드를 명시했을 경우 다음 흐름인 반복절로 이동하기때문에 
			//while문에 비해서 continue키워드 사용에 따른 위험이 적다
		}
		printf("%d, ", i+1);
		i++;
	}

	printf("\n");
#elif E05_DO_WHILE
	int i = 0;
	int nTimes = 0;
	printf("반복 횟수입력\n");
	scanf("%d", &nTimes);
	/*
	while for 문은 사전 판단 조건 먼저 체크하고 실행여부결정
	do~while  문은 사후판단 반복문 조건과 관계없이 무조건 한번 실행
	*/
	do
	{
		printf("%d, ", ++i);
	} while (i<nTimes);

	printf("\n");
#endif
}
