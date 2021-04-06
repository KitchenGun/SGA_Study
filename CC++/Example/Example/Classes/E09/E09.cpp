#include "E09.h"

//#define E09_SINGLE_PTR	1
//#define E09_DOUBLE_PTR	2
#define E09_FUNC_PTR	3

#if E09_SINGLE_PTR
//#define SINGLE_PTR_A	1
#define SINGLE_PTR_B	2
#endif //#if E09_SINGLE_PTR


#if E09_SINGLE_PTR
#if SINGLE_PTR_A
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
#elif SINGLE_PTR_B
//배열 랩퍼
struct E09STArrayWrapper
{
	int m_anValues[5];
};
//배열을 초기화한다 구조체
void E09InitArrayByStruct(E09STArrayWrapper a_stWrapper)
{
	const int nSize = sizeof(a_stWrapper.m_anValues) / sizeof(a_stWrapper.m_anValues[0]);
	for (int i = 0; i < nSize; ++i)
	{
		a_stWrapper.m_anValues[i] = i + 1;
	}
}
/*
특정 함수에 입력으로 전달된 배열을 포인터로 넘겨 받았을 경우 반드시 해당 배열의 길이를 같이 입력으로 전달 받아야 한다.
이는 해당 함수에서 입력으로 전달됨 배열의 길이를 계산하는 것이 불가능하기 때문이다.
*/
//배열을 초기화한다 포인터
void E09InitArrayByPtr(int a_pnArray[], int a_nSize)//사이즈 넘기는 이유는 배열의 총 사이즈를 알 수 없기 때문 이다.
{
	printf("\n크기 %d\n", sizeof(a_pnArray));//배열이여도 포인터로 사이즈가 나옴
	for (int i = 0; i < a_nSize; ++i)
	{
		a_pnArray[i] = i + 1;
	}
}

#endif //SINGLE_PTR_A
#elif E09_DOUBLE_PTR
//포인터 교환한다
void E09SwapByPtr(int **a_pnValueA, int **a_pnValueB)
{
	int *pnTemp = *a_pnValueA;
	*a_pnValueA = *a_pnValueB;
	*a_pnValueB = pnTemp;
}
#elif E09_FUNC_PTR
//재정의
typedef void(*func_ptr_t)(void);

//함수 a
void E09FuncA(void)
{
	printf("\na\n");
}
//함수 b
void E09FuncB(void)
{
	printf("\nb\n");
}
//함수 c
func_ptr_t E09FuncC(int a_nFuncType)
{
	return (a_nFuncType <= 0) ? E09FuncA : E09FuncB;
}

