#include "E05.h"

//#define E05_WHILE		1
#define E05_FOR			2	
//#define E05_DO_WHILE	3

void E05(int argc, char ** args)
{
	//�ݺ����̶�
	/*
		�־��� ������ �����ҵ��� �����ϴ� ����� �ǹ� �Ѵ�

		�ݺ��� ����
		-while
		-for
		-do~while
	ex)
	while(���ǽ�)
	{
	���� �����Ҷ����� ����
	}
	
	for(�ʱ���;������;�ݺ���)
	{
	���� �����Ҷ����� ����
	}

	do
	{
	������� �ϰ� ���ǰ� ��
	}
	while(���ǽ�)
	*/
#if E05_WHILE
	int i = 0;
	int nTimes = 0;
	printf("�ݺ� Ƚ���Է�\n");
	scanf("%d", &nTimes);
	/*
		�ݺ����� ������ ���� ��� Ư�� ������ �������� �����ϴ� �ݺ����� ���� ������� �Ѵ�.
	*/
	while (i < nTimes)
	{
		printf("%d, ", ++i);
	}

	while (1)
	{
		if (i > 5)
		{
			break;
			// �ݺ��� ���� break�� ������� ��� ���� �ݺ����� �ߴܤ��ϰ� �ݺ��� ������ ���α׷��� �帧 �̵� ����
		}
	}

	printf("\n");
#elif E05_FOR
	int nTimes = 0;
	printf("for �ݺ� Ƚ���Է�\n");
	scanf("%d", &nTimes);

	for (int i = 0; i < nTimes; ++i)
	{//���ڸ� ���Ҷ��� for���� ����ϴ� ���� ����
		//¦�� �� ���
		if ((i + 1) % 2 == 0)
		{
			continue;
		}
		printf("%d, ", i + 1);
	}

	printf("\n");
	
	int i = 0;
	nTimes = 0;
	printf("while �ݺ� Ƚ���Է�\n");
	scanf("%d", &nTimes);

	while (i < nTimes)
	{//���º񱳿� ���� ����
		//¦�� �� ���
		if ((i + 1) % 2 == 0)
		{
			i++;
			continue;
			//�ǹ� = �����帧���� �Ѿ��  �ݺ��� �ȿ����� ��밣
			//������ ���� ���� ������ ����Ǿ����� Ȯ���ϰ� continue�� ����ؾ���
			//for �ݺ��� ���ο��� �ش� Ű���带 ������� ��� ���� �帧�� �ݺ����� �̵��ϱ⶧���� 
			//while���� ���ؼ� continueŰ���� ��뿡 ���� ������ ����
		}
		printf("%d, ", i+1);
		i++;
	}

	printf("\n");
#elif E05_DO_WHILE
	int i = 0;
	int nTimes = 0;
	printf("�ݺ� Ƚ���Է�\n");
	scanf("%d", &nTimes);
	/*
	while for ���� ���� �Ǵ� ���� ���� üũ�ϰ� ���࿩�ΰ���
	do~while  ���� �����Ǵ� �ݺ��� ���ǰ� ������� ������ �ѹ� ����
	*/
	do
	{
		printf("%d, ", ++i);
	} while (i<nTimes);

	printf("\n");
#endif
}
