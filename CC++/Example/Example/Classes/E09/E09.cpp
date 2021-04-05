#include "E09.h"

#define E09_SINGLE_PTR	1
#define E09_DOUBLE_PTR	2
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

#elif E09_FUNC_PTR

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

#elif E09_FUNC_PTR

#endif // E09_SINGLE_PTR
}
