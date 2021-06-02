#include "E07.h"

//#define E07_TEMPLATE_FUNC	1
#define E07_TEMPLATE_CLS	2

#if E07_TEMPLATE_CLS
#define TEMPLATE_CLS_CASE_A	1
//#define TEMPLATE_CLS_CASE_B 2
#define TEMPLATE_CLS_CASE_C 3

#endif 
namespace E07Space
{
#if E07_TEMPLATE_FUNC
	struct STData
	{
		int m_nVal;
		float m_fVal;

	};

	/*
	��� ���ø� �Լ� �Ǵ� Ŭ������ template Ű����� ��ø� ������ϸ� template �Լ� �Ǵ� Ŭ������ �ڷ����� ��ü�� �������ڰ� �ʿ��ϴ� 
	���� ���ڴ� typename �Ǵ� Ŭ���� Ű���带 ���ؼ� �����ϴ� ���� �����ϸ� �ش� ������ ������ �ʿ��� ��ŭ �����ϴ� ���� �����ϴ�
	*/
	template <typename T>
	//���� ��ȯ�� �ش�
	void Swap(T &a_rtLhs, T &a_rtRhs)
	{
		T tTemp = a_rtLhs;
		a_rtLhs = a_rtRhs;
		a_rtRhs = tTemp;
	}
	/*
	���ø��� ���� ���ڿ��� �ڷ��� �Ӹ� �ƴ϶� ����� ����ϴ� ���� �����ϴ�
	�ش� ����� Ȱ���ؼ� �迭���� ���� �Ҵ� �ڵ带 �ۼ��ϴ� ���� �����ϴ�
	*/
	//�迭�� �����Ѵ�
	template <typename T,int SIZE =5>
	T* MakeArr(int a_nSize = SIZE)
	{
		return new T[a_nSize];
	}
	
	/*
	c++ ���ø��� Ư�� �ڷ����� ��� ������ ���ø��� �ƴ϶� ������ ���ø����� �����ϴ� Ư��ȭ ����� �����մϴ�
	�� �Լ� ���ø��� ���ø��� �κ� Ư��ȭ ��� �������� ������ ���ø��� ���� Ư��ȭ�� �����մϴ�
	�� ���ø��� �κ� Ư��ȭ�� ���ø��� ���� ���ڰ� 2�� �̻��� ��� 
	�ش� ������ �ڷ����� ��� �����ϴ� ���� �ƴ϶� �Ϻθ� ���� �Ҽ��ִ� ����� �ǹ��Ѵ�
	*/
	//���� ��ȯ�Ѵ�
	//���ø��� ���� Ư��ȭ ���� ��� ���ø��� �ƴ� �Լ��� ��������� ������ ������ �������� 
	//���ø� �Լ��� ��� �ش� �Լ��� ���� ȣ���ؾ����� ���ø� �Լ��� �����Ǵ� 
	//�ݸ� �Ϲ����� �����Լ��� �Լ��� ȣ�� ���ο� ������� �ش� �Լ��� ����� ������ �ȴ�
	template <>
	void Swap(STData &a_rstLhs, STData &a_rstRhs)
	{
		Swap<int>(a_rstLhs.m_nVal, a_rstRhs.m_nVal);
	}

#elif E07_TEMPLATE_CLS
#if TEMPLATE_CLS_CASE_A

	//���� ����Ʈ
	template <class T>
	class CLinkedList
	{
	public:
		//���
		struct  STNode
		{
			T m_tVal;
			STNode *m_pstNextNode;
		};
	public:
		//������ �Ҹ���
		CLinkedList(void)
		{
			//do nothing
		}
		virtual ~CLinkedList(void)
		{
			this->Reset();
		}
		CLinkedList(const CLinkedList &a_rOther)
		{
			*this = a_rOther;
		}
		//���������

	public:
		//operator =
		CLinkedList & operator=(const CLinkedList &a_rOther)
		{
			this->Reset();
			STNode *pstCurNode = a_rOther.m_pstHeadNode;
			while (pstCurNode != nullptr)
			{
				this->AddVal(pstCurNode->m_tVal);
				pstCurNode = pstCurNode->m_pstNextNode;
			}

			return *this;
		}
	public:
		//�Լ�
		//���� ����
		void Reset(void)
		{
			STNode *pstCurNode = m_pstHeadNode;

			while (pstCurNode != nullptr)
			{
				STNode *pstRemoveNode = pstCurNode;
				pstCurNode = pstCurNode->m_pstNextNode;

				SAFE_DELETE(pstRemoveNode);
			}
			m_pstHeadNode = nullptr;
		}
		//�� ���� ��ȯ
		int GetNumVals(void)const
		{
			return m_nNumVals;
		}
		//������ �߰�
		void AddVal(T a_tVal)
		{
			STNode *pstNode = this->CreateNode(a_tVal);
			//��� ��尡 �������� ���� ���
			if (m_pstHeadNode == nullptr)
			{
				m_pstHeadNode = pstNode;
			}
			else
			{
				STNode *pstTailNode = m_pstHeadNode;

				//���� ��� Ž���Ѵ�
				while (pstTailNode->m_pstNextNode != nullptr)
				{
					pstTailNode = pstTailNode->m_pstNextNode;
				}
				pstTailNode->m_pstNextNode = pstNode;
			}
			m_nNumVals += 1;
		}
		//������ Ž��
		STNode *FindVal(int a_nIdx)
		{
			STNode *pstCurNode = m_pstHeadNode;
			for (int i = 0; i < a_nIdx; i++)
			{
				pstCurNode = pstCurNode->m_pstNextNode;
			}
			return pstCurNode;
		}
	private:
		//node ����
		STNode *CreateNode(T a_tVal)
		{
			STNode *pstNode = new STNode();
			pstNode->m_tVal = a_tVal;
			pstNode->m_pstNextNode = nullptr;

			return pstNode;
		}
	private:
		//����
		int m_nNumVals = 0;
		STNode*m_pstHeadNode = nullptr;
	};
#elif TEMPLATE_CLS_CASE_B
	//�̱��� ���ø����� �ۼ��ϴ� ���� c++�� c�� �����ϰ�� ��ó�� �Լ��� ����Ҽ���� �̷� ������� ������
	//���ø� Ŭ������ ���۵� �ڵ� �κ��� �ּ��� �̱����� ������� ����� �����ϰ� �������� ������� ó���� �Ѵ�.
template <class T>
class CSinglton
{
public:
	static T *GetInst(void)
	{
		//�ν��Ͻ� ������Ұ��
		if (CSinglton::m_pInst == nullptr)
		{
			CSinglton::m_pInst = new T();
		}
		return m_pInst;
	}
	//�ν��Ͻ� ����
	static void DestroyInst(void)
	{
		//�ν��Ͻ� �����Ұ��
		if (CSinglton::m_pInst != nullptr)
		{
			SAFE_DELETE(CSinglton::m_pInst);
		}
	}
protected:
	//������ �Ҹ���
	CSinglton(void)
	{
		//do nothing
	}
	virtual ~CSinglton(void)
	{
		//do nothing
	}
	//���� ������
	CSinglton(const CSinglton &a_rOther);

private:
	//����
	static T *m_pInst;
};

template <class T> 
T *CSinglton<T>::m_pInst = nullptr;

//����
class CWidget :public CSinglton<CWidget>
{
public:
	/*
	c++����friend Ű���带 Ư�� Ŭ������ ���Ͱ���� ����ϴ� ���� �����ϴ�
	�̶� ���� ���谡 ������ Ŭ������ �ش� Ű���带 ����� Ŭ������ private �ɹ��� �����ϴ� ���� �����ϴ� 
	�� friend Ű����� �ܹ����̱� ������ ���� Ŭ������ �ش� Ŭ������ friend�� ������� �ʾ��� ��쿡�� private �ɹ��� �����ϴ� ���� �Ұ����ϴ�
	*/
	friend class CSinglton<CWidget>;
public:
	void ShowInfo(void)
	{
		printf("CWidget.CWidget(void)�Լ� ȣ��\n");
	}
private:
	//������
	CWidget(void)
	{
		printf("CWidget.CWidget(void)������ ȣ��\n");
	}
	virtual ~CWidget(void)
	{
		printf("CWidget.CWidget(void)�Ҹ��� ȣ��\n");
	}
};
#elif TEMPLATE_CLS_CASE_C
	//������
template<class T1,class T2>
class CData
{
public:
	//������
	CData(void)
	{
		printf("CData<T1 T2>.CData(void)������ ȣ��\n");
	}
private:
	T1 m_tValA;
	T2 m_tValB;
};

/*
c++ Ŭ���� ���ø��� �Լ����ø��� �޸�
���� ���ڰ� 2�� �̻��� ��� Ư�� ���ĸ� �����ϴ� ���� �����ϸ� �̸� ���ø��� �κ� Ư��ȭ��� �Ѵ�
�� �̶� Ŭ���� �̸� ���� ���ø� ���� ���ڸ� ������������ �����Ϸ��� �ش� Ŭ���� ���ø��� 
�κ� Ư��ȭ ���ø��̶�� �ν��Ҽ��ִ�
*/
//������
template <class T>
class CData<int,T>//�̰� �������� �κ� Ư��ȭ�̴�
{
public:
	//������
	CData(void)
	{
		printf("CData<int T>.CData(void)������ ȣ��\n");
	}
private:
	//����
	int m_nValA;
	T m_nValB;

};

template <>
class CData<int, float>
{
public:
	//������
	CData(void)
	{
		printf("CData<int float>.CData(void)������ ȣ��\n");
	}
private:	
	//����
	int m_nValA;
	float m_nValB;
};

#endif // TEMPLATE_CLS_CASE_A
#endif // E07_TEMPLATE_FUNC