//오름차순으로 비교한다
int E09CompareByAscending(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//내림차순으로 비교한다
int E09CompareByDescending(int a_nLhs, int a_nRhs)
{
	return a_nRhs - a_nLhs;
}
//값을 정렬한다
void E09SortValues(int *a_pnValues, int a_nSize, int(*a_pfnCompare)(int, int))
{
	for (int i = 0; i < a_nSize - 1; i++)
	{
		int nCompareIdx = i;
		for (int j = i + 1; j < a_nSize; j++)
		{
			//값교환이 필요한경우
			if (a_pfnCompare(a_pnValues[nCompareIdx], a_pnValues[j]) > 0)
			{
				nCompareIdx = j;
			}
		}

		int nTemp = a_pnValues[i];
		a_pnValues[i] = a_pnValues[nCompareIdx];
		a_pnValues[nCompareIdx] = nTemp;
	}
}
#endif // E09_SINGLE_PTR


void E09(int argc, char ** args)
{
#if E09_SINGLE_PTR
#if SINGLE_PTR_A
	int nValue = 0;
	int*pnValue = &nValue;
	*pnValue = 10;
	float fValue = 0.0f;
	float *pfValue = &fValue;
	*pfValue = 3.14f;
	//%p메모리 주소 16진수 형태로 출력해줌 
	printf("포인터 조작 결과 \n");
	printf("nvalue %d %p nvalue * %p\n", nValue, &nValue, pnValue);
	printf("fvalue %f %p fvalue * %p\n", fValue, &fValue, pfValue);

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

	//c언어 포인터 상수의 종류
	/*
	const int *pnConstPtrA = &nValueA;			포인터를 통한 값의 조작을 금지
	int *const pnConstPtrB = &nValueB;			포인터 자체를 상수화
	const int* const pnConstPtrC = &nValueA;	1+2 유형상수
	*/
	const int *pnConstPtrA = &nValueA;//포인터를 통한 값의 조작을 허용하지 않음
	int *const pnConstPtrB = &nValueB; //배열과 유사한 특징을 가지고 있음
	const int* const pnConstPtrC = &nValueA;
	//1 다른 메모리를 가리키는 것이 가능하다 하지만 값을 변경할수없다
	//*pnConstPtrA = 10;
	pnConstPtrA = &nValueB;

	//2 다른 메모리 가리키는것 불가능 포인터를 통한 값의 조작은 허용한다.
	*pnConstPtrB = 20;
	//pnConstPtrB = &nValueA;
	//3
	//둘다 안됨
#elif SINGLE_PTR_B
	int anValuesA[5] = { 1,2,3,4,5 };
	int anValuesB[5] = { 1,2,3,4,5 };
	const int nSizeA = sizeof(anValuesA) / sizeof(anValuesA[0]);
	const int nSizeB = sizeof(anValuesB) / sizeof(anValuesB[0]);
	
	printf("\n===배열A의 요소 %d ===\n",sizeof(anValuesA));
	/*
	포인터 연산이란 c언어의 포인터는 주소에 특정 값을 더하거나 빼는 행위가 가능하며 이를 포인터 연산이라고 한다. 
	포인터 특정값을 더한다는 것은 일반적인 수의 덧셈이 아니라 간격을 의미한다
	주소의 특정값을 더하는 것은 해당 간격만큼 건너 띄어라라는 의미이다.
	포인터 연산의 결과는 해당 포인터의 자료형마다 다르며 간격의 의미는 해당 포인터 자료형의 크기를 의미한다 
	즉 char 형은 1간격 == 1byte int 형 1간격 == 4byte 이다.
	*/
	for (int i = 0; i < nSizeA; i++)
	{
		printf("%d ", *(anValuesA+i));
	}

	int *pnValues = anValuesB;
	printf("\n===배열B의 요소 %d===\n",sizeof(pnValues));

	for (int i = 0; i < nSizeB; i++)
	{
		printf("%d ", pnValues[i]);
	} 
	/*
	배열의 이름은 포인터 상수의 두번째 유형과 유사한 특징을 지니고 있기 때문에 특정배열을 포인터로 조작이 가능함
	단 배열의 크기를 비교하면 배열의 경우 요소*요소개수 만큼의 메모리를 차지하고 포인터 경우 요소만큼의 메모리를 가지고 있다
	그래서 함수에 입력을 전달하기 위해서는 반드시 해당 배열의 크기를 같이 넘겨줘야한다.
	배열자체를 함수의 입력으로 온전하게 전달은 구조체만 가능 배열의 특정함수에 전달 위해서는 포인터 사용해야한다.
	*/

	E09STArrayWrapper stArrayWrapper = {0};
	E09InitArrayByStruct(stArrayWrapper);
	int anValuesC[5] = { 0 };
	const int nSizeC = sizeof(anValuesC) / sizeof(anValuesC[0]);
	E09InitArrayByPtr(anValuesC, nSizeC);
	printf("\n구조체를 사용한 배열 초기화\n");
	for (int i = 0; i < nSizeC; ++i)
	{
		printf("%d ", stArrayWrapper.m_anValues[i]);
	}
	printf("\n포인터를 사용한 배열 초기화\n");
	for (int i = 0; i < nSizeC; ++i)
	{
		printf("%d ", anValuesC[i]);
	}

	
	int nValueA = 0;
	int nValueB = 0;

	int *pnValueA = &nValueA;
	int *pnValueB = &nValueB;
	*pnValueA = 10;
	*pnValueB = 20;

	printf("%d %d", nValueA, nValueB);

#endif // SINGLE_PTR_A
#elif E09_DOUBLE_PTR

	int nValueA = 0;
	int nValueB = 0;
	
	int *pnValue = &nValueA;
	
	int **pnDoublePtr = &pnValue;
	
	**pnDoublePtr = 10;
	*pnDoublePtr = &nValueB;
	**pnDoublePtr = 20;
	*pnValue = 30;

	printf("포인터 조작 결과 \n");
	printf("valueA : %d %p \n", nValueA, &nValueA);
	printf("valueB : %d %p \n", nValueB, &nValueB);
	printf("int* %p %p int** %p", pnValue, &pnValue, pnDoublePtr);

	nValueA = 10;
	nValueB = 20;

	int *pnValueA = &nValueA;
	int *pnValueB = &nValueB;

	printf("포인터 교환전\n");
	printf("%d, %d\n", *pnValueA, *pnValueB);
	/*
	프로그래밍 언어에서 함수의 호출은 2가지 유형으로 구분
	1. Call by Value		값에 의한 호출
	2. Call by Reference	참조에 의한 호출

	이 두 유형 구분은 상대적 개념 호출된 함수에서 해당 함수의 제작 목적에 맞게 원본을 수정할수있다면 이를 CallbyReference라고 한다
	즉 함수의 입력으로 주소를 입력으로 넘겼다 하더라도 함수의 제작 목적을 달성할수없다면 이는 CallbyReference가 아니다.
	*/
	E09SwapByPtr(&pnValueA,&pnValueB);
	printf("포인터 교환후\n");
	printf("%d, %d\n", *pnValueA, *pnValueB);
	printf("포인터 교환후\n");
	printf("value a %d, value b %d\n", nValueA, nValueB);

#elif E09_FUNC_PTR
	printf("E09 %p", E09);//함수의 이름에 주소가 있다
	//반환값 포인터함수이름 입력
	

	//void (*pfnFunc)(void) = E09FuncA;
	//우항의 값에 따라서 자동으로 자료형을 지정해준다
	auto pfnFunc = E09FuncA;
	
	
	pfnFunc();
	pfnFunc = E09FuncB;
	pfnFunc();
	/*int nFuncType = 0;
	printf("함수 타입(0 or 1)입력 :");
	scanf("%d", &nFuncType);
	
	void(*pfnFunc)(void) = E09FuncC(nFuncType);
	pfnFunc();
	*/
	int anValues[10] = { 0 };
	const int nSize = sizeof(anValues) / sizeof(anValues[0]);
	for (int i = 0; i < nSize; i++)
	{
		anValues[i] = rand() % 100;
	}
	printf("정렬전\n");
	for (int i = 0; i < nSize; i++)
	{
		printf("%d ", anValues[i]);

	}
	E09SortValues(anValues, nSize, E09CompareByAscending);
	printf("\n오름차순 후\n");
	for (int i = 0; i < nSize; ++i)
	{
		printf("%d ", anValues[i]);

	}
	E09SortValues(anValues, nSize, E09CompareByDescending);
	printf("\n내림차순 후\n");
	for (int i = 0; i < nSize; ++i)
	{
		printf("%d ", anValues[i]);

	}

#endif // E09_SINGLE_PTR
}
