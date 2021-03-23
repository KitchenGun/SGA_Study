#include "E03.h"

/*
연산자란?
데이터를 가공하기 위한 특수한 의미를 지니는 기호를 연산자
연산자를 사용하면 특정 데이터를 프로그램의 목적에 맞게 제어하는 것이 가능하다

C언어 연산자의 종류
산술연산
+-/%*
할당연산자
= += -= *=
비교 연산자
== >= <= != < >
논리 연산자
&& || !
증감 연산자
++ --
비트연산자
& | ^(익스쿨르시브 0,0->true 1,1 -> fales) ~(비트 부정 0->1 1->0) >>(shift 연산자) <<()
조건 연산자 
? :
*/

void E03(int argc, char **args)
{
	int nValueA=0;
	int nValueB=0;
	//0은 거짓 나머지수는 참이다
	printf("정수(2개 입력) : ");
	scanf("%d %d", &nValueA, &nValueB);
	printf("결과\n");
	printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
	printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
	printf("비교연산자\n");
	printf("%d != %d =%d\n", nValueA, nValueB, nValueA != nValueB);
	printf("%d == %d =%d\n", nValueA, nValueB, nValueA == nValueB);
	printf("%d >= %d =%d\n", nValueA, nValueB, nValueA >= nValueB);
	printf("%d <= %d =%d\n", nValueA, nValueB, nValueA <= nValueB);
	printf("%d > %d =%d\n", nValueA, nValueB, nValueA > nValueB);
	printf("%d < %d =%d\n", nValueA, nValueB, nValueA < nValueB);
	printf("논리연산자\n");
	printf("%d && %d =%d\n", nValueA, nValueB, nValueA && nValueB);
	printf("%d || %d =%d\n", nValueA, nValueB, nValueA || nValueB);
	printf("!%d =%d\n", nValueA,!nValueA);
	printf("증감연산자\n");//앞 또는 뒤에 명시 가능
	printf("++%d --%d\n", ++nValueA, --nValueB);//전의 증감 선 증감 후 연산 
	printf("%d++ %d--\n", nValueA++, nValueB--);//후위 증감 선 연산 후 증감
	printf("증감 연산 결과 %d %d\n", nValueA, nValueB);
	/*
	%x 16진수를 값으로 출력하기 위한 서식문자이다 대문자로 서식문자를 작성하면 출력이 대문자로 나온다
	*/
	printf("비트연산자\n");
	printf("%x & %x =%x\n", nValueA, nValueB, nValueA & nValueB);
	printf("%x | %x =%x\n", nValueA, nValueB, nValueA | nValueB);
	printf("%x ^ %x =%x\n", nValueA, nValueB, nValueA ^ nValueB);//두개가 다르면 참 같으면 거짓  0010 1000 -> 1010
	printf("~%x = %d\n", nValueA, ~nValueA +1);// 2의 보수법을 통해서 음수를 표현함 비트 반전 +1
	printf("%x << 2 =%x\n", nValueA, nValueA << 2);//0은 걍 0으로 나옴
	printf("%x >> 2 =%x\n", nValueB, nValueB >> 2);
	printf("조건연산자\n");//삼항 연산자
	printf("(%d < %d) ? : = %d\n", nValueA, nValueB, nValueA < nValueB ? nValueA : nValueB);
	printf("할당 연산자\n");
	nValueA += 5;
}