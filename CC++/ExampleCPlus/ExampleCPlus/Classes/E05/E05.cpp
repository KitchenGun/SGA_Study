#include "E05.h"

//#define E05_CLASS_MEM	1
#define E05_SINGLETON	2
#if E05_SINGLETON
#define SINGLETON_CASE_A	1
#define SINGLETON_CASE_B	2
#endif // E05_SINGLETON


namespace E05Space
{
#if E05_CLASS_MEM
	//����
	class CWidget
	{
	public:
		//�� ��ȯ
		int GetValue(void)const
		{
			return m_nValueA;
		}
		//�� ����
		void SetValue(int a_nValue)
		{
			m_nValueA = a_nValue;
		}
		//�� �߰�
		void AddValue(int a_nValue)
		{
			m_nValueB += a_nValue;
		}
		static int GetConstMemValue(void)
		{
			return m_nValueB;
		}

		/*
		Ŭ���� �Լ� ���ο����� �Ϲ����� �ɹ� ���� �� �Լ��� ����ϴ� ���� �Ұ��� �ϴ�

		�̴� �ɹ� ���� �� �Լ��� ������ؼ� Ư�� ��ü�� ���� ����� �ϱ⶧���̴�
		�� Ŭ���� �Լ����ο����� Ư�� ��ü�� �����ϱ� ���� this �����Ͱ� ���޵��� �ʴ´�
		*/
		//������ ����Ѵ� Ŭ���� �ɹ� �Լ�
		static void ShowInfo(void)
		{
			//m_nValueA;
			printf("widgetȣ��\n");
		}
	private:
		int m_nValueA = 0;
		static int m_nValueB;
	};
	/*
	Ŭ���� ������ �Ϲ����� �ɹ� ������ �޸� Ŭ���� ���ο� ������ ���ִ� �͸����� ����ϴ� ���� �Ұ��� �ϴ� ����
	�ش� Ŭ���� �ܺο��� �ݵ�� Ŭ���� ������ ���� �ʱ�ȭ�� ����� �ش� Ŭ���� ������ ���ǰ� �Ϸ�ȴ�.
	*/
	//class �ɹ� ����(static) �ʱ�ȭ
	int CWidget::m_nValueB = 0;


#elif E05_SINGLETON
#if SINGLETON_CASE_A

	//�̱��� ������ ������
	class CDataManager
	{
	public:
		struct STData
		{
			std::string m_oID;

			int m_nValue;
			float m_fValue;
		};
	public:
		//������ ��ȯ
		STData GetData(const std::string &a_rID)
		{
			int nIdx = this->FindData(a_rID);
			assert(nIdx >= 0);//�׻� 0���� ũ�ٴ� ���� �����ϰ� �ۼ�
			/*
			assert ��ũ�� �Լ��� ����ϸ� Ư�� ������ ���� �϶� ���α׷��� ���̻� �������� �ʰ� �ش� ���Ͽ� ���� ���� ���+���� ������ش�
			assert ��ũ�δ� �������� ������Ʈ������ �۵��ϸ� ������� (������� ���ϴ� �۾�)���� �۵����� �ʴ´� 
			*/
			// try catch ��ſ� ����� 


			return m_astDatas[nIdx];
		}
		//������ �߰�
		void AddData(const STData &a_rstData)
		{
			int nIdx = this->FindData(a_rstData.m_oID);
			//������ ������
			if (nIdx <= -1)
			{
				m_astDatas[m_nNumDatas++] = a_rstData;
			}
		}
		//������ ����
		void RemoveData(const std::string &a_rID)
		{
			int nIdx = this->FindData(a_rID);
			//������ �����
			if (nIdx >= 0)
			{
				for (int i = nIdx; i < m_nNumDatas - 1; ++i)
				{
					m_astDatas[i] = m_astDatas[i + 1];
				}
				m_nNumDatas -= 1;
			}
		}
		//������ Ž��
		int FindData(const std::string &a_rID)
		{
			for (int i = 0; i < m_nNumDatas; ++i)
			{
				if (m_astDatas[i].m_oID == a_rID)
				{
					return i;
				}
			}
			return -1;
		}
		//�ν��Ͻ� ��ȯ
		static CDataManager *GetInst(void)
		{
			//�ν��Ͻ� ���� ���Ұ��   
			/*
			�̱��� ������ ��������� �����Ǵ� ��ü�� 1���� ���� �����μ� ���� ������ ���������� ������ ��ü �� �����͸� �����ϴ� ���̴� ���� �Ϲ������� �̱���
			��ü�� �̸� �����ϴ� ���� �ƴ϶� �ش� ��ü�� �ʿ�� �ϴ� �߰� ������ �ȴ�
			�̸� Lazy Initialization
			������ �ʱ�ȭ ��ü ������ �ʱ�ȭ ����Ѵ�
			*/
			if (CDataManager::m_pInst == nullptr)
			{
				CDataManager::m_pInst = new CDataManager();

				/*
				CDataManager�� ���� �����ڸ� �����ΰ� ���� ������ �����ϱ� ������ �̴� �� �ش� Ŭ������ ���� ������ ��ü�� �����ϴ� ���� �Ұ����ϴٴ� ���� �ǹ��Ѵ�
				�� ��ü�� ���� �Ǳ� ���ؼ��� ���� �����ڰ� ȣ��Ǿ���ϴµ� ���� �������� �����ΰ� �������� �ʱ� ������ ��ũ ������ �߻��Ѵ�
				*/
				//CDataManager oDataManager(*CDataManager::m_pInst);
			}

			return CDataManager::m_pInst;
		}
		//�ν��Ͻ� ����
		static void DestroyInst(void)
		{
			//�ν��Ͻ� ������ ���
			if (CDataManager::m_pInst != nullptr)
			{
				SAFE_DELETE(CDataManager::m_pInst);
			}
		}
	private:
		CDataManager(void)
		{
			//do nothing
		}
		virtual ~CDataManager(void)
		{
			//do nothing
		}
		//��������� 
		CDataManager(const CDataManager &a_rOther);

