#include "E04.h"

//#define E04_INHERITANCE	1
//#define E04_PRACTICE		2
#define E04_POLYMORPHISM	3

namespace E04Space
{
#if E04_INHERITANCE
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

	public:
		//������
		CParent(int a_nValue, float a_fValue)
			:
			m_nValue(a_nValue),
			m_fValue(a_fValue)
		{
			printf("Cparent(int,float)�θ�Ŭ���� ������ ȣ��\n");
		}
		//�Ҹ���
		~CParent(void)
		{
			printf("Cparent(int,float) �θ�Ŭ���� �Ҹ��� ȣ��\n");
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
	public:
		/*
		Ŭ������ ��� �����϶� �������� �ùٸ� ȣ�� ������ �θ� Ŭ�������� �ڽ� ������ ȣ��Ǵ� ���̴�. ���� �θ� Ŭ������ �����ڸ� ȣ���ϴ� ������ �������� ���
		�����Ϸ��� ���ؼ� �ڵ����� �θ� Ŭ������ �⺻ �����ڸ� ȣ���ϴ� ������ �߰� �ȴ�.

		���� �θ� Ŭ������ �⺻ �����ڰ� �������� ���� ���
		�ݵ�� �ڽ� Ŭ������ �����ڸ� �ɹ� �̴ϼȶ����� ������ ���ؼ� �θ�Ŭ������ �����ڸ� ������� ȣ��������Ѵ�
		*/
		//������
		CChild(void) : CChild(0, 0.0f, "")//�θ�Ŭ���� ���� �־�� �ϱ⶧���� �̷��� �ڽ� ��ü���� ���� �ؾ��� ���� ������ ���
		{
			printf("Cchild(void)�ڽ�Ŭ���� ������ ȣ��\n");
		}
		CChild(int a_nValue, float a_fValue, const char *a_pszString)
			:
			CParent(a_nValue, a_fValue)
		{
			strcpy(m_szString, a_pszString);
			printf("Cchild(int,float,const char*)�ڽ�Ŭ���� ������ ȣ��\n");
		}
		/*
		Ư�� Ŭ���� ��� ���迡 ������ �Ҹ����� ȣ�� ������ �����ڿ� �޸� �ڽ� Ŭ�������� �θ� ������ ȣ��ȴ�
		*/
		//�Ҹ���
		~CChild(void)
		{
			printf("Cchild(void)�ڽ�Ŭ���� �Ҹ��� ȣ��\n");
		}
	private:
		char m_szString[100] = "";
	};
#elif E04_PRACTICE
	//�迭
	class CArray
	{
	public:
		enum
		{
			DEF_SIZE = 5
		};
	public: //operator
		/*
		�̹� ������ �Ϸ�� ��ü�� �ٸ� ��ü�� ������ �����ϱ� ���ؼ��� �Ҵ� ������ �����ε� �̶�� �ϴ� Ư���� �ɹ� �Լ��� �����ؾ��Ѵ�

		�ش� �Լ� ���� �����Ϸ��� ���ؼ� �ڵ����� ��������� �Լ� 
		�Ҵ翬���� �����ε��� �������� ���� ��� �����Ϸ��� �ڵ����� ���� ���縦 �����ϴ� �ش� �Լ��� �߰� �Ѵ�.
		*/
		CArray& operator=(const CArray &a_rOther)//��ü�� ������� �����ڸ� �����ְ� ����� �κ� 
		{
			SAFE_DELETE_ARRAY(m_pnValues);
			
			m_nSize = a_rOther.m_nSize;
			m_nNumValues = a_rOther.m_nNumValues;

			m_pnValues = new int[a_rOther.m_nSize];
			memcpy(m_pnValues, a_rOther.m_pnValues, sizeof(int)*a_rOther.m_nSize);

			/*
			c++ ��� �ɹ� �Լ����� �ش� �Լ��� ȣ���� ��ü�� ����Ű�� this �����Ͱ� ���� �ȴ�
			this �����ʹ� ���� �ش��Լ��� ȣ���� ��ü�� ����Ű�� �뵵�̸� �ش� �����Ͱ� �����ϱ� ������ �ɹ� �Լ����� �ɹ� ������ �����ϴ� ���� �����ϴ�
			->�� �����Ϳ��� ���� �����Ҷ� �ο��� 
			*/
			return *this;
		}

