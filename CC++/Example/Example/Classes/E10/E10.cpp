#include "E10.h"

#define E10_MALLOC	1
#define E10_CALLOC	2
#define E10_REALLOC	3

#if E10_MALLOC
//#define MALLOC_A 1
#define MALLOC_B 2
#elif E10_CALLOC
#elif E10_REALLOC
#endif // E10_MALLOC

void E10(int argc, char ** args)
{
#if E10_MALLOC
#if MALLOC_A
	/*
	c���� �����ϴ� ���� �Ҵ� �Լ����� ��ȯ ������ void*�� ��ȯ ��
	�׷����� ��������� � �ڷ����� �����ϴ��� ���Ǹ� ���� ���ұ� ������ ���α׷��� ������ �°� �ڷ����� ��ȯ�ؼ� ����ؾ���
	*/
	int *pnValue = (int*)malloc(sizeof(int));
	double *pndbValue = (double*)malloc(sizeof(double));

	*pnValue = 10;
	*pndbValue = 3.14f;
	printf("\n�����Ҵ�\n");
	printf("int* : %d \n", *pnValue);
	printf("double* : %lf \n", *pndbValue);
	/*
	c���� �������� �Ҵ�� �޸𸮸� �ý����� ���������� �ʴ�
	��Ŵ����� ����̱� ������ �ش� �޸𸮰� ���̻� �ʿ䰡 ���ٸ�
	�ݵ�� free�Լ��� ���ؼ� �������� �Ҵ�� �޸𸮸� ���� ����Ѵ�
	*/
	//��ó���⸦ ����� ��ũ�� �Լ��� ����� �޸� �ʱ�ȭ ����̴�
	SAFE_FREE(pnValue);
	//�Ʒ��� �ڵ�� ���� ��ó�� �ܰ迡�� �Ʒ� ó�� ����ȴ� 
	//if ((pnValue) != NULL) { free((pnValue)); (pnValue) = NULL; }
	SAFE_FREE(pndbValue);
	//free(pnValue);		pnValue = NULL;
	//free(pndbValue);	
	/*
	free�Լ��� ���ؼ� �̹� ���� �Ǿ��ִ� �޸𸮿�
	�ٽ� ������ �õ��ϸ� �̴� ���� ������ ���� �޸� ������ ������ �õ��� ���̱� ������
	���α׷��� ���۵��ϰų� ũ���ð� �߻��Ҽ��ִ� ������ �����ϱ� ���ؼ� �ش� �޸𸮸� ����Ű�� �����͸� NULL�� �������ִ� ���� ���� �����̴�
	�� �����͸� ���� �޸𸮿� �����ϱ� ���� �� ������ ���θ� �˻��ϴ� �ڵ带 �����������ν� ���� �����ϰ� �����͸� �����ϴ� ���� �����ϴ�
	*/
	if (pnValue != NULL)
	{
		*pnValue = 10;
	}
	int nSize = 0;

	printf("\n�ʱ� �迭ũ�� �Է� : ");
	scanf("%d", &nSize);

	int *pnValues = (int*)malloc(sizeof(int)*nSize);


	int nNumValues = 0;
	int nInputValue = 0;

	do
	{
		printf("���� %d �Է� : ", nNumValues + 1);
		scanf("%d", &nSize);

		//�迭�� ���� á�� ���
		if (nNumValues >= nSize)
		{
			nSize *= 2;
			int*pnNewValues = (int*)malloc(sizeof(int)*nSize);
			for (int i = 0; i < nNumValues; ++i)
			{
				pnNewValues[i] = pnValues[i];
			}

			SAFE_FREE(pnValues);
			pnValues = pnNewValues;
		}

		pnValues[nNumValues++] = nInputValue;
	} while (nInputValue != 0);

	printf("\n���� �Ҵ� �迭���\n");
	for (int i = 0; i < nNumValues; ++i)
	{
		printf("%d ", pnValues[i]);
	}
	SAFE_FREE(pnValues);

#elif MALLOC_B
	int nNumRows = 0;
	int nNumCols = 0;

	printf("��� ũ�� �Է� :");
	scanf("%d %d", &nNumRows, &nNumCols);
	int nValue = 0;
	int *pnMatrix = (int*)malloc(sizeof(int)*(nNumCols*nNumRows));
	/*
	2���� �̻��� �迭�� �������� �Ҵ��ϱ����ؼ��� 1���� �迭�� �Ҵ��� �ּ��� ����� ���ؼ� 2���� �迭ó�� ����ؾ��Ѵ� 
	�̴� ��ǻ���� �޸𸮴� 1���� ������ �Ǿ������� 2���� �迭 ������ ��ǻ�Ͱ� �ڵ����� 1�������� ������ �Ѵ�
	�� �������� �Ҵ�� �޸𸮴� ��ǻ�Ͱ� �ڵ����� 2���� �̻��� �ּҸ� �����ϴ� ���� �Ұ��� �ϱ⶧���� �̸� ���� �����ؾ��Ѵ�

	(�� * ������) +��  �޸𸮻��� �ε��� ��ġ
	1���� �ε��� / �� ������ ���ε���
	1���� �ε��� % �� ������ �� �ε���

	*/
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i*nNumCols) + j;
			pnMatrix[nIdx] = ++nValue;
		}
	}

	int anMatrix[5][5] = { 0 };
	memcpy(anMatrix, pnMatrix, sizeof(int)*(nNumCols*nNumRows));
	printf("\n��Ŀ��\n");
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i*nNumCols) + j;
			printf("%2d ", pnMatrix[nIdx]);
		}
		printf("\n");
	}
	for (int i = 0; i < nNumRows; i++)
	{
		for (int j = 0; j < nNumCols; j++)
		{
			int nIdx = (i*nNumCols) + j;
			printf("%2d ", ((int *)(anMatrix))[nIdx]);
		}
		printf("\n");
	}
	SAFE_FREE(pnMatrix);

#endif // MALLOCA
#elif E10_CALLOC
#elif E10_REALLOC
#endif // E10_MALLOC
}
