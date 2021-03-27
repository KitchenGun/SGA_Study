#include "P01.h"

//#define P1 1
//#define P2 2
//#define P3 3
//#define P4 4
//#define P5 5
#define P6 6
//����2 +-���� �Լ�
void DefinePlusMinursFunc(char sign, int defPlusMinurs)
{
	char PlusMinurs;
	if (defPlusMinurs >= 7)
	{
		PlusMinurs = '+';
	}
	else if (defPlusMinurs < 7 && defPlusMinurs >= 4)
	{
		PlusMinurs = NULL;
	}
	else if (defPlusMinurs < 4)
	{
		PlusMinurs = '-';
	}
	printf("��� : %c%c", sign, PlusMinurs);
}

//����5 ��ǻ���Է�
int CpuInputProc(int selectNum,int CpuNum)
{
	switch (selectNum)
	{
	case 0:
	{
		switch (CpuNum)
		{
		case 0:
		{
			printf("�����ϴ�(�� - ����, ��ǻ�� ����)\n");
			return 0;
		}
		case 1:
		{
			printf("�̰���ϴ�(�� - ����, ��ǻ�� ����)\n");
			return 1;
		}
		case 2:
		{
			printf("�����ϴ�(�� - ����, ��ǻ�� ��)\n");
			return -1;
		}
		}
		break;
	}
	case 1:
	{
		switch (CpuNum)
		{
		case 0:
		{
			printf("�����ϴ�(�� - ����, ��ǻ�� ����)\n");
			return -1;
		}
		case 1:
		{
			printf("�����ϴ�(�� - ����, ��ǻ�� ����)\n");
			return 0;
		}
		case 2:
		{
			printf("�̰���ϴ�(�� - ����, ��ǻ�� ��)\n");
			return 1;
		}
		}
		break;
	}
	case 2:
	{
		switch (CpuNum)
		{
		case 0:
		{
			printf("�̰���ϴ�(�� - ��, ��ǻ�� ����)\n");
			return 1;
		}
		case 1:
		{
			printf("�����ϴ�(�� - ��, ��ǻ�� ����)\n");
			return -1;
		}
		case 2:
		{
			printf("�����ϴ�(�� - ��, ��ǻ�� ��)\n");
			return 0;
		}
		}
		break;
	}
	default:
	{
		fputs("�߸� �Է��߽��ϴ�. �ٽ��Է��ϼ���\n",stdout);
		break;
	}
	}
}

