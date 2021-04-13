#include "E02.h"

//#define E02_FUNC_OVERLOADING 1
//#define E02_REFERENCE 2
#define E02_INLINE_FUNC	3

namespace E02Space
{
#if E02_FUNC_OVERLOADING
	/*
	extern "C"�� Ư�� ������ ����ϸ� �ش� ������ c++�� ��Ģ�� �ƴ�   c�� ��Ģ�� ���� �������� �����ϴ� ���� �����ϴ�
	�� �ش� ���������� ���� �ͱ۸��� ������� �ʱ� ������ �Լ� �����ε� �Ұ���

	���� �ͱ۸��̶�
	C++�����Ϸ��� Ư�� �Լ����� ������ �Ҷ� �ش� �Լ����� �̸��� �����ϴ� �ܰ踦 �����ϸ� �ش� �ܰ踦 ���� �ͱ۸��̶�� �Ѵ�
	�� ������ �̸� �Լ��� ���� �ͱ۸� ��Ģ�� ���� ���� �ٸ� �Լ��� �̸��� ��������� ������ �����ε��� �����ϴ�
	*/
	extern "C"
	{

	}
	int GetSumValue(int a_nLhs, int a_nRhs)
	{
		return a_nLhs + a_nRhs;
	}
	int GetSumValue(int a_nLhs, int a_nMhs, int a_nRhs)
	{
		return a_nLhs + a_nMhs + a_nRhs;
	}

#elif E02_REFERENCE
	/*
	���۷����� ����ϸ� �����Ϳ� ���������� �ٸ� ������ �����ϴ� ������ ���� �� �����ϴ� ���� �����ϴ�.
	�迭�� �����͸� ����Ͽ� �ѱ�� ���� ���ϴ�. �Ұ��� �Ѱ��� �ƴ�
	*/
	void SwapByRef(int &a_nLhs, int &a_nRhs)
	{
		int nTemp = a_nLhs;
		a_nLhs = a_nRhs;
		a_nRhs = nTemp;
	}
#elif E02_INLINE_FUNC
	/*
	�ζ��� �Լ��� �������� ���� �ƴ϶� �����Ϸ����� ��û�ϴ� ���̱� ������ �����Ϸ��� ���ؼ� 
	�ش� �Լ��� ���� ����� �����ϰ� �ִٸ� �� ��û�� �źδ��Ҽ��ִ�.
	*/
	//�迭�� �հ� �� ��չ�ȯ
	inline void GetSumAndAverage(int *a_pnValues, int a_nSize, int &a_rnOutSum, float &a_rfOutAverage)
	{
		int nSumValue = 0;
		for (int i = 0; i < a_nSize; ++i)
		{
			nSumValue += a_pnValues[i];
		}
		a_rnOutSum = nSumValue;
		a_rfOutAverage = nSumValue / (float)a_nSize;
	}
	

#endif // E02_FUNC_OVERLOADING


	void E02(const int argc, const char ** args)
	{
	#if E02_FUNC_OVERLOADING
		int nLhs = 10;
		int nMhs = 20;
		int nRhs = 30;

		printf("%d+%d=%d\n", nLhs, nRhs, GetSumValue(nLhs, nRhs));
		printf("%d+%d+%d=%d\n", nLhs, nMhs, nRhs, GetSumValue(nLhs, nMhs, nRhs));
	#elif E02_REFERENCE
		int nValue = 0;
		int &rnValue = nValue;//����� ���ÿ� ������ ����� ���Ŀ� 
		
		
		//���� �ȵǴ� �ڵ� 
		int &&rnRValue = 0;
		rnRValue = 10;
		/*
		���۷����� Ư�� ������ ��Ī�� �ο��Ҽ��ִ� ������ �ش� ���۷����� ����Ǵ� �����̱� �����̴� 
		���� �̹� ������ �Ϸ�� ���۷����� �ٸ� ������ �Ҵ��� ��� �̴� ���ο� ��Ī�� �ο��ϴ� ���� �ƴ϶�
		�ش纯���� ���� ���۷����� �Ҵ��ϴ� ���̴�.
		*/
		rnValue = 10;
		rnValue = nValue;//�ּҰ��� �����ϴ� ���� �ƴ� ���۷��� ������ ���� �ִ� ���̴�.
		std::cout << "���" << std::endl;
		printf("value %d %p \n", nValue, &nValue);
		printf("Ref value %d %p \n", rnValue, &rnValue);

		int nLhs = 10;
		int nRhs = 20;

		printf("\n �� ��ȯ��\n");
		printf("%d ,%d\n", nLhs, nRhs);

		SwapByRef(nLhs, nRhs);

		printf("\n �� ��ȯ��\n");
		printf("%d ,%d\n", nLhs, nRhs);

	#elif E02_INLINE_FUNC
		E02Space::GetSumValue(10, 20);
		/*
		random device�� ����ϸ� ������ �����ϴ� ���� �����ϸ� 
		uniform_int_distribution�� ����ϸ� ������ ������ �����ϴ� ���� �����ϴ�
		���� �Ǽ��� ������ �����ϰ� ������ uniform_real_distribution�� ����ϸ� �ȴ�
		*/
		std::random_device oRandom;
		std::uniform_int_distribution<int> oUniform(0, 100);
		std::uniform_real_distribution<float> oUniformReal(0.0f, 10.0f);
		int anValues[10] = { 0 };
		float afValues[10] = { 0.0f };

		const int nSize = sizeof(anValues) / sizeof(anValues[0]);

		for (int i = 0; i < nSize; ++i)
		{
			anValues[i] = oUniform(oRandom);
			afValues[i] = oUniformReal(oRandom);
		}
		printf("���� �迭 ���");
		for (int i = 0; i < nSize; ++i)
		{
			printf("%d ",anValues[i]);
		}
		printf("�Ǽ��� ���");
		for (int i = 0; i < nSize; ++i)
		{
			printf("%.2f ", afValues[i]);
		}

		int nSum = 0;
		float fAverage = 0.0f;
		GetSumAndAverage(anValues, nSize, nSum, fAverage);
		printf("\n\n�հ� %d \n", nSum);
		printf("��� %f \n", fAverage);

	#endif // E02_FUNC_OVERLOADING
	}
	
}
