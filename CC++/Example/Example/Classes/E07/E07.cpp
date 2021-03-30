#include "E07.h"
//#include�� ��� ���� ������ ���� ����
//#define E07_FUNC_A		1
//#define E07_FUNC_B		2
#define E07_FUNC_C		3


#if E07_FUNC_A
//! ���� ����� ��ȯ�Ѵ�
int E07GetSumValue(int a_nLhs, int a_nRhs)//a = ���ް��̶�� �ǹ� nLhs ����  nRhs ����
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
int E07GetSubValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs - a_nRhs;
}
//! ���� ����� ��ȯ�Ѵ�
int E07GetMultiplyValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs * a_nRhs;
}
//! ������ ����� ��ȯ�Ѵ�
float E07GetDivideValue(int a_nLhs, int a_nRhs)
{
	return a_nLhs / (float)a_nRhs;
}
#elif E07_FUNC_B
static int g_nGValue = 0;

void E07IncrValue(int a_nValue)
{
	static int nLValue=0;
	//���������� �ش��Լ������� ���ٰ����� �ش����� ����� �޸𸮿��� ����� ������ X
	g_nGValue += a_nValue;
	nLValue += a_nValue;
	printf("���� ���\n");
	printf("����  %d\n", nLValue);
	printf("����  %d\n", g_nGValue);
}
#elif E07_FUNC_C
//���丮�� ���� ��ȯ 3! = 3*2*1
int E07GetFactorial(int a_nValue)
{
	//���� ����� ���
	if (a_nValue <= 1)
	{
		return 1;
	}
	return a_nValue * E07GetFactorial(a_nValue - 1);
}

#endif //#if E07_FUNC_A

void E07(int argc, char ** args)
{
#if E07_FUNC_A
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null ���� ������ ���� �ʱ�ȭ��

	printf("�����Է� + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		int nResult = E07GetSumValue(nValueA, nValueB);
		printf("%d + %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '-')
	{
		int nResult = E07GetSubValue(nValueA, nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '*')
	{
		int nResult = E07GetMultiplyValue(nValueA, nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nResult);
	}
	else if (chOperator == '/')
	{
		float fResult = E07GetDivideValue(nValueA, nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, fResult);
	}
	else
	{
		printf("�߸��� ������ �Է��Ͽ����ϴ�.");
	}
#elif E07_FUNC_B
	//��������
	//�� ����
	int nValue = 0;
	//g_nGValue = 0; 
	//���������� ���α׷� ��𼭵��� ������ ������
	do
	{
		printf("���� �Է�");
		printf("\n");
		scanf("%d", &nValue);
		E07IncrValue(nValue);
		printf("\n");

	} while (nValue!=0);
#elif E07_FUNC_C
	/*printf("���� �ִ밪 %d\n", RAND_MAX);
	std::random_device oRandom;//�ϵ��� ������ �õ尪�� ������� ��
	
	for (int i = 0; i < 10; i++)
	{
		//printf("%d\n",rand()%100);
		printf("%d\n", oRandom() % 100);
	}*/

	int nValue = 0;
	{
		//c/c++ ������ �ٸ��� ���� �̸� ���� ���𰡴� �ִ��� ����� ������ ������ �켱������ ����
		int nValue = 0;
		nValue = 100;
	}
	

	printf("���� �Է�\n");
	scanf("%d",&nValue);
	int nResult = E07GetFactorial(nValue);
	printf("%d! = %d\n", nValue, nResult);
#endif // E07_FUNC_A

}
