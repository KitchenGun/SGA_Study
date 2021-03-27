#include "P01.h"

//#define P1 1
//#define P2 2
//#define P3 3
//#define P4 4
//#define P5 5
#define P6 6
//과제2 +-구분 함수
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
	printf("결과 : %c%c", sign, PlusMinurs);
}

//과제5 컴퓨터입력
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
			printf("비겼습니다(나 - 바위, 컴퓨터 바위)\n");
			return 0;
		}
		case 1:
		{
			printf("이겼습니다(나 - 바위, 컴퓨터 가위)\n");
			return 1;
		}
		case 2:
		{
			printf("졌습니다(나 - 바위, 컴퓨터 보)\n");
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
			printf("졌습니다(나 - 가위, 컴퓨터 바위)\n");
			return -1;
		}
		case 1:
		{
			printf("비겼습니다(나 - 가위, 컴퓨터 가위)\n");
			return 0;
		}
		case 2:
		{
			printf("이겼습니다(나 - 가위, 컴퓨터 보)\n");
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
			printf("이겼습니다(나 - 보, 컴퓨터 바위)\n");
			return 1;
		}
		case 1:
		{
			printf("졌습니다(나 - 보, 컴퓨터 가위)\n");
			return -1;
		}
		case 2:
		{
			printf("비겼습니다(나 - 보, 컴퓨터 보)\n");
			return 0;
		}
		}
		break;
	}
	default:
	{
		fputs("잘못 입력했습니다. 다시입력하세요\n",stdout);
		break;
	}
	}
}

//과제6 행렬 출력
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
//과제6 문자열 중복 문자 제거
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
//과제6 행렬 데이터 체크
int CheckResult(char matrix[][3])
{//1반환시 정답 0반환시 정답 아님
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
	//과제1
	{
		printf("과제 1\n");
		printf("ABCD\n");
		printf("%c%c%c%c\n", 'A', 'B', 'C', 'D');
		printf("%s\n", "ABCD");
		fputs("ABCD", stdout);
	}
#elif P2
	//과제2
	{
		int Score = 0;//점수
		int DefPlusMinursValue = 0;//+,-판별을 위한 변수

		printf("학점입력 : ");
		scanf("%d", &Score);

		if (Score > 100 || Score < 0)
		{
			fputs("잘못된 숫자 입력", stdout);
		}
		else if (Score <= 100 && Score >= 90)
		{//A
			DefPlusMinursValue = Score - 90;
			printf("점수 입력 : %d\n", Score);
			DefinePlusMinursFunc('A', DefPlusMinursValue);
		}
		else if (Score <= 89 && Score >= 80)
		{//B
			DefPlusMinursValue = Score - 80;
			printf("점수 입력 : %d\n", Score);
			DefinePlusMinursFunc('B', DefPlusMinursValue);
		}
		else if (Score <= 79 && Score >= 70)
		{//C
			DefPlusMinursValue = Score - 70;
			printf("점수 입력 : %d\n", Score);
			DefinePlusMinursFunc('C', DefPlusMinursValue);
		}
		else if (Score <= 69 && Score >= 60)
		{//D
			DefPlusMinursValue = Score - 60;
			printf("점수 입력 : %d\n", Score);
			DefinePlusMinursFunc('D', DefPlusMinursValue);
		}
		else 
		{//F
			printf("점수 입력 : %d\n", Score);
			DefinePlusMinursFunc('F', 5);
		}
	}
#elif P3
	//과제3
	{
		int Line=0;
		printf("라인 수 입력 :");
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
	//과제4
	{
		int Size = 0;
		int* Array;
		printf("개수 입력 : ");
		scanf("%d", &Size);
		//동적할당
		Array = (int*)malloc(sizeof(int) * Size);
		//입력
		for (int i = 0; i < Size ; i++)
		{
			printf("정수 %d 입력 : ", i+1);
			scanf("%d", &Array[i]);
		}

		//홀수 출력
		printf("입력 결과 : ");
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] % 2 != 0)
			{
				printf("%d ", Array[i]);
			}
		}
		//짝수 출력
		for (int i = Size; i > 0; i--)
		{
			if (Array[i] % 2 == 0)
			{
				printf("%d ", Array[i]);
			}
		}
	}

#elif P5
	//과제 5
	{
		//입력
		int selectNum;
		int cpuInput;
		//승패
		int win=0;
		int draw=0;
		int lose=0;
		int result;
		//게임 진행
		while (1)
		{
			printf("바위 (0), 가위 (1), 보 (2) 선택 : ");
			scanf("%d", &selectNum);
			//랜덤 함수
			srand((unsigned int)time(NULL));
			cpuInput = rand() % 3;
			result = CpuInputProc(selectNum, cpuInput);
			//결과
			if (result ==-1)
			{
				printf("전적 : %d 승 %d 무", win, draw);
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
//과제 6
	{
		char Matrix[3][3] = { 0 };
		char slot[10] = { '1','2','3','4','5','6','7',' ','8' };
		char slotselect[10]={ ' ','1','2','3','4','5','6','7','8' };
		int randNum;
		int count = 0;
		//임시 변수 값 변경용
		char temp=0;
		//입력 정보
		int row;
		int col;
		//생성
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//정답 확인용
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
			//출력
			PrintMatrix(Matrix);
			printf("위치 입력 (행,열) :");
			scanf("%d %d", &row, &col);
			if (row <= 2 &&  row >= 0)//예외 처리
			{
				if (col <= 2 && col >= 0)//예외 처리
				{
					//변경&변경불가능
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
					//결과
					if (temp == 0)
					{
						printf("변경 실패 빈칸 주변의 행,열을 입력하세요\n");
					}
					else if (temp == ' ')
					{
						printf("빈칸을 제외하고 입력해주세요\n");
						temp = 0;
					}
					else
					{
						printf("변경 성공\n");
						if (CheckResult(Matrix) == 1)
						{
							printf("정렬 성공 프로그램 종료");
							break;
						}
						temp = 0;
					}
				}
				else
				{
					printf("제대로된 숫자를 입력해주세요 (열 입력 오류)\n");
				}
			}
			else
			{
				printf("제대로된 숫자를 입력해주세요 (행 입력 오류)\n");
			}
			
		}
	}

	
#endif
}
