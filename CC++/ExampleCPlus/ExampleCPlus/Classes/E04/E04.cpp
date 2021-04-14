#include "E04.h"
namespace E04Space
{
	//�θ�Ŭ����
	class CParent
	{
	public:
		/*
		�θ�Ŭ������ �ڽ� Ŭ������ ���� �ٸ� �����̱� ������ ������ ������ ���ϴ� �Լ��� �����ϴ� ���� �����ϴ� 
		�̶� �켱������ �ڽ� Ŭ������ ���� �Ǿ��ִ� �Լ��� �� ���� �켱������ ������ 
		���� �ڽ� Ŭ������ �Լ� ���ο��� �θ� Ŭ������ ������ �̸��� ���ϴ� �Լ��� ȣ���ϰ� �ʹٸ� :: ���� ���������ڸ� ����ϸ� �ȴ�
		*/
		//������ ����Ѵ�
		void PrintInfo()
		{
			printf("�θ�ü ����\n");
			printf("int : %d\n", m_nValue);
			printf("float : %f\n", m_fValue);
		}
	protected:
		int m_nValue = 0;
		float m_fValue = 0.0f;
	};
	//�ڽ� Ŭ����
	class CChild : public CParent
	{
	public:
		//������ ���
		void PrintInfo()
		{
			CParent::PrintInfo();
			printf("\n�ڽİ�ü ����\n");
			printf("string : %s\n", m_szString);
		}
	private:
		char m_szString[100] = "";
	};

	void E04(const int argc, const char ** args)
	{
		CParent oParent;
		oParent.PrintInfo();

		CChild oChild;
		oChild.PrintInfo(); 

	}
}
