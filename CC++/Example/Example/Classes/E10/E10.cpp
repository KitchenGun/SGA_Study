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
	c언어에서 제공하는 동적 할당 함수들은 반환 값으로 void*가 반환 됨
	그럼으로 만든공간에 어떤 자료형이 들어가야하는지 정의를 안해 놓았기 때문에 프로그램의 목적에 맞게 자료형을 변환해서 사용해야함
	*/
	int *pnValue = (int*)malloc(sizeof(int));
	double *pndbValue = (double*)malloc(sizeof(double));

	*pnValue = 10;
	*pndbValue = 3.14f;
	printf("\n동적할당\n");
	printf("int* : %d \n", *pnValue);
	printf("double* : %lf \n", *pndbValue);
	/*
	c언어는 동적으로 할당된 메모리를 시스템이 관리해주지 않는
	언매니지드 언어이기 때문에 해당 메모리가 더이상 필요가 없다면
	반드시 free함수를 통해서 동적으로 할당된 메모리를 해제 줘야한다
	*/
	//전처리기를 사용한 매크로 함수를 사용한 메모리 초기화 방법이다
	SAFE_FREE(pnValue);
	//아래의 코드와 같다 전처리 단계에서 아래 처럼 변경된다 
	//if ((pnValue) != NULL) { free((pnValue)); (pnValue) = NULL; }
	SAFE_FREE(pndbValue);
	//free(pnValue);		pnValue = NULL;
	//free(pndbValue);	
	/*
	free함수를 통해서 이미 해제 되어있는 메모리에
	다시 접근을 시도하면 이는 접근 권한이 없는 메모리 영역에 접근을 시도한 것이기 때문에
	프로그램이 오작동하거나 크래시가 발생할수있다 접근을 방지하기 위해서 해당 메모리를 가리키는 포인터를 NULL로 변경해주는 것이 좋은 습관이다
	즉 포인터를 통해 메모리에 접근하기 전에 널 포인터 여부를 검사하는 코드를 병시해줌으로써 좀더 안전하게 포인터를 제어하는 것이 가능하다
	*/
	if (pnValue != NULL)
	{
		*pnValue = 10;
	}
	int nSize = 0;

	printf("\n초기 배열크기 입력 : ");
	scanf("%d", &nSize);

	int *pnValues = (int*)malloc(sizeof(int)*nSize);


	int nNumValues = 0;
	int nInputValue = 0;

	do
	{
		printf("정수 %d 입력 : ", nNumValues + 1);
		scanf("%d", &nSize);

		//배열이 가득 찼을 경우
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

	printf("\n동적 할당 배열요소\n");
	for (int i = 0; i < nNumValues; ++i)
	{
		printf("%d ", pnValues[i]);
	}
	SAFE_FREE(pnValues);

#elif MALLOC_B
	int nNumRows = 0;
	int nNumCols = 0;

	printf("행렬 크기 입력 :");
	scanf("%d %d", &nNumRows, &nNumCols);
	int nValue = 0;
	int *pnMatrix = (int*)malloc(sizeof(int)*(nNumCols*nNumRows));
	/*
	2차원 이상의 배열을 동적으로 할당하기위해서는 1차원 배열을 할당후 주소의 계산을 통해서 2차원 배열처럼 사용해야한다 
	이는 컴퓨터의 메모리는 1차원 구조로 되어있으며 2차원 배열 생성시 컴퓨터가 자동으로 1차원으로 변경을 한다
	단 동적으로 할당된 메모리는 컴퓨터가 자동으로 2차원 이상의 주소를 연산하는 것이 불가능 하기때문에 이를 직접 수행해야한다

	(행 * 열개수) +열  메모리상의 인덱스 위치
	1차원 인덱스 / 열 개수는 행인덱스
	1차원 인덱스 % 열 개수는 열 인덱스

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
	printf("\n행렬요소\n");
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
