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

void E04(int argc, char ** args)
{
	int nValueA = 0;
	int nValueB = 0;
	//0�� ���� ���������� ���̴�
	printf("����(2�� �Է�) : ");
	scanf("%d %d", &nValueA, &nValueB);

	if (nValueB == 0)
	{
		printf("b�� ���� 0���� �Է��� �� �����ϴ�.\n");
	}
	else
	{
		printf("���\n");
		printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
		printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
		printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
		printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
		printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
	}
}
