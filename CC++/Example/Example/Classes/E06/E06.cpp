#include "E06.h"

//#define E06_ARRAY	1
#define E06_STRING	2

#if E06_ARRAY
//#define E06_SINGLE_ARRAY	1
#define E06_MULTI_ARRAY		2
#elif E06_STRING
#endif // E06_ARRAY

void PrintMatrix(int matrix[][2], int nRow, int nCol)
{
	int nRowA = sizeof(matrix) / sizeof(matrix[0]);
	int nColA = sizeof(matrix[0]) / sizeof(matrix[0][0]);


	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
/*
리스트에 비해서 백터는 퍼포
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
	배열의 길이보다 초기화 값이 적을 경우 나머지 명시되지 않은 배열 요소는 0으로 초기화가 된다

	int a[5] = {0}; 0으로 전부 초기화 첫 요소만 0을 넣고 나머지 요소는 0으로 자동 초기화
	*/
	int anValuesC[5] =
	{
		1,2,3
	};

	/*
	배열의 길이를 명시하지 않았을 경우 초기화 값의 개수를 기반으로 배열의 길이가 자동으로 계산 된다 즉 배열의 길이를 명시하지 않았으면 
	초기화값을 지정해야한다
	*/

	int anValuesD[] =
	{
		1,2
	};


	printf("배열 a요소\n");
	printf("%d,%d,%d,%d,%d\n",anValuesA[0], anValuesA[1], anValuesA[2], anValuesA[3], anValuesA[4]);
	printf("\n배열 b요소\n");
	/*
	sizeof 연산자를 배열에 적용하면 배열의 크기를 가져오는 것이 가능하다 
	배열의 크기는 배열 요소 크기 * 배열 길이 이를 활용하면 배열의 길이를 계산하는 것이 가능하다
	*/
	const int nSizeB = sizeof(anValuesB) / sizeof(anValuesB[0]);
	for (int i = 0; i <nSizeB; i++)
	{
		printf("%d ", anValuesB[i]);
	}
	printf("\n");

	printf("배열 c요소\n");
	const int nSizeC = sizeof(anValuesC) / sizeof(anValuesC[0]);
	for (int i = 0; i < nSizeC; i++)
	{
		printf("%d ", anValuesC[i]);
	}
	printf("\n");

	printf("배열 d요소\n");
	const int nSizeD = sizeof(anValuesD) / sizeof(anValuesD[0]);
	for (int i = 0; i < nSizeD; i++)
	{
		printf("%d ", anValuesD[i]);
	}
	printf("\n");

#elif E06_MULTI_ARRAY	
	/*
	2차원 배열은 1차원 배열을 요소로하는 배열
	배열의 특정요소에 값을 지정하기 위해서는 인덱스 번호를 2번 명시해야한다 
	즉 첫번째 인덱스 번호는 2차원 배열이 지니고 있는 각 요소에 접근하기 위한 것이며 
	두번째 인덱스 번호는 해당 배열의 요소에 접근하기 위한 것이다.
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
	//다차원 배열은 반드시 초기화값의 차원을 명시해주는 것이 좋은 습관이다.
	int anMatrixD[2][2]
	{
		{1},
		{3}
	};
	/*
	다차원 배열에 초기화 값에 하위 차원 지정을 생략했을 경우 배열의 기준대로 초기화 값이 배열의 요소에 순차적으로 지정된다 
	이때 배열의 기준은 하드웨어의 따라 행기준 또는 열기준으로 구분이 되며 행기준 일 경우에는 행을 기반으로 차례대로 값이 지정 되며,
	열기준일 경우에는 열을 기반으로 차례대로 값이 지정된다 가능하면 초기화 값의 차원을 명시해주는 것이 배열기준에 따른 오류를 방지하는 좋은 습관이다.
	*/
	int anMatrixE[2][2]//행기준 열기준 배열 의 차이 때문에 이렇게 선언하지 않는 것이 좋음 cpu gpu의 차이가 있음
	{
		1,2
	};

	int nRow;
	int nCol;

	printf("A 출력\n");
	nRow = sizeof(anMatrixA) / sizeof(anMatrixA[0]);
	nCol = sizeof(anMatrixA) / sizeof(anMatrixA[0]);
	PrintMatrix(anMatrixA, nRow, nCol);
	printf("B 출력\n");
	nRow = sizeof(anMatrixB) / sizeof(anMatrixB[0]);
	nCol = sizeof(anMatrixB[0]) / sizeof(anMatrixB[0][0]);
	PrintMatrix(anMatrixB, nRow, nCol);
	printf("C 출력\n");
	nRow = sizeof(anMatrixC) / sizeof(anMatrixC[0]);
	nCol = sizeof(anMatrixC[0]) / sizeof(anMatrixC[0][0]);
	PrintMatrix(anMatrixC, nRow, nCol);
	printf("D 출력\n");
	nRow = sizeof(anMatrixD) / sizeof(anMatrixD[0]);
	nCol = sizeof(anMatrixD[0]) / sizeof(anMatrixD[0][0]);
	PrintMatrix(anMatrixD, nRow, nCol);
	printf("E 출력\n");
	nRow = sizeof(anMatrixE) / sizeof(anMatrixE[0]);
	nCol = sizeof(anMatrixE[0]) / sizeof(anMatrixE[0][0]);
	PrintMatrix(anMatrixE, nRow, nCol);
	
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

	char szStringA[100] = { 'A','B','C','D','\0' }; //공백 문자 없으면 작동 하지 않으면 널문자가 나올때 까지 출력됨
	char szStringB[100] = "abcd";
	
	printf("문자열 출력\n");
	/*
	%s 는 문자열을 출력하기 위한 서식문자이다 scanf 함수를 통해 문자열을 입력 받을 때도  해당 서식 문자 사용하면 됨
	하지만 공백 문자를 기준으로 scanf가 작동함으로 공백 문자열을 읽어들일수없다
	*/
	printf("문자열 A : %s\n", szStringA);
	printf("문자열 B : %s\n", szStringB);
	/*
	strcpy 함수는 우항에 명시한 문자열을 좌항에 복사하는 역할을 수행한다 즉 =과 동일한 기능이다
	strcat 함수는 우항에 명시한 문자열을 좌항에 추가하는 역할을 수행한다 즉 +=와 동일한 기능이다
	strlen 함수는 문자열의 개수를 가져올수있다.
	*/

	strcpy(szStringA, "Hi");
	strcat(szStringB, "World");

	printf("출력결과\n");
	printf("문자열 A (%d): %s\n", szStringA, szStringA);
	printf("문자열 B (%d): %s\n", szStringB, szStringA);


	printf("\n문자열 개수 결과\n");
	printf("문자열 A (%d): %s\n", strlen(szStringA), szStringA);
	printf("문자열 B (%d): %s\n", strlen(szStringB), szStringB);

	printf("\n문자열 비교 결과\n");
	printf("문자열 A B 비교 : %d\n", strcmp(szStringA, szStringB));
	/*
	strcmp 함수는 두 문자열을 비교한다. 아스키코드의 숫자 합으로 결정
		좌항이 작으면 -1 
		같으면 0 
		우항이 크면 1
	*/
	//주어진 문자열에서 한문자의 포함여부를 검사하는역할 수행
	printf("문자열 A의 T문자 포함 여부 : %d\n", strchr(szStringA, 'T') != NULL);
	//문자열에서 특정문자열의 포함 여부를 검사하는 역할을 수행한다
	printf("문자열 B의 World 문자열 포함 여부 : %d\n", strstr(szStringB, "World") != NULL);
	//두함수 모두 결과값의 특정문자의 위치를 가리키는 포인터가 반환되며 해당결과값이 Null이면 탐색 실패를 의미한다

	//다른 곳에서 사용할수 있으나 visual studio에서는 비공식적으로 지원하지 않음

	//문자열 반전
	printf("문자열 반전 : %s\n", _strrev(szStringA));
	//대소문자 변경
	printf("문자열 A 모두 소문자로 변환 : %s\n", _strlwr(szStringA));
	printf("문자열 B 모두 대문자로 변환 : %s\n", _strupr(szStringB));

	printf("\n 문자열 A 입력 : ");
	scanf("%s", szStringA);
	getchar();
	//개행문자를 지우는 역할
	printf("문자열 B 입력 : ");

	/*
	콘솔용으로 제작된 프로그램을 실행하면 해당프로그램과 콘솔 프로그램 간에 데이터를 주고 받을 수 있는 다리가 연결되면 해당 다리는 stream이라고 한다
	stdin 콘솔 프로그램으로 부터 데이터를 읽어 들일수있는 다리이다
	stdout 스트림은 데이터를 콘솔 프로그램에 내보내는 다리이다.
	즉 printf scanf 함수는 내부적으로 해당 stream을 통해서 데이터를 출력 하거나 입력 받는 역할을 수행한다

	fgets 함수는 특정 stream 에서 데이터를 읽어들이는 역할을 수행하며 해당 함수를 사용하면 
	공백이 포함 되어 있는 문자열을 콘솔창으로부터 읽어들이는 것이 가능하다
	fputs 함수는 특정 stream으로 데이터를 출하는 역할을 수행한다.
	fgets/fputs 함수 모두 문자열 데이터를 다루는데 특화되어 있는 함수 이기 때문에 
	
	해당 함수에 문자열이 아닌 다른 데이터를 명시했을 경우 올바르게 동작 하지 않는다
	*/

	fgets(szStringB,sizeof(szStringB),stdin);//불러오는 값을 제안할수있기때문에 사용 fput는 통일성을 위해서 사용
	fputs("출력 결과",stdout);
	printf("\n");
	printf("문자열 A : %s\n", szStringA);
	printf("문자열 B : %s\n", szStringB);
#endif // E06_ARRAY

}
