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
//�迭 ����
struct E09STArrayWrapper
{
	int m_anValues[5];
};
//�迭�� �ʱ�ȭ�Ѵ� ����ü
void E09InitArrayByStruct(E09STArrayWrapper a_stWrapper)
{
	const int nSize = sizeof(a_stWrapper.m_anValues) / sizeof(a_stWrapper.m_anValues[0]);
	for (int i = 0; i < nSize; ++i)
	{
		a_stWrapper.m_anValues[i] = i + 1;
	}
}
/*
Ư�� �Լ��� �Է����� ���޵� �迭�� �����ͷ� �Ѱ� �޾��� ��� �ݵ�� �ش� �迭�� ���̸� ���� �Է����� ���� �޾ƾ� �Ѵ�.
�̴� �ش� �Լ����� �Է����� ���޵� �迭�� ���̸� ����ϴ� ���� �Ұ����ϱ� �����̴�.
*/
//�迭�� �ʱ�ȭ�Ѵ� ������
void E09InitArrayByPtr(int a_pnArray[], int a_nSize)//������ �ѱ�� ������ �迭�� �� ����� �� �� ���� ���� �̴�.
{
	printf("\nũ�� %d\n", sizeof(a_pnArray));//�迭�̿��� �����ͷ� ����� ����
	for (int i = 0; i < a_nSize; ++i)
	{
		a_pnArray[i] = i + 1;
	}
}

#endif //SINGLE_PTR_A
#elif E09_DOUBLE_PTR
//������ ��ȯ�Ѵ�
void E09SwapByPtr(int **a_pnValueA, int **a_pnValueB)
{
	int *pnTemp = *a_pnValueA;
	*a_pnValueA = *a_pnValueB;
	*a_pnValueB = pnTemp;
}
#elif E09_FUNC_PTR
//������
typedef void(*func_ptr_t)(void);

//�Լ� a
void E09FuncA(void)
{
	printf("\na\n");
}
//�Լ� b
void E09FuncB(void)
{
	printf("\nb\n");
}
//�Լ� c
func_ptr_t E09FuncC(int a_nFuncType)
{
	return (a_nFuncType <= 0) ? E09FuncA : E09FuncB;
}

