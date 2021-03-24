#include "E04.h"

//���ǹ� = Ư�� ���ǿ� ���� ���α׷� ���� �帧�� �ϳ��� ���� �Ҽ��ְ� ����� ���

/*
���ǹ��� ���� 
if ~ else
ex)
if(����a)
{
}
else if(����b)
{
}
else
{
}
switch ~ case
switch()
{
case:
}

*/

//#define E04_IF_ELSE		1	
#define E04_SWITCH_CASE 2

void E04(int argc, char ** args)
{/*
 #if~ #endif �� ��ó���⿡ ���� ó���Ǵ� ���ǹ��̴�. 
������ �Ǳ����� �ش籸���� ó���Ǳ� ������ Ư���ڵ带 Ȱ��/��Ȱ��ȭ ����

�ش� ���ǹ��� c�� ���ǹ��� �޸� �߰�ȣ �����ڸ� ���ؼ� ������ �����ϴ� ���� �Ұ����ϱ� ������ #if ��ɾ�� ���������� �޵�� #endif�� ���� ������ �ʿ��ϴ�
*/
#if E04_IF_ELSE
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null ���� ������ ���� �ʱ�ȭ��

	printf("�����Է� + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	if (chOperator == '+')
	{
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	}
	else if (chOperator == '-')
	{
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	}
	else if (chOperator == '*')
	{
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	}
	else if (chOperator == '/')
	{
		printf("%d / %d = %d\n", nValueA, nValueB, nValueA / nValueB);
	}
	else
	{
		printf("�߸��� ������ �Է��Ͽ����ϴ�.");
	}
#elif E04_SWITCH_CASE
	int nValueA = 0;
	int nValueB = 0;

	char chOperator = '\0';//null ���� ������ ���� �ʱ�ȭ��

	printf("�����Է� + - * /) : ");
	scanf("%d %c %d", &nValueA, &chOperator, &nValueB);

	//������ ������ ���ѵ�  ���� = �帧�� ���⼭ ���� �����Ѵ� break�� ����Ͽ��� �帧�� ¥���°���
	//���� ���ο��� ���� ���� �Ұ��� �߰�ȣ�� ������ ���� ������ ������
	//���� �� �Ұ��� 
	//�Ǽ��� ���
	{
		float fValue = 10.0f;
		//���������� �Լ��� ���� 
		if (fValue >= 9.0f - FLT_EPSILON && fValue <= 15.0f + FLT_EPSILON)
		{
			printf("�Ǽ� ���� ����");
		}
	}


	switch (chOperator)
	{
	case'+':
	{
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	}
	break;
	case'-':
	{
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	}
	break;
	case'*':
	{
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	}
	break;
	case'/':
	{
		printf("%d / %d = %d\n", nValueA, nValueB, nValueA / nValueB);
	}
	break;
	default:
	{
		printf("�߸��� ������ �Է��Ͽ����ϴ�.");
	}
	break;
	}

#endif//if E04_IF_ELSE

	/*
	�����ս������� if else�� switch case ���� �� ����
	��Ȯ�� ����񱳿��� ������ �ڵ尡 �����
	���� �����⿡ ������Ѵ�
	*/
}