	private:
		int m_nNumDatas = 0;
		STData m_astDatas[100];
		static CDataManager *m_pInst;
	};

	CDataManager *CDataManager::m_pInst = nullptr;
#elif SINGLETON_CASE_B
//�̱��� A
class CSingletonA 
{
public:
	//���� ���
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonA)
};
/*
:: ���� ���� �����ڸ� ����ϸ� Ŭ������ �ɹ��Լ��� Ŭ���� �ܺο� �����ϴ� ���� �����ϴ� �� �ش� �����ڸ� Ȱ���ϸ�
Ŭ������ ���� ������� Ŭ������ ���Ǵ� �ҽ����Ͽ� ���� Ư�� Ŭ������ �и��ؼ� �ڵ��ۼ��ϴ� ���� �����ϴ�
*/
//����&�Ҹ���
CSingletonA::CSingletonA(void)
{
	printf("������a ȣ��\n");
}
CSingletonA::~CSingletonA(void)
{
	printf("�Ҹ���a ȣ��\n");
}
//���� ���
void CSingletonA::ShowInfo(void)
{
	printf("csingleton A ȣ��\n");
}
//�̱��� B
class CSingletonB
{
public:
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonB)
};
//����&�Ҹ���
CSingletonB::CSingletonB(void)
{
	printf("������b ȣ��\n");
}
CSingletonB::~CSingletonB(void)
{
	printf("�Ҹ���b ȣ��\n");
}
//���� ���
void CSingletonB::ShowInfo(void)
{
	printf("csingleton B ȣ��\n");
}
//�̱��� C
class CSingletonC
{
public:
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonC)
};
//����&�Ҹ���
CSingletonC::CSingletonC(void)
{
	printf("������c ȣ��\n");
}
CSingletonC::~CSingletonC(void)
{
	printf("�Ҹ���c ȣ��\n");
}
void CSingletonC::ShowInfo(void) 
{
	printf("csingleton C ȣ��\n");
}
#endif // SINGLETON_CASE_A
#endif // E05_CLASS_MEM

	
	void E05(const int argc, const char ** args)
	{
	#if E05_CLASS_MEM
		CWidget oWidgetA;
		CWidget oWidgetB;
		
		oWidgetA.ShowInfo();
		CWidget::ShowInfo();
		
		oWidgetA.SetValue(10);
		oWidgetB.SetValue(20);

		oWidgetA.AddValue(10);
		oWidgetB.AddValue(20);
		/*
		 Ŭ���� ������ �ش� Ŭ������ ���� ������ ��� ��ü�� �����ϴ� �����̱⶧���� �ش� ������ ���� �����ϸ� ��� ��ü�� ������ �޴´�
		*/
		printf("\nŬ���� ���� ���� ���\n");
		printf("A : %d, %d\n", oWidgetA.GetValue(),oWidgetA.GetConstMemValue());
		printf("B : %d, %d\n", oWidgetB.GetValue(),oWidgetB.GetConstMemValue());
	#elif E05_SINGLETON
	#if SINGLETON_CASE_A
		/*
	CDataManager�� �����ڰ� private������ �ش簴ü�� Ŭ���� �ܺο��� �����ϴ� ���� �Ұ����ϴ�
	�Ҹ��� ���� private�̱� ������ Ŭ���� �ܺο��� ��ü ���Ű� �Ұ��� �ϴ�
	*/
	//delete CDataManager::GetInst;


		for (int i = 0; i < 10; i++)
		{
			CDataManager::STData stData = { std::to_string(i),i + 1,i + 1.5f };

			CDataManager::GetInst()->AddData(stData);
		}
		printf("����Ÿ ������ �߰� ���\n");
		for (int i = 0; i < 10; i++)
		{
			std::string oID = std::to_string(i);
			CDataManager::STData stData = CDataManager::GetInst()->GetData(oID);

			printf("Data : [%d, %f]\n", stData.m_nValue, stData.m_fValue);
		}

		CDataManager::DestroyInst();
	#elif SINGLETON_CASE_B
		CSingletonA::GetInst()->ShowInfo();
		printf("\n");
		CSingletonB::GetInst()->ShowInfo();
		printf("\n");
		CSingletonC::GetInst()->ShowInfo();
		printf("\n");
	#endif // SINGLETON_CASE_A
	#endif //E05_CLASS_MEM
	}
}
