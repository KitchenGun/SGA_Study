#include "P03.h"

//#define P1	1
//#define	P2	2
#define	P3	3

#if P1
#elif P2

#elif P3
typedef struct Pos
{
	int x;
	int y;
};

//����Լ�
char* P3GetExitWay(char* a_cMatrix, int a_nNumRows, int a_nNumCols, Pos nPos, Pos prPos)
{
		bool NoExitWay = true;
		int idx = (nPos.y * a_nNumCols + nPos.x);
		a_cMatrix[idx] = 'X';
		if (idx % a_nNumCols - 1 > 0)//-x
		{
			if (idx - 1 != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
			{
				if (a_cMatrix[idx - 1] == '_')
				{
					NoExitWay = false;
					prPos = nPos;
					nPos.x--;
					return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
				}
				else if (a_cMatrix[idx - 1] == 'G')
				{
					a_cMatrix[idx - 1] = 'X';
					return a_cMatrix;
				}
			}
		}
		if (idx % a_nNumCols + 1 < a_nNumCols)//+x
		{
			if (idx + 1 != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
			{
				if (a_cMatrix[idx + 1] == '_')
				{
					NoExitWay = false;
					prPos = nPos;
					nPos.x++;
					return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
				}
				else if (a_cMatrix[idx + 1] == 'G')
				{
					a_cMatrix[idx + 1] = 'X';
					return a_cMatrix;
				}
			}
		}
		if (idx - a_nNumCols > 0)//-y
		{
			if (idx - a_nNumCols != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
			{
				if (a_cMatrix[idx - a_nNumCols] == '_')
				{
					NoExitWay = false;
					prPos = nPos;
					nPos.y--;
					return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
				}
				else if (a_cMatrix[idx - a_nNumCols] == 'G')
				{
					a_cMatrix[idx - a_nNumCols] = 'X';
					return a_cMatrix;
				}
			}
		}
		if (idx + a_nNumCols < a_nNumRows*a_nNumCols)//+y
		{
			if (idx + a_nNumCols != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
			{
				if (a_cMatrix[idx + a_nNumCols] == '_')
				{
					NoExitWay = false;
					prPos = nPos;
					nPos.y++;
					return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
				}
				else if (a_cMatrix[idx + a_nNumCols] == 'G')
				{
					a_cMatrix[idx + a_nNumCols] = 'X';
					return a_cMatrix;
				}
			}
		}
		if (NoExitWay)
		{
			a_cMatrix[idx] = '_';
			if (idx % a_nNumCols - 1 > 0)
			{
				if (idx != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
				{
					if (a_cMatrix[idx - 1] == 'X')
					{
						prPos = nPos;
						nPos.x--;
						return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
					}
				}
			}
			if (idx % a_nNumCols + 1 < a_nNumCols)
			{
				if (idx != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
				{
					if (a_cMatrix[idx + 1] == 'X')
					{
						prPos = nPos;
						nPos.x++;
						return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
					}
				}
			}
			if (idx - a_nNumCols > 0)
			{
				if (idx != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
				{
					if (a_cMatrix[idx - a_nNumCols] == 'X')
					{
						prPos = nPos;
						nPos.y--;
						return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
					}
				}
			}
			if (idx + a_nNumCols < a_nNumRows * a_nNumCols)//y�� ����
			{
				if (idx != (prPos.y * a_nNumRows) + prPos.x)//������ǥ�� ���� �� �� ��� ���� ����
				{
					if (a_cMatrix[idx + a_nNumCols] == 'X')
					{
						prPos = nPos;
						nPos.y++;
						return P3GetExitWay(a_cMatrix, a_nNumRows, a_nNumCols, nPos, prPos);
					}
				}
			}

		}


	return a_cMatrix;
}

#endif // P1



void P03(const int argc, const char** args)
{
#if P1
	int nSize = 0;
	int nPos = 0;
	bool Plus = true;
	bool Minus = true;

	do
	{
		printf("�ʱ� �迭ũ�� �Է� (10 �̻�): ");
		scanf("%d", &nSize);

	} while (nSize < 10);

	int* pnValues = (int*)malloc(sizeof(int)* nSize);
	
	srand((unsigned int)time(NULL));


	for (int i = 0; i < nSize; ++i)
	{
		pnValues[i] = rand() % 12;
		printf("%d, ", pnValues[i]);
	}

	printf("\nġȯ ���� ��ġ �Է� : ");
	scanf("%d", &nPos);
	--nPos;
	//ġȯ��
	printf("\n===== �迭 ġȯ �� =====\n");
	for (int i = 0; i < nSize; ++i)
	{
		printf("%d, ", pnValues[i]);
	}
	//ġȯ��
	printf("\n===== �迭 ġȯ �� =====\n");
	if (pnValues[nPos] >= 10)
	{//�ڽ��� 2�ڸ� �̻��� ���
		for (int i = 0; i < nSize; ++i)
		{
			printf("%d, ", pnValues[i]);
		}
	}
	else
	{
		pnValues[nPos] = -1;

		for (int i = 1; i < nSize; ++i)
		{
			if (Plus)//����ġ���� �ڿ��� �迭 ���� Ȯ��
			{
				if (nPos + i < nSize)
				{
					if (pnValues[nPos + i] >= 10)
					{
						Plus = false;
					}
					else
					{
						pnValues[nPos + i] = -1;
					}
				}
			}
			if (Minus)//����ġ���� �տ��� �迭 ���� Ȯ��
			{
				if (nPos - i >= 0)
				{
					if (pnValues[nPos - i] >= 10)
					{
						Minus = false;
					}
					else
					{
						pnValues[nPos - i] = -1;
					}
				}
			}
		}
		//���
		for (int i = 0; i < nSize; ++i)
		{
			printf("%d, ", pnValues[i]);
		}
	}

	SAFE_FREE(pnValues);



#elif P2
	int nNumRows = 0;
	int nNumCols = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("��� ũ�� �Է� :");
		scanf("%d %d", &nNumRows, &nNumCols);

	} while (nNumRows < 5 || nNumCols < 5);
	
	int nValue = 0;
	int* pnMatrix = (int*)malloc(sizeof(int) * (nNumCols * nNumRows));
	int nTotalRows = 0;
	int *nTotalCols = (int*)malloc(sizeof(int)*sizeof(nNumCols));
	// �࿭ ���� ���� +  �� �� ��� �� ���
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i * nNumCols) + j;
			pnMatrix[nIdx] = rand()%9+1;
			printf("%2d ", pnMatrix[nIdx]);
			nTotalRows += pnMatrix[nIdx];
		}
		printf("%2d", nTotalRows);
		nTotalRows = 0;
		printf("\n");
	}
	//�ʱ�ȭ
	for (int j = 0; j < nNumCols; j++)
	{
		nTotalCols[j] = 0;
	}
	//�� �հ��
	for (int i = 0; i < nNumRows; i++)
	{
		int j;
		for (j = 0; j < nNumCols; j++)
		{
			int nIdx = (i * nNumCols) + j;
			nTotalCols[j] += pnMatrix[nIdx];
		}
	}
	//�� ���
	for (int j = 0; j < nNumCols; j++)
	{
		printf("%2d ", nTotalCols[j]);
	}


	SAFE_FREE(pnMatrix);

#elif P3
	//�迭 ����
	int nNumRows = 5;
	int nNumCols = 5;

	char* cMatrix = (char*)malloc(sizeof(char) * (nNumCols * nNumRows));
	
	char Map[5][5]=
	{
		'S','#','_','_','_',
		'_','_','_','#','#',
		'_','#','_','_','_',
		'_','#','#','#','_',
		'#','#','G','#','_'
	};

	memcpy(cMatrix, Map, sizeof(char) * (nNumCols* nNumRows));
	
	//��� �⺻ ��
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i * nNumCols) + j;
			
			printf("%c ", cMatrix[nIdx]);
		}
		printf("\n");
	}
	printf("\n");

	Pos startPos;
	startPos.x = 0;
	startPos.y = 0;
	Pos initprPos;
	initprPos.x = -1;
	initprPos.y = -1;

	char* copy = P3GetExitWay(cMatrix,nNumRows,nNumCols,startPos, initprPos);
	
	//��� ��� Ž����
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i * nNumCols) + j;
			printf("%c ", copy[nIdx]);
		}
		printf("\n");
	}
	SAFE_FREE(cMatrix);
#endif // P1

	

}
