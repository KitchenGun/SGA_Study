#include "P02.h"
//#define P1 1
//#define P2 2
#define P3 3


#if P1
int s = 0;
int b = 0;

void Search(int* a_pArray, int* a_pPlayerArray)
{
	for (int i = 0; i < 4; i++)
	{
		if (a_pArray[i] == a_pPlayerArray[i])
		{
			s++;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				if (a_pArray[i] == a_pPlayerArray[j])
				{
					b++;
					break;
				}
			}
		}
	}

}
void PrintResult()
{
	printf("결과 : %d 스트라이크, %d 볼 \n", s,b);
}

void Print(int* a_pArray)
{
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", a_pArray[i]);
	}
}
void SetRandomNum(int* a_pArray)
{
	printf("숫자야구 숫자생성\n");
	for (int i = 0; i < 4; i++)
	{
		a_pArray[i]=rand()%10;
		for (int j = 0; j < i; j++)
		{
			if (a_pArray[i] == a_pArray[j])
			{
				i--;
				break;
			}
		}
	}
}
#elif P2
int Size;

void PrintInit(char* a_sAnswer)
{
	printf("%c", a_sAnswer[0]);
	for (int i = 0; i < Size - 2; i++)
	{
		printf("_");
	}
	printf("%c", a_sAnswer[Size - 1]);

}
bool CheckResult(bool*a_check)
{
	for (int i = 0; i < Size; i++)
	{
		if (a_check[i] == false)
		{
			return false;
		}
	}
	printf("게임을 종료합니다.");
	return true;
}


#elif P3
typedef struct  User
{
	int flag;//0이면 null 1이면 존재
	char sName[20];
	char sPhone[20];
	int age;
}User;
User userlist[20] = {0};
int Size = sizeof(userlist) / sizeof(User);
void PrintInit()
{
	printf("\n===== 메뉴 =====\n");
	printf("1. 회원 추가\n");
	printf("2. 회원 삭제\n");
	printf("3. 회원 검색\n");
	printf("4. 모든 회원 출력\n");
	printf("5. 종료\n");
	printf("메뉴 선택 : ");
}

void InsertUser()
{
	printf("\n");
	User newUser;
	newUser.flag = 1;
	printf("이름 : ");
	scanf("%s", &newUser.sName);
	getchar();
	printf("전화번호 : ");
	scanf("%s", &newUser.sPhone);
	getchar();
	printf("나이 : ");
	scanf("%d", &newUser.age);
	for (int i = 0; i < Size; i++)
	{
		if (userlist[i].flag == 0)
		{
			userlist[i] = newUser;
			break;
		}
	}
	printf("\n");
}

void DeleteUser()
{
	bool isThereUser = false;
	printf("\n");
	char sUserName[20];
	printf("이름 : ");
	scanf("%s", &sUserName);
	getchar();

	for (int i = 0; i < Size; i++)
	{
		if (userlist[i].flag == 1)
		{
			if (strcmp(userlist[i].sName, sUserName) == 0)
			{
				userlist[i].flag = 0;
				strcpy(userlist[i].sName, "");
				strcpy(userlist[i].sPhone, "");
				userlist[i].age = NULL;
				printf("%s(을)를 삭제했습니다.\n", sUserName);
				isThereUser = true;
				break;
			}
			else
			{
				printf("%s(은)는 회원이 아닙니다.\n", sUserName);
				break;
			}
		}
	}
	if (!isThereUser)
	{
		printf("%s(은)는 회원이 아닙니다.\n");
	}
}

void SearchUser()
{
	bool isThereUser = false;
	printf("\n");
	char sUserName[20];
	printf("이름 : ");
	scanf("%s", &sUserName);
	getchar();

	for (int i = 0; i < Size; i++)
	{
		if (userlist[i].flag == 1)
		{
			printf("\n===== 회원 검색 결과 =====\n");
			if (strcmp(userlist[i].sName, sUserName) == 0)
			{
				printf("\n이름 : %s\n전화번호 : %s\n나이 : %d\n", userlist[i].sName, userlist[i].sPhone, userlist[i].age);
				isThereUser = true;
			}
		}
	}
	if (!isThereUser)
	{
		printf(" %s(은)는 회원이 아닙니다.\n", sUserName);
	}
}

void PrintAll()
{
	printf("\n===== 모든 회원 정보 =====\n");
	for (int i = 0; i < 20; i++)
	{
		if (userlist[i].flag == 1)
			printf("\n이름 : %s\n전화번호 : %s\n나이 : %d\n",userlist[i].sName, userlist[i].sPhone, userlist[i].age);
	}
}

#endif // P1




void P02(const int argc, const char** args)
{
#if P1
	srand((unsigned int)time(NULL));
	int nArray[4] = { 0 };
	int* pArray = nArray;
	int nPlayerArray[4] = { 0 };
	//랜덤 
	SetRandomNum(pArray);
	//정답 출력용
	//Print(pArray);
	//반복문
	do
	{
		s = 0;
		b = 0;
		printf("숫자 (4개) 입력 : ");
		scanf("%d %d %d %d", &nPlayerArray[0], &nPlayerArray[1], &nPlayerArray[2], &nPlayerArray[3]);
		Search(pArray, nPlayerArray);
		PrintResult();
	} while (s != 4);
#elif P2
	srand((unsigned int)time(NULL));
	char sWord1Array[] = "Apple";
	char sWord2Array[] = "Orange";
	char sWord3Array[] = "House";
	char sWord4Array[] = "Rifle";
	char sWord5Array[] = "Fight";
	char* pWordArray[] = { sWord1Array,sWord2Array ,sWord3Array,sWord4Array,sWord5Array };
	char cInputValue;
	//랜덤 선택
	int nIndex = rand() % 5;
	char *sAnswer = pWordArray[nIndex];
	Size = strlen(sAnswer);
	PrintInit(sAnswer);
	printf("\n");
	//입력
	bool check[10] = {false};
	check[0] = check[Size - 1] = true;
	while (!CheckResult(check))
	{
		printf("문자열 입력 : ");
		scanf("%c", &cInputValue);
		getchar();
		for (int i = 1; i < Size-1; i++)
		{
			if (sAnswer[i] == cInputValue)
			{
				check[i] = true;
			}
		}
		for (int i = 0; i < Size; i++)
		{
			if (check[i] == true)
			{
				printf("%c", sAnswer[i]);
			}
			else
			{
				printf("_");
			}
		}
		printf("\n");
	}
	
#elif P3
	int nSelectNum;
	while (true)
	{
		PrintInit();
		scanf("%d", &nSelectNum);
		switch (nSelectNum)
		{
		case 1:
		{
			InsertUser();
			break;
		}
		case 2:
		{
			DeleteUser();
			break;
		}
		case 3:
		{
			SearchUser();
			break;
		}
		case 4:
		{
			PrintAll();
			break;
		}
		case 5:
		{
			printf("프로그램을 종료합니다.");
			return;
			break;
		}

		default:
			break;
		}
	}
	
#endif // P1

	
}