	public:
		/*
		c++Ŭ���� �ɹ��Լ��� const Ű���带 ����Ͽ� �ش��Լ��� 
		��� �ɹ� �Լ��� ���� �ϴ� ���� �����ϴ�

		��� �ɹ� �Լ���?
		�Լ� ���ο��� �ɹ� ������ �����Ҽ����� �Լ��� ��� �ɹ� �Լ���� �Ѵ�
		�� �ش� �Լ��� ��ü�� ����� ��� �����Ϸ����� �ش� �Լ� ���ο����� 
		���� ������ �߻����� �ʴ´ٴ� ������ �ϱ� ���� �뵵�̴�.
		
		���� ��� ��ü�� �Ϲ����� �ɹ� �Լ��� ȣ�� �� �� ������ ��� �ɹ� �Լ��� ȣ���� �����ϴ� 
		�̴� �Ϲ����� �ɹ��Լ� ������ �ɹ� ������ �����Կ� �־ �߻��ϴ� ���� ����� �����ϱ� ���Ѱ��̴�.
		*/
		//���� ������ ��ȯ
		int GetNumValues() const
		{
			return m_nNumValues;
		}
		//���� ��ȯ�Ѵ�
		int GetValue(int a_nIdx)const
		{
			return m_pnValues[a_nIdx];
		}
		//���� �����Ѵ�
		void SetValue(int a_nIdx, int a_nValue)
		{
			m_pnValues[a_nIdx] = a_nValue;
		}
		//���� �߰��Ѵ�
		void AddValue(int a_nValue)
		{
			//�迭�� ���� á�� ���
			if (m_nNumValues >= m_nSize)
			{
				m_nSize *= 2;
				m_pnValues = (int *)realloc(m_pnValues, sizeof(int)*m_nSize);
			}

			m_pnValues[m_nNumValues++] = a_nValue;
		}


	public://������ �Ҹ���
		/*
		c++�� �Լ��� �Ű� ������ ���� �� ��� �ش� �Ű� ������ �Է� �� ���� �Լ��� ȣ���ϴ� ���� �����ϴ�
		�� �ش� ������ ������ ������ �Լ��� �Է� ���� ���� ��� �ڵ����� �⺻���� ������ �� �ִ� ����Ʈ �Ű� ������ �����ϱ� �����̴�
		
		Ư�� �Լ��� �Է��� ���� ���� �ʾ��� ��� �ش� �Ű������� �Ҵ� ���� �����Ҽ��ִ� ����� �ǹ��Ѵ�.
		�Ϲ� �Ű������� ȥ�� ����� ���������� Ư�� �Ű� ������ ����Ʈ ���� �Ҵ�������쿡�� �ش� �Ű����� ���� ���ʹ� ����Ʈ ���� ���������Ѵ�.
		*/
		//CArray(int a_nParams1,int a_nSize = DEF_SIZE,int a_nParams2) �̰� ������ 
		CArray(int a_nSize = DEF_SIZE)
		:
		m_nSize(a_nSize)
		{
			m_pnValues = new int[a_nSize];
			memset(m_pnValues, 0, sizeof(int)*a_nSize);
		}
		//���� ������
		CArray(const CArray &a_rOther)
		{ 
			*this = a_rOther;
		}


		~CArray()
		{
			SAFE_DELETE_ARRAY(m_pnValues);

		}

	private://����
		int m_nSize;
		int m_nNumValues;

		int *m_pnValues = nullptr;
	};

	//�迭 ���
	void PrintArray(const CArray a_oArray)
	{
		for (int i = 0; i < a_oArray.GetNumValues(); ++i)
		{
			printf("%d ", a_oArray.GetValue(i)) ;
		}
		printf("\n");
	}
	


#elif E04_POLYMORPHISM
	//�θ�Ŭ����
	class CParent
	{

	};
	//�ڽ�Ŭ����
	class CChild:public CParent
	{

	};
#endif // E04_INHERITANCE

	void E04(const int argc, const char ** args)
	{
	#if E04_INHERITANCE
		CChild oChild;
		oChild.PrintInfo(); 

	#elif E04_PRACTICE
		CArray oArrayA;

		for (int i = 0; i < 10; ++i)
		{
			oArrayA.AddValue(i + 1);
		}

		CArray oArrayB(oArrayA);
		CArray oArrayC;

		oArrayC = oArrayA;

		printf("\narray a\n");
		PrintArray(oArrayA);
		printf("\narray b\n");
		PrintArray(oArrayA);
		printf("\narray c\n");
		PrintArray(oArrayA);
	#elif E04_POLYMORPHISM
		/*
		�θ� Ŭ������ �����ͷ� �ڽ� ��ü�� ����Ű�� ���� �������� �ݴ�� �ڽ� Ŭ������ �����ͷ� �θ� ��ü�� ����Ű�� ���� �Ұ��� �ϴ�
		*/
		CParent *pParentA = new CParent();
		CParent *pParentB = new CChild();

		CChild *pChildA = new CChild;
		//CChild *pChildB = new CParent;

		SAFE_DELETE(pParentA);
		SAFE_DELETE(pParentB);
		SAFE_DELETE(pChildA);
	#endif // E04_INHERITANCE
	}
}