//����6 ��� ���
void PrintMatrix(char matrix[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}
//����6 ���ڿ� �ߺ� ���� ����
void CharEliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)
	{
		if (*str == ch)
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}
//����6 ��� ������ üũ
int CheckResult(char matrix[][3])
{//1��ȯ�� ���� 0��ȯ�� ���� �ƴ�
	char Answer[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8',' '} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != Answer[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}


void P01(const int argc, const char** args)
{
#if P1
	//����1
	{
		printf("���� 1\n");
		printf("ABCD\n");
		printf("%c%c%c%c\n", 'A', 'B', 'C', 'D');
		printf("%s\n", "ABCD");
		fputs("ABCD", stdout);
	}
#elif P2
	//����2
	{
		int Score = 0;//����
		int DefPlusMinursValue = 0;//+,-�Ǻ��� ���� ����

		printf("�����Է� : ");
		scanf("%d", &Score);

		if (Score > 100 || Score < 0)
		{
			fputs("�߸��� ���� �Է�", stdout);
		}
		else if (Score <= 100 && Score >= 90)
		{//A
			DefPlusMinursValue = Score - 90;
			printf("���� �Է� : %d\n", Score);
			DefinePlusMinursFunc('A', DefPlusMinursValue);
		}
		else if (Score <= 89 && Score >= 80)
		{//B
			DefPlusMinursValue = Score - 80;
			printf("���� �Է� : %d\n", Score);
			DefinePlusMinursFunc('B', DefPlusMinursValue);
		}
		else if (Score <= 79 && Score >= 70)
		{//C
			DefPlusMinursValue = Score - 70;
			printf("���� �Է� : %d\n", Score);
			DefinePlusMinursFunc('C', DefPlusMinursValue);
		}
		else if (Score <= 69 && Score >= 60)
		{//D
			DefPlusMinursValue = Score - 60;
			printf("���� �Է� : %d\n", Score);
			DefinePlusMinursFunc('D', DefPlusMinursValue);
		}
		else 
		{//F
			printf("���� �Է� : %d\n", Score);
			DefinePlusMinursFunc('F', 5);
		}
	}
#elif P3
	//����3
	{
		int Line=0;
		printf("���� �� �Է� :");
		scanf("%d", &Line);
		for (int i = 0; i < Line; i++) 
		{
			for (int j = Line - 1; j > i; j--) 
			{
				printf(" ");
			}

			for (int j = 0; j < 2 * i + 1; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
#elif P4
	//����4
	{
		int Size = 0;
		int* Array;
		printf("���� �Է� : ");
		scanf("%d", &Size);
		//�����Ҵ�
		Array = (int*)malloc(sizeof(int) * Size);
		//�Է�
		for (int i = 0; i < Size ; i++)
		{
			printf("���� %d �Է� : ", i+1);
			scanf("%d", &Array[i]);
		}

		//Ȧ�� ���
		printf("�Է� ��� : ");
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] % 2 != 0)
			{
				printf("%d ", Array[i]);
			}
		}
		//¦�� ���
		for (int i = Size; i > 0; i--)
		{
			if (Array[i] % 2 == 0)
			{
				printf("%d ", Array[i]);
			}
		}
	}

#elif P5
	//���� 5
	{
		//�Է�
		int selectNum;
		int cpuInput;
		//����
		int win=0;
		int draw=0;
		int lose=0;
		int result;
		//���� ����
		while (1)
		{
			printf("���� (0), ���� (1), �� (2) ���� : ");
			scanf("%d", &selectNum);
			//���� �Լ�
			srand((unsigned int)time(NULL));
			cpuInput = rand() % 3;
			result = CpuInputProc(selectNum, cpuInput);
			//���
			if (result ==-1)
			{
				printf("���� : %d �� %d ��", win, draw);
				break;
			}
			else if (result == 0)
			{
				draw++;
			}
			else if (result == 1)
			{
				win++;
			}
		}
	}
#elif P6
//���� 6
	{
		char Matrix[3][3] = { 0 };
		char slot[10] = { '1','2','3','4','5','6','7',' ','8' };
		char slotselect[10]={ ' ','1','2','3','4','5','6','7','8' };
		int randNum;
		int count = 0;
		//�ӽ� ���� �� �����
		char temp=0;
		//�Է� ����
		int row;
		int col;
		//����
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//���� Ȯ�ο�
				//Matrix[i][j] = slot[count];
				srand((unsigned int)time(NULL));
				randNum = rand() % (9-count);
				Matrix[i][j] = slotselect[randNum];
				CharEliminate(slotselect, slotselect[randNum]);
				count++;
			}
		}
		while (1)
		{
			//���
			PrintMatrix(Matrix);
			printf("��ġ �Է� (��,��) :");
			scanf("%d %d", &row, &col);
			if (row <= 2 &&  row >= 0)//���� ó��
			{
				if (col <= 2 && col >= 0)//���� ó��
				{
					//����&����Ұ���
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							if (Matrix[i][j] == ' ')
							{
								if (i - 1 <= row && i + 1 >= row)
								{
									if (j - 1 <= col && j + 1 >= col)
									{
										temp = Matrix[row][col];
										Matrix[row][col] = Matrix[i][j];
										Matrix[i][j] = temp;
									}
								}
							}
						}
					}
					//���
					if (temp == 0)
					{
						printf("���� ���� ��ĭ �ֺ��� ��,���� �Է��ϼ���\n");
					}
					else if (temp == ' ')
					{
						printf("��ĭ�� �����ϰ� �Է����ּ���\n");
						temp = 0;
					}
					else
					{
						printf("���� ����\n");
						if (CheckResult(Matrix) == 1)
						{
							printf("���� ���� ���α׷� ����");
							break;
						}
						temp = 0;
					}
				}
				else
				{
					printf("����ε� ���ڸ� �Է����ּ��� (�� �Է� ����)\n");
				}
			}
			else
			{
				printf("����ε� ���ڸ� �Է����ּ��� (�� �Է� ����)\n");
			}
			
		}
	}

	
#endif
}
