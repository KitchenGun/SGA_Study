#include "E06.h"

#define E06_ARRAY	1
#define E06_STRING	2

#if E06_ARRAY
//#define E06_SINGLE_ARRAY	1
#define E06_MULTI_ARRAY		2
#elif E06_STRING
#endif // E06_ARRAY

void PrintMatrix(int matrix[][2])
{
	int nRowA = sizeof(matrix) / sizeof(matrix[0]);
	int nColA = sizeof(matrix[0]) / sizeof(matrix[0][0]);


	for (int i = 0; i < nRowA; i++)
	{
		for (int j = 0; j < nColA; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
/*
����Ʈ�� ���ؼ� ���ʹ� ����
*/

void E06(int argc, char ** args)
{
#if E06_ARRAY
#if E06_SINGLE_ARRAY	

	int anValuesA[5];
	anValuesA[0] = 1;
	anValuesA[1] = 2;
	anValuesA[2] = 3;
	anValuesA[3] = 4;
	anValuesA[4] = 5;

	int anValuesB[7] =
	{
		1,2,3,4,5,6,7
	};
	/*
	�迭�� ���̺��� �ʱ�ȭ ���� ���� ��� ������ ��õ��� ���� �迭 ��Ҵ� 0���� �ʱ�ȭ�� �ȴ�

	int a[5] = {0}; 0���� ���� �ʱ�ȭ ù ��Ҹ� 0�� �ְ� ������ ��Ҵ� 0���� �ڵ� �ʱ�ȭ
	*/
	int anValuesC[5] =
	{
		1,2,3
	};

	/*
	�迭�� ���̸� ������� �ʾ��� ��� �ʱ�ȭ ���� ������ ������� �迭�� ���̰� �ڵ����� ��� �ȴ� �� �迭�� ���̸� ������� �ʾ����� 
	�ʱ�ȭ���� �����ؾ��Ѵ�
	*/

	int anValuesD[] =
	{
		1,2
	};


	printf("�迭 a���\n");
	printf("%d,%d,%d,%d,%d\n",anValuesA[0], anValuesA[1], anValuesA[2], anValuesA[3], anValuesA[4]);
	printf("\n�迭 b���\n");
	/*
	sizeof �����ڸ� �迭�� �����ϸ� �迭�� ũ�⸦ �������� ���� �����ϴ� 
	�迭�� ũ��� �迭 ��� ũ�� * �迭 ���� �̸� Ȱ���ϸ� �迭�� ���̸� ����ϴ� ���� �����ϴ�
	*/
	const int nSizeB = sizeof(anValuesB) / sizeof(anValuesB[0]);
	for (int i = 0; i <nSizeB; i++)
	{
		printf("%d ", anValuesB[i]);
	}
	printf("\n");

	printf("�迭 c���\n");
	const int nSizeC = sizeof(anValuesC) / sizeof(anValuesC[0]);
	for (int i = 0; i < nSizeC; i++)
	{
		printf("%d ", anValuesC[i]);
	}
	printf("\n");

	printf("�迭 d���\n");
	const int nSizeD = sizeof(anValuesD) / sizeof(anValuesD[0]);
	for (int i = 0; i < nSizeD; i++)
	{
		printf("%d ", anValuesD[i]);
	}
	printf("\n");

#elif E06_MULTI_ARRAY	
	/*
	2���� �迭�� 1���� �迭�� ��ҷ��ϴ� �迭
	�迭�� Ư����ҿ� ���� �����ϱ� ���ؼ��� �ε��� ��ȣ�� 2�� ����ؾ��Ѵ� 
	�� ù��° �ε��� ��ȣ�� 2���� �迭�� ���ϰ� �ִ� �� ��ҿ� �����ϱ� ���� ���̸� 
	�ι�° �ε��� ��ȣ�� �ش� �迭�� ��ҿ� �����ϱ� ���� ���̴�.
	*/
	int anMatrixA[2][2];
	anMatrixA[0][0] = 1;
	anMatrixA[0][1] = 2;
	anMatrixA[1][0] = 3;
	anMatrixA[1][1] = 4;

	int anMatrixB[2][2]
	{
		{1,2},
		{3,4}
	};
	int anMatrixC[2][2]
	{
		1,2,3,4
	};
	//������ �迭�� �ݵ�� �ʱ�ȭ���� ������ ������ִ� ���� ���� �����̴�.
	int anMatrixD[2][2]
	{
		{1},
		{3}
	};
	/*
	������ �迭�� �ʱ�ȭ ���� ���� ���� ������ �������� ��� �迭�� ���ش�� �ʱ�ȭ ���� �迭�� ��ҿ� ���������� �����ȴ� 
	�̶� �迭�� ������ �ϵ������ ���� ����� �Ǵ� ���������� ������ �Ǹ� ����� �� ��쿡�� ���� ������� ���ʴ�� ���� ���� �Ǹ�,
	�������� ��쿡�� ���� ������� ���ʴ�� ���� �����ȴ� �����ϸ� �ʱ�ȭ ���� ������ ������ִ� ���� �迭���ؿ� ���� ������ �����ϴ� ���� �����̴�.
	*/
	int anMatrixE[2][2]//����� ������ �迭 �� ���� ������ �̷��� �������� �ʴ� ���� ���� cpu gpu�� ���̰� ����
	{
		1,2
	};


	printf("A ���");
	PrintMatrix(anMatrixA);
	printf("B ���");
	PrintMatrix(anMatrixB);

	//int nRowA = sizeof(anMatrixA) / sizeof(anMatrixA[0]);
	//int nColA = sizeof(anMatrixA[0]) / sizeof(anMatrixA[0][0]);
	//for (int i = 0; i < nRowA; i++)
	//{
	//	for (int j = 0; j < nColA; j++)
	//	{
	//		printf("%d", anMatrixA[i][j]);
	//	}
	//	printf("\n");
	//}



#endif//E06_SINGLE_ARRAY

#elif E06_STRING

#endif // E06_ARRAY

}