//������������ ���Ѵ�
int E09CompareByAscending(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//������������ ���Ѵ�
int E09CompareByDescending(int a_nLhs, int a_nRhs)
{
	return a_nRhs - a_nLhs;
}
//���� �����Ѵ�
void E09SortValues(int *a_pnValues, int a_nSize, int(*a_pfnCompare)(int, int))
{
	for (int i = 0; i < a_nSize - 1; i++)
	{
		int nCompareIdx = i;
		for (int j = i + 1; j < a_nSize; j++)
		{
			//����ȯ�� �ʿ��Ѱ��
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
	//%p�޸� �ּ� 16���� ���·� ������� 
	printf("������ ���� ��� \n");
	printf("nvalue %d %p nvalue * %p\n", nValue, &nValue, pnValue);
	printf("fvalue %f %p fvalue * %p\n", fValue, &fValue, pfValue);

	printf("\n������ ũ��\n");
	//�������� ũ��� �ڷ����� ũ��� ���� ������� 
	//32��Ʈ������ ������ �޸𸮰� 4����Ʈ�� ���� 64��Ʈ������ 8����Ʈ�� ����
	//�������� ��ġ ���� �� ����Ʈ�� �����ϸ� �Ǵ��� �˷��ֱ� ���ؼ� �����Ϳ� �ڷ����� ������
	printf("int * %d\n", sizeof(int*));
	printf("float * %d\n", sizeof(float*));
	printf("double * %d\n", sizeof(double*));
	//void �����Ͷ�? �ּ� ��ü�� ��ġ�� �߿��� ��쿡 ��� ������ �� ������ �Ұ���
	void *pvPtr = &nValue;
	pvPtr = &fValue;
	//�ڷ����� �տ� �����Ͽ� ����ȯ���� �� ������ ������  ����� ���� �ڷ����� ����
	*((float*)pvPtr) = 3.14f;

	int nValueA = 0;
	int nValueB = 0;

	printf("\n���� 2�� �Է�\n");
	scanf("%d %d", &nValueA, &nValueB);

	printf("�� ��ȯ��\n");
	printf("%d %d\n", nValueA, nValueB);
	/*
	c���� �Լ� ȣ��� �Է����� �־����� �����ʹ� �ش� �Լ��� ���ϰ� �ִ� �Ű������� ���簡 �̷������
	���� Ư�� ������ �����ϴ� ���� �ش��Լ��� �����ϱ� ���ؼ��� �ش� ������ �ּҸ� �˷�������� ������ �����ϴ�
	�Լ��� ȣ���Ҷ� �־����� �����͸� ������ ��� �ϸ� �ش� ���� �Է����� �޴� ������ �Ű������� �������ڶ�� �Ѵ�
	*/
	//E09SwapByValue(nValueA, nValueB);
	E09SwapByPointer(&nValueA, &nValueB);

	printf("�� ��ȯ��\n");
	printf("%d %d\n", nValueA, nValueB);

	int nMaxValue = 0;
	int nMinValue = 0;
	/*
	c���� �����͸� ����ؼ� Ư���Լ��� ���� �������� ��ȯ���� �������ִ�.���� 1���� ���� ��ð���
	�����͸� Ȱ���ϸ� ��ȸ������ 2�� �̻��� ����� �Լ��� ���� �޾ƿü�����
	*/
	E09GetMinMaxValue(nValueA, nValueB, &nMinValue, &nMaxValue);
	printf("\n�ּҰ� %d \n", nMinValue);
	printf("\n�ִ밪 %d \n", nMaxValue);

	//c��� ������ ����� ����
	/*
	const int *pnConstPtrA = &nValueA;			�����͸� ���� ���� ������ ����
	int *const pnConstPtrB = &nValueB;			������ ��ü�� ���ȭ
	const int* const pnConstPtrC = &nValueA;	1+2 �������
	*/
	const int *pnConstPtrA = &nValueA;//�����͸� ���� ���� ������ ������� ����
	int *const pnConstPtrB = &nValueB; //�迭�� ������ Ư¡�� ������ ����
	const int* const pnConstPtrC = &nValueA;
	//1 �ٸ� �޸𸮸� ����Ű�� ���� �����ϴ� ������ ���� �����Ҽ�����
	//*pnConstPtrA = 10;
	pnConstPtrA = &nValueB;

	//2 �ٸ� �޸� ����Ű�°� �Ұ��� �����͸� ���� ���� ������ ����Ѵ�.
	*pnConstPtrB = 20;
	//pnConstPtrB = &nValueA;
	//3
	//�Ѵ� �ȵ�
#elif SINGLE_PTR_B
	int anValuesA[5] = { 1,2,3,4,5 };
	int anValuesB[5] = { 1,2,3,4,5 };
	const int nSizeA = sizeof(anValuesA) / sizeof(anValuesA[0]);
	const int nSizeB = sizeof(anValuesB) / sizeof(anValuesB[0]);
	
	printf("\n===�迭A�� ��� %d ===\n",sizeof(anValuesA));
	/*
	������ �����̶� c����� �����ʹ� �ּҿ� Ư�� ���� ���ϰų� ���� ������ �����ϸ� �̸� ������ �����̶�� �Ѵ�. 
	������ Ư������ ���Ѵٴ� ���� �Ϲ����� ���� ������ �ƴ϶� ������ �ǹ��Ѵ�
	�ּ��� Ư������ ���ϴ� ���� �ش� ���ݸ�ŭ �ǳ� ������ �ǹ��̴�.
	������ ������ ����� �ش� �������� �ڷ������� �ٸ��� ������ �ǹ̴� �ش� ������ �ڷ����� ũ�⸦ �ǹ��Ѵ� 
	�� char ���� 1���� == 1byte int �� 1���� == 4byte �̴�.
	*/
	for (int i = 0; i < nSizeA; i++)
	{
		printf("%d ", *(anValuesA+i));
	}

	int *pnValues = anValuesB;
	printf("\n===�迭B�� ��� %d===\n",sizeof(pnValues));

	for (int i = 0; i < nSizeB; i++)
	{
		printf("%d ", pnValues[i]);
	} 
	/*
	�迭�� �̸��� ������ ����� �ι�° ������ ������ Ư¡�� ���ϰ� �ֱ� ������ Ư���迭�� �����ͷ� ������ ������
	�� �迭�� ũ�⸦ ���ϸ� �迭�� ��� ���*��Ұ��� ��ŭ�� �޸𸮸� �����ϰ� ������ ��� ��Ҹ�ŭ�� �޸𸮸� ������ �ִ�
	�׷��� �Լ��� �Է��� �����ϱ� ���ؼ��� �ݵ�� �ش� �迭�� ũ�⸦ ���� �Ѱ�����Ѵ�.
	�迭��ü�� �Լ��� �Է����� �����ϰ� ������ ����ü�� ���� �迭�� Ư���Լ��� ���� ���ؼ��� ������ ����ؾ��Ѵ�.
	*/

	E09STArrayWrapper stArrayWrapper = {0};
	E09InitArrayByStruct(stArrayWrapper);
	int anValuesC[5] = { 0 };
	const int nSizeC = sizeof(anValuesC) / sizeof(anValuesC[0]);
	E09InitArrayByPtr(anValuesC, nSizeC);
	printf("\n����ü�� ����� �迭 �ʱ�ȭ\n");
	for (int i = 0; i < nSizeC; ++i)
	{
		printf("%d ", stArrayWrapper.m_anValues[i]);
	}
	printf("\n�����͸� ����� �迭 �ʱ�ȭ\n");
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

	printf("������ ���� ��� \n");
	printf("valueA : %d %p \n", nValueA, &nValueA);
	printf("valueB : %d %p \n", nValueB, &nValueB);
	printf("int* %p %p int** %p", pnValue, &pnValue, pnDoublePtr);

	nValueA = 10;
	nValueB = 20;

	int *pnValueA = &nValueA;
	int *pnValueB = &nValueB;

	printf("������ ��ȯ��\n");
	printf("%d, %d\n", *pnValueA, *pnValueB);
	/*
	���α׷��� ���� �Լ��� ȣ���� 2���� �������� ����
	1. Call by Value		���� ���� ȣ��
	2. Call by Reference	������ ���� ȣ��

	�� �� ���� ������ ����� ���� ȣ��� �Լ����� �ش� �Լ��� ���� ������ �°� ������ �����Ҽ��ִٸ� �̸� CallbyReference��� �Ѵ�
	�� �Լ��� �Է����� �ּҸ� �Է����� �Ѱ�� �ϴ��� �Լ��� ���� ������ �޼��Ҽ����ٸ� �̴� CallbyReference�� �ƴϴ�.
	*/
	E09SwapByPtr(&pnValueA,&pnValueB);
	printf("������ ��ȯ��\n");
	printf("%d, %d\n", *pnValueA, *pnValueB);
	printf("������ ��ȯ��\n");
	printf("value a %d, value b %d\n", nValueA, nValueB);

#elif E09_FUNC_PTR
	printf("E09 %p", E09);//�Լ��� �̸��� �ּҰ� �ִ�
	//��ȯ�� �������Լ��̸� �Է�
	

	//void (*pfnFunc)(void) = E09FuncA;
	//������ ���� ���� �ڵ����� �ڷ����� �������ش�
	auto pfnFunc = E09FuncA;
	
	
	pfnFunc();
	pfnFunc = E09FuncB;
	pfnFunc();
	/*int nFuncType = 0;
	printf("�Լ� Ÿ��(0 or 1)�Է� :");
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
	printf("������\n");
	for (int i = 0; i < nSize; i++)
	{
		printf("%d ", anValues[i]);

	}
	E09SortValues(anValues, nSize, E09CompareByAscending);
	printf("\n�������� ��\n");
	for (int i = 0; i < nSize; ++i)
	{
		printf("%d ", anValues[i]);

	}
	E09SortValues(anValues, nSize, E09CompareByDescending);
	printf("\n�������� ��\n");
	for (int i = 0; i < nSize; ++i)
	{
		printf("%d ", anValues[i]);

	}

#endif // E09_SINGLE_PTR
}
