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
	printf("��� : %d ��Ʈ����ũ, %d �� \n", s,b);
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
	printf("���ھ߱� ���ڻ���\n");
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
	printf("������ �����մϴ�.");
	return true;
}


#elif P3
typedef struct  User
{
	int flag;//0�̸� null 1�̸� ����
	char sName[20];
	char sPhone[20];
	int age;
}User;
User userlist[20] = {0};
int Size = sizeof(userlist) / sizeof(User);
void PrintInit()
{
	printf("\n===== �޴� =====\n");
	printf("1. ȸ�� �߰�\n");
	printf("2. ȸ�� ����\n");
	printf("3. ȸ�� �˻�\n");
	printf("4. ��� ȸ�� ���\n");
	printf("5. ����\n");
	printf("�޴� ���� : ");
}

void InsertUser()
{
	printf("\n");
	User newUser;
	newUser.flag = 1;
	printf("�̸� : ");
	scanf("%s", &newUser.sName);
	getchar();
	printf("��ȭ��ȣ : ");
	scanf("%s", &newUser.sPhone);
	getchar();
	printf("���� : ");
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
	printf("�̸� : ");
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
				printf("%s(��)�� �����߽��ϴ�.\n", sUserName);
				isThereUser = true;
				break;
			}
			else
			{
				printf("%s(��)�� ȸ���� �ƴմϴ�.\n", sUserName);
				break;
			}
		}
	}
	if (!isThereUser)
	{
		printf("%s(��)�� ȸ���� �ƴմϴ�.\n");
	}
}

void SearchUser()
{
	bool isThereUser = false;
	printf("\n");
	char sUserName[20];
	printf("�̸� : ");
	scanf("%s", &sUserName);
	getchar();

	for (int i = 0; i < Size; i++)
	{
		if (userlist[i].flag == 1)
		{
			printf("\n===== ȸ�� �˻� ��� =====\n");
			if (strcmp(userlist[i].sName, sUserName) == 0)
			{
				printf("\n�̸� : %s\n��ȭ��ȣ : %s\n���� : %d\n", userlist[i].sName, userlist[i].sPhone, userlist[i].age);
				isThereUser = true;
			}
		}
	}
	if (!isThereUser)
	{
		printf(" %s(��)�� ȸ���� �ƴմϴ�.\n", sUserName);
	}
}

void PrintAll()
{
	printf("\n===== ��� ȸ�� ���� =====\n");
	for (int i = 0; i < 20; i++)
	{
		if (userlist[i].flag == 1)
			printf("\n�̸� : %s\n��ȭ��ȣ : %s\n���� : %d\n",userlist[i].sName, userlist[i].sPhone, userlist[i].age);
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
	//���� 
	SetRandomNum(pArray);
	//���� ��¿�
	//Print(pArray);
	//�ݺ���
	do
	{
		s = 0;
		b = 0;
		printf("���� (4��) �Է� : ");
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
	//���� ����
	int nIndex = rand() % 5;
	char *sAnswer = pWordArray[nIndex];
	Size = strlen(sAnswer);
	PrintInit(sAnswer);
	printf("\n");
	//�Է�
	bool check[10] = {false};
	check[0] = check[Size - 1] = true;
	while (!CheckResult(check))
	{
		printf("���ڿ� �Է� : ");
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
			printf("���α׷��� �����մϴ�.");
			return;
			break;
		}

		default:
			break;
		}
	}
	
#endif // P1

	
}
