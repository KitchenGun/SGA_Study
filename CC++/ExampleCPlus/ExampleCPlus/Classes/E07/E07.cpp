#include "E07.h"

#define E07_TEMPLATE_FUNC	1
#define E07_TEMPLATE_CLS	2


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
	#endif // E07_TEMPLATE_FUNC
	
	}
}
