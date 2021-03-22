#include "E02.h"

/*
#define 명령어를 사용하면 전처리기에 의해서 처리되는 상수 선언 가능
해당기능을 통해서 생성된 상수를 매크로 상수라고함  컴파일러 입장에서 리터럴 상수
*/
//#define E02_VARIABLE			1
#define E02_DATA_INPUT_OUTPUT	2


void E02(int argc, char ** args)
{
#if E02_VARIABLE
	/*
	자료형 + 변수이름을 통해서 변수를 선언하고 필요시 값을 지정이 가능함 이 행위를 변수의 초기화라고함
	c언어 변수 이름 작성 규칙
	기본적으로 변수의 이름은 알파벳(대/소문자),숫자,_(언더 스코어)의 조합을 통해서 작성이 가능하며 첫글자에는 숫자사용이 불가능하다.
	c컴파일러는 대소문자 구별 가능
	ex)
	int a;
	int A;
	c컴파일러는 해당 변수를 서로 다른 변수로 인식한다
	변수이름은 중복 허용 X
	*/

	short nShort = 10;
	int nInt = 20;
	long nLong = 30;
	long long nLongLong = 40;
	float fFloat = 3.14f;
	double dblDouble = 3.14;
	char chLetter = 'A';
	/*
	printf 함수는 서식 문자를 활용해서 특정 데이터를 출력하는 것이 가능하다
	
	printf 함수 서식 문자의 종류
	//정수
	%d		==short,int
	%ld		==long
	%lld	==long long
	//실수
	%f		==float
	%lf		==double
	//문자형
	%c		==char
	//서식문자를 명시할때는 반드시 치환시킬 데이터의 자료형에 맞춰서 서식문자를 명시해줘야한다

	*/



	printf("정수형 출력\n");
	printf("short %d:%d\n", sizeof(nShort), nShort);
	printf("int %d:%d\n", sizeof(nInt), nInt);
	printf("long %d:%ld\n", sizeof(nLong), nLong);
	printf("long long %d:%lld\n", sizeof(nLongLong), nLongLong);
	printf("실수형 출력\n");
	printf("float %d:%f\n", sizeof(fFloat), fFloat);
	printf("double %d:%lf\n", sizeof(dblDouble), dblDouble);
	printf("문자형 출력\n");
	printf("char %d:%c\n", sizeof(chLetter), chLetter);

#elif E02_DATA_INPUT_OUTPUT
	int nValueA = 0;
	int nValueB = 0;
	printf("정수(2개 입력) : ");
	scanf("%d %d", &nValueA, &nValueB);
	//scanf는 서식문자와 공백만 사용이 가능하고 읽을 데이터의 형식에 맞춰서 선언 필요  scanf는 독자함수기때문에 주소값을 받아야한다
	//해더에서 정의 하면 다른 컴파일러에서도 scanf 사용가능 scanf_s는 비주얼 스튜디오 컴파일러에서만 사용가능하다	
	printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
	//피연산자를 2개이상요구하는 경우 이항 연산자를 사용했을 경우 피연산자의 자료형이 일치해야한다
	//행변환은 해석 방법을 바꾼다 하나만 바꿔도 암묵적인 형변환(묵시적형변환) 발생 값에 손실이 덜 발생하는 방향으로 진행됨
	printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
#endif // E02_VARIABLE
}
