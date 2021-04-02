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
	//%p�޸� �ּ� 16���� ���·� ������� 
	printf("������ ���� ��� \n");
	printf("nvalue %d %p nvalue * %p\n", nValue,&nValue, pnValue);
	printf("fvalue %f %p fvalue * %p\n", fValue,&fValue, pfValue);

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

#elif E09_DOUBLE_PTR

#elif E09_FUNC_PTR

#endif // E09_SINGLE_PTR
}
