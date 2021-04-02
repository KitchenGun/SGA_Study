#include "E09.h"

#define E09_SINGLE_PTR	1
#define E09_DOUBLE_PTR	2
#define E09_FUNC_PTR	3

#if E09_SINGLE_PTR
void E09SwapByValue(int a_nValueA,int a_nValueB)
{
	int nTemp = a_nValueA;
	a_nValueA = a_nValueB;
	a_nValueB = nTemp;
}	
void E09SwapByPointer(int *a_pnValueA, int *a_pnValueB)
{
	int nTemp = *a_pnValueA;
	*a_pnValueA = *a_pnValueB;
	*a_pnValueB = nTemp;
}
void E09GetMinMaxValue(int a_nValueA, int a_nValueB, int* a_pnOutMinValue, int* a_pnOutMaxValue)
{
	*a_pnOutMinValue = (a_nValueA <= a_nValueB) ? a_nValueA : a_nValueB;
	*a_pnOutMaxValue = (a_nValueA >= a_nValueB) ? a_nValueA : a_nValueB;
}

#elif E09_DOUBLE_PTR

#elif E09_FUNC_PTR

#endif // E09_SINGLE_PTR


void E09(int argc, char ** args)
{
#if E09_SINGLE_PTR
	int nValue = 0;
	int*pnValue = &nValue;
	*pnValue = 10;
	float fValue = 0.0f;
	float *pfValue = &fValue;
	*pfValue = 3.14f;
	//%p메모리 주소 16진수 형태로 출력해줌 
	printf("포인터 조작 결과 \n");
	printf("nvalue %d %p nvalue * %p\n", nValue,&nValue, pnValue);
	printf("fvalue %f %p fvalue * %p\n", fValue,&fValue, pfValue);

	printf("\n포인터 크기\n");
	//포인터의 크기와 자료형의 크기와 전혀 상관없음 
	//32비트에서는 포인터 메모리가 4바이트로 잡힘 64비트에서는 8바이트로 잡힘
	//포인터의 위치 부터 몇 바이트를 제어하면 되는지 알려주기 위해서 포인터에 자료형이 존재함
	printf("int * %d\n", sizeof(int*));
	printf("float * %d\n", sizeof(float*));
	printf("double * %d\n", sizeof(double*));
	//void 포인터란? 주소 자체의 위치가 중요할 경우에 사용 하지만 역 참조가 불가능
	void *pvPtr = &nValue;
	pvPtr = &fValue;
	//자료형을 앞에 기입하여 형변환으로 값 변경이 가능함  사용자 정의 자료형도 가능
	*((float*)pvPtr) = 3.14f;

	int nValueA = 0;
	int nValueB = 0;

	printf("\n정수 2개 입력\n");
	scanf("%d %d", &nValueA, &nValueB);
	
	printf("값 교환전\n");
	printf("%d %d\n", nValueA, nValueB);
	/*
	c언어에서 함수 호출시 입력으로 주어지는 데이터는 해당 함수가 지니고 있는 매개변수에 복사가 이루어진다
	따라서 특정 지역에 존재하는 값을 해당함수가 제어하기 위해서는 해당 변수의 주소를 알려줘야지만 접근이 가능하다
	함수를 호출할때 주어지는 데이터를 실인자 라고 하며 해당 값을 입력으로 받는 변수를 매개변수를 형식인자라고 한다
	*/
	//E09SwapByValue(nValueA, nValueB);
	E09SwapByPointer(&nValueA, &nValueB);

	printf("값 교환후\n");
	printf("%d %d\n", nValueA, nValueB);

	int nMaxValue = 0;
	int nMinValue = 0;
	/*
	c언어는 포인터를 사용해서 특정함수로 부터 여러개의 반환값을 받을수있다.오직 1개의 값만 명시가능 
	포인터를 활용하면 우회적으로 2개 이상의 결과를 함수로 부터 받아올수있음
	*/
	E09GetMinMaxValue(nValueA, nValueB, &nMinValue, &nMaxValue);
	printf("\n최소값 %d \n", nMinValue);
	printf("\n최대값 %d \n", nMaxValue);

#elif E09_DOUBLE_PTR

#elif E09_FUNC_PTR

#endif // E09_SINGLE_PTR
}
