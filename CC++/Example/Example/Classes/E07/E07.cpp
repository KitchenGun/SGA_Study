#include "E07.h"
//#include�� ��� ���� ������ ���� ����
//#define P07_FUNC_A		1
#define P07_FUNC_B		2
#define P07_FUNC_C		3


#if P07_FUNC_A
//! ���� ����� ��ȯ�Ѵ�
int P07GetSumValue(int a_nLhs, int a_nRhs)//a = ���ް��̶�� �ǹ� nLhs ����  nRhs ����
{
	/*
	return Ű����� �Լ��� �帧�� �����ϰ� �ش��Լ��� ȣ���� ������ �ǵ��ư��� ������ �����Ѵ� ���� �ش� �Լ��� ��ȯ ���� ���� �� ��� �ش� Ű���忡 
	��õ� ��� ���� ȣ���� ������ ��ȯ�Ѵ�.
	void �� ��� 
	return;
	*/
	return a_nLhs + a_nRhs;
}
//! ���� ����� ��ȯ�Ѵ�
int P07GetSubValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//! ���� ����� ��ȯ�Ѵ�
int P07GetMultiplyValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs * a_nRhs;
}
//! ������ ����� ��ȯ�Ѵ�
float P07GetDivideValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs / (float)a_nRhs;
}
#elif P07_FUNC_B

#endif //#if P07_FUNC_A

void E07(int argc, char ** args)
{
#if P07_FUNC_A
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null ���� ������ ���� �ʱ�ȭ��

	printf("�����Է� + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		int nResult = P07GetSumValue(nValueA, nValueB);
		printf("%d + %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '-')
	{
		int nResult = P07GetSubValue(nValueA, nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '*')
	{
		int nResult = P07GetMultiplyValue(nValueA, nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '/')
	{
		float fResult = P07GetDivideValue(nValueA, nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, fResult);
	}
	else
	{
		printf("�߸��� ������ �Է��Ͽ����ϴ�.");
	}
#elif P07_FUNC_B
#elif P07_FUNC_C
#endif // P07_FUNC_A

}