	void E07(const int argc, const char ** args)
	{
	#if E07_TEMPLATE_FUNC
		int nValA=10;
		int nValB=20;
		float fValA=10.0f;
		float fValB=20.0f;
		
		std::string oStrA = "ABCD";
		std::string oStrB = "abcd";
		
		STData stDataA = { 10,10.0f };
		STData stDataB = { 20,20.0f };

		printf("\n��ȯ��\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str());
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		//���ø� �Լ��� ȣ�� �Ҷ� �ڷ����� ������ ������ִ� ���� ���� �����̴�
		//�Ű������� �ڷ����� ������� �����Ϸ��� ã���ش� �̴� ��ġ �ʴ� ����� ����� �����ֱ⿡ ����Ѵ� �ӵ� ���̴� ���� 
		Swap<int>(nValA, nValB);
		Swap<float>(fValA, fValB);
		Swap<std::string>(oStrA, oStrB);
		Swap<STData>(stDataA, stDataB);

		printf("\n��ȯ��\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str()); 
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		int *pnVals = MakeArr<int>(10);
		float *pfVals = MakeArr<float>(10);

		for (int i = 0; i < 10; i++)
		{
			pnVals[i] = i + 1;
			pfVals[i] = i + 1.0f;
		}
		printf("\n���� �Ҵ���\n");

		printf("int : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", pnVals[i]);
		}
		printf("\n");
		printf("float : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%.2f ", pfVals[i]);
		}
		printf("\n");
		SAFE_DELETE_ARRAY(pnVals);
		SAFE_DELETE_ARRAY(pfVals);
	#elif E07_TEMPLATE_CLS
	#if TEMPLATE_CLS_CASE_A
		CLinkedList<int> oValListA;
		CLinkedList<std::string> oValListB;

		for (int i = 0; i < 10; i++)
		{
			oValListA.AddVal(i + 1);
			oValListB.AddVal(std::to_string(i + 1));
		}

		printf("\nA����Ʈ���\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", oValListA.FindVal(i)->m_tVal);
		}
		printf("\nB����Ʈ���\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%s ", oValListB.FindVal(i)->m_tVal.c_str());
		}
	#elif TEMPLATE_CLS_CASE_B
		CWidget::GetInst()->ShowInfo();
		CWidget::GetInst()->ShowInfo();
		CWidget::GetInst()->ShowInfo();
	#elif TEMPLATE_CLS_CASE_C

		CData<std::string, std::string> oDataA;
		CData<int, std::string> oDataB;
		CData<int, float> oDataC;

	#endif // TEMPLATE_CLS_CASE_A
	#endif // E07_TEMPLATE_FUNC
	}
}
