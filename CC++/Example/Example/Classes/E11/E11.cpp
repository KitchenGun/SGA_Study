#include "E11.h"

//#define E11_TEXT_IO	1
#define E11_BINARY_IO	2

typedef unsigned char BYTE;


void E11(int argc, char ** args)
{
#if E11_TEXT_IO
	/*
	w로 쓰기용으로 스트림 개방시 기존파일 존재지 파일 내용 모두 지우고 스트림을 생성하는 반면
	a로 지정했을 경우 기존의 파일 내용을 보존한 상태에서 스트림을 생성한다.
	또한 두 모드 모두 만약 파일이 존재하지 않을 경우 파일생성하는 역할도 수행

	텍스트 모드 vs 이진모드 입출력
	파일 시스템에서 텍스트 모드와 이진 모드의 차이점
	\n개행문자의 발생 유무이다 텍스트 모드일 경우 개행 문자를 출력할 경우 해당 개행 문자를
	\r\n\으로 변형시키며 반대로 읽어들일 때는 해당 문자를 다시 개행 문자로 변형시키는 연산이 발생한다
	이진 모드 입출력은 원본데이터를 전혀 변형하지 않기 때문에 온전하게 원본 상태로 저장하거나 읽어들이기 위해서 이진모드를 사용한다
	*/
	FILE *pstWStream = fopen("Resources/E11_01.txt", "at");
	if (pstWStream != NULL)
	{
		for (int i = 0; i < 10; ++i)
		{
			fprintf(pstWStream, "hi \n");
		}
		fclose(pstWStream);
	}

	//\n <=> \r\n    

	FILE *pstRStream = fopen("Resources/E11_01.txt", "rt");
	if (pstRStream != NULL)
	{
		for (int i = 0; i < 10; ++i)
		{
			char szString[100] = "";
			/*
			fgets 함수는 파일에서 더이상 읽어들일 문자열이 존재하지 않을 경우 Null포인터를 반환하기 때문에
			해당조건을 기준으로 파일의 모든 내용을 읽어들이는 반복문을 구성하는 것이 가능하다
			*/
			while (fgets(szString, sizeof(szString), pstRStream) != NULL)//결과 null은 파일에 읽을 내용이 없다
			{
				//개행문자가 존재할경우 개행을 없애기 위해서 사용 일반적으로 널문자는 읽어올수있음
				if (szString[strlen(szString) - 1] == '\n')
				{
					szString[strlen(szString) - 1] = '\0';
				}
				printf("%s", szString);
			}
		}
		fclose(pstWStream);
	}
#elif E11_BINARY_IO
	//명령인수 사용법
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", args[i]);
	}

	/*
	명령 프롬포트에서 파일 복사 명령어 입력 방식
	프로그램 이름 + 원본파일 경로 +사본파일 경로
	ex)
	Example Example.exe CopyExample2.exe
	*/
	//매개변수가 잘못 입력되었을 경우
	if (argc < 3)
	{
		printf("매개변수가 잘못 입력 되었습니다.\n");
	}
	
	FILE *pstRStream = fopen(args[1], "rb");
	FILE *pstWStream = fopen(args[2], "wb");

	//스트림이 생성되었을 경우
	if (pstRStream != NULL && pstWStream != NULL)
	{
		/*
		특정 파일의 크기를 계산하기 위해서는 fseek,ftell 함수를 사용하면 된다
		ftell 함수는 파일 커서의 위치를 가져오는 역할을 수행하기 때문에 fseek함수를
		사용해서 파일의 커서를 가장 마지막 위치로 옮긴후 해당함수를 사용하면 파일의 크기를 가져오는 것이 가능하다 
		자료형을 읽는 방식은 확장자에서 정해준다
		*/
		fseek(pstRStream, 0, SEEK_END);
		printf("파일 크기 :%d", ftell(pstRStream));
		fseek(pstRStream, 0, SEEK_SET);
		size_t nNumBytes = 0;
		BYTE anBuffer[100] = {0};

		fseek(pstRStream, 0, SEEK_CUR);//

		/*
		fread를 포함한 파일 제어함수들은 내부적으로 파일의 데이터 제어 위치를 나타내는 파일 커서 정보를 기반으로 작동한다.
		파일 커서 정보를 기반으로 작동한다 만약 해당 커서의 정보를 수동적으로 변경하기 위해서는 fseek 함수를 사용한다
		fseek 종류
		seek_set 파일 첫번째 데이터
		seek_cur 파일 현재 커서 위치
		seek_end 파일 마지막 데이터
		*/

		while (1)
		{
			//파일 구조체 안의 커서를 통해서 정보를 읽어들임 
			nNumBytes=fread(anBuffer, sizeof(BYTE), sizeof(anBuffer), pstRStream);
			//더이상 읽을 데이터가 없을 경우
			if (feof(pstRStream))
			{
				//특정 파일에서 읽어들일 데이터의 유무를 판단하기 위해서는 fread fgets함수의 반환값을 사용해도 되지만 
				//feof함수를 통ㅎ새서 이를 판단하는 것이 가능하다
			}

			if (nNumBytes <= 0)
			{
				break;
			}

			fwrite(anBuffer, sizeof(BYTE), nNumBytes, pstWStream);
		}

		fclose(pstRStream);
		fclose(pstWStream);
	}

#endif // E11_TEXT_IO

	

}
