#include "E11.h"

//#define E11_TEXT_IO	1
#define E11_BINARY_IO	2

typedef unsigned char BYTE;


void E11(int argc, char ** args)
{
#if E11_TEXT_IO
	/*
	w�� ��������� ��Ʈ�� ����� �������� ������ ���� ���� ��� ����� ��Ʈ���� �����ϴ� �ݸ�
	a�� �������� ��� ������ ���� ������ ������ ���¿��� ��Ʈ���� �����Ѵ�.
	���� �� ��� ��� ���� ������ �������� ���� ��� ���ϻ����ϴ� ���ҵ� ����

	�ؽ�Ʈ ��� vs ������� �����
	���� �ý��ۿ��� �ؽ�Ʈ ���� ���� ����� ������
	\n���๮���� �߻� �����̴� �ؽ�Ʈ ����� ��� ���� ���ڸ� ����� ��� �ش� ���� ���ڸ�
	\r\n\���� ������Ű�� �ݴ�� �о���� ���� �ش� ���ڸ� �ٽ� ���� ���ڷ� ������Ű�� ������ �߻��Ѵ�
	���� ��� ������� ���������͸� ���� �������� �ʱ� ������ �����ϰ� ���� ���·� �����ϰų� �о���̱� ���ؼ� ������带 ����Ѵ�
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
			fgets �Լ��� ���Ͽ��� ���̻� �о���� ���ڿ��� �������� ���� ��� Null�����͸� ��ȯ�ϱ� ������
			�ش������� �������� ������ ��� ������ �о���̴� �ݺ����� �����ϴ� ���� �����ϴ�
			*/
			while (fgets(szString, sizeof(szString), pstRStream) != NULL)//��� null�� ���Ͽ� ���� ������ ����
			{
				//���๮�ڰ� �����Ұ�� ������ ���ֱ� ���ؼ� ��� �Ϲ������� �ι��ڴ� �о�ü�����
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

	/*
	��� ������Ʈ���� ���� ���� ��ɾ� �Է� ���
	���α׷� �̸� + �������� ��� +�纻���� ���
	ex)
	Example Example.exe CopyExample2.exe
	*/
	//�Ű������� �߸� �ԷµǾ��� ���
	if (argc < 3)
	{
		printf("�Ű������� �߸� �Է� �Ǿ����ϴ�.\n");
	}
	
	FILE *pstRStream = fopen(args[1], "rb");
	FILE *pstWStream = fopen(args[2], "wb");

	//��Ʈ���� �����Ǿ��� ���
	if (pstRStream != NULL && pstWStream != NULL)
	{
		size_t nNumBytes = 0;
		BYTE anBuffer[100] = {0};

		while (1)
		{
			nNumBytes=fread(anBuffer, sizeof(BYTE), sizeof(anBuffer), pstRStream);
			//���̻� ���� �����Ͱ� ���� ���
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
