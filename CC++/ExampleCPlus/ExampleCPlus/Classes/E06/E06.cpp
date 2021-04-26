#include "E06.h"

namespace E06Space
{
	//�迭
	class CArray
	{
	public:
		enum
		{
			DEF_SIZE = 5
		};
	public:
		/*
		���࿡ []=�� ǥ���ϰ� ������
		operator[] ���ο���operator=�� ȣ���ϵ��� �����ؾ��Ѵ�
			oArray[i]=

			c++Ŭ������ ���� Ŭ������ �ɹ� �Լ��ϰ� ��� �ɹ� �Լ� ���� �Ϲ����� �ɹ� �Լ������� ���� ������ ������� �Լ� �����ε��� �����Ѵ�
			�� �ɹ� �Լ��� ��� ���� ���� ���� �Լ� �����ε��� ������ �ϳ��̴�.
			���� �ش� Ư¡�� �� Ȱ���ϸ� ������ ���� ����� ��ü�� �����ڸ� ����ϴ� ���� �����ϴ�

		���� �ɹ� �Լ��� �Ϲ� ������ ��� ���� ��� ȣ���� ������ ���
		�켱 ������ �Ϲ� �ɹ� �Լ��� �� ���� ������ �ش� ��쿡�� �Ϲ� �ɹ� �Լ��� ȣ��ȴ�
		*/
		//operator[]
		//���۷���
		int & operator[](const int a_nIdx)
		{
			/*
			�� ���� ������ �� �ɹ� ���� �����ڸ� ���ÿ� ������� ��� �Ϲ�������
			���� �ɹ� ������ �ؼ� �ǰ� ������ �����ڰ� �ؼ��� �ȴ�
			���� �Ʒ��� ��� this ��ü�� �ɹ��� ����Ű�� ���� �����ض� ��� ������ �ؼ��� �ȴ�
			//*this.n_nNumValues=10;
			
			�ݸ� �Ʒ��� ��� ()(�켱 ���� ������)�� ���ؼ� ������ �����ڸ� ���� �ؼ��ǰ� �켱 ������ �����߱� ������ �ش� ������ �����Ϸ��� ���ؼ�
			this �����Ͱ� ����Ű�� ��ü �Ǵ� ����ü�� �ɹ� m_nNumValues�� �����ض�� ������ �ؼ��� �ȴ�
			//(*this).n_nNumValues=10;
			�ɹ� ���� ������ ��� ������ �ɹ� ���� �����ڸ� ���������
			�ɹ� ���� �����ڸ� ����������� ������ �ɹ� ���� �����ڰ� ���� �ؼ��� �� ������ �����ڰ� �ؼ� �ȴ�
			�� ������ �ɹ� ���� ������ ���� ������ ������ ���� �켱 ������ ����
			//*this->n_nNumValues=10;
			*/
			return m_pnValues[a_nIdx];
		}
		//operator[]
		//���۷��� x
		int operator[](const int a_nIdx) const
		{
			/*
			��� �ɹ� �Լ����� �����ε��� �Ϲ� �ɹ� �Լ��� ȣ���ϱ� ���ؼ���
			�ش� ��ü�� ���ϰ� �ִ� ������� �Ͻ������� ���� ��Ų �� �ش��Լ��� ȣ���ϸ�ȴ�
			�� ��ü�� ����� ���� �Ǿ��� ������ �Լ� �����ε� ȣ�� �켱 ������ ����
			��������� �Լ��� �ƴ϶� �Ϲ� �ɹ��Լ��� ȣ���� �ȴ�
			*/
			//case 1 ���۷��� ������ ��ȯ�� ������ ���
			return const_cast<CArray &>(*this)[a_nIdx];
			//return const_cast<CArray &>(*this).operator[](a_nIdx); ���� ������ �̰� ó�� �ؼ��� �ȴ�
		
			//case 2 �����ͷ� ��ȯ �� ������ �����ε� �� �Լ� ���� ȣ�� 
			return const_cast<CArray*>(this)->operator[](a_nIdx);
		}
		
		//operator
		CArray& operator=(const CArray &a_rOther)//��ü�� ������� �����ڸ� �����ְ� ����� �κ� 
		{
			SAFE_DELETE_ARRAY(m_pnValues);

			m_nSize = a_rOther.m_nSize;
			m_nNumValues = a_rOther.m_nNumValues;

			m_pnValues = new int[a_rOther.m_nSize];
			memcpy(m_pnValues, a_rOther.m_pnValues, sizeof(int)*a_rOther.m_nSize);

			return *this;
		}

	public:
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
	////operator[]
	//static int operator[](const CArray &a_rArray, int a_nIdx)
	//{
	//�� �����Լ� ���� ������ �����ε��� �ɹ� �Լ������� �޸� ����Ҽ��ִ� �������� ������ ���ѵǾ��ֱ� ������ �ش���׿� �����ؼ� ���� �Լ� ������ �����ؾ��Ѵ�
	//}

	/*
	c++���� ���� �Լ��� ���ؼ� ������ �����ε��� �Ҽ��ִ� ����� �����Ѵ� 
	�̴� �̹� �ϼ��Ǿ� �����Ǵ� Ŭ������ ������� ������ �����ε� �Ҽ��ְ� ��� ��������
	�����Ǵ� ����̴�
	�� �ɹ��Լ��� ���� ������ �����ε��� �ش� Ŭ������ ���������� �����Ҷ��� ����ϴ� ���� ����������
	�̹� �ϼ��Ǿ� ���̺귯�� ���·� �����Ǵ� Ŭ�������� �ɹ� �Լ��� ���� ������ �����ε��� ����ϴ� ���� �Ұ����ϴ�
	*/
	//operator<<
	std::ostream & operator<<(std::ostream &a_rStream, const CArray &a_rArray)
	{
		for (int i = 0; i < a_rArray.GetNumValues(); ++i)
		{
			printf("%d ", a_rArray[i]);
		}
		return a_rStream;
	}

	void E06(const int argc, const char ** args)
	{
		CArray oArray;

		for (int i = 0; i < 10; ++i)
		{ 
			oArray.AddValue(i + 1);
		}
		for (int i = 0; i < oArray.GetNumValues(); ++i)
		{
			oArray[i] *= 10;
		}
		printf("�迭 ���\n");
		for (int i = 0; i < oArray.GetNumValues(); ++i)
		{
			printf("%d ", oArray[i]);
		}
		printf("\n");
		std::cout << oArray << std::endl;
	}
}
