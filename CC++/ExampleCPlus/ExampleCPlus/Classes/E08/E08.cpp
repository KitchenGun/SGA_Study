#include "E08.h"

//#define E08_AUTO			1
//#define E08_RANGE_BASE_FOR	2
//#define E08_SMART_POINTER	3
#define E08_LAMBDA			4
#define E08_MEM_FUNC_PTR	5

#if E08_SMART_POINTER
//#define AUTO_PTR	1
//#define UNIQUE_PTR	2
//#define SHARED_PTR	3
#define WEAK_PTR	4
#endif



namespace E08Space
{
#if E08_AUTO

#elif E08_RANGE_BASE_FOR
#elif E08_SMART_POINTER
	//widget
	class CWidget
	{
	public:
		//�Ҹ���
		virtual ~CWidget(void)
		{
			printf("CWidget.~CWidget(void)�Ҹ��� ȣ��\n");
		}
	};


	class CWidgetB;

	class CWidgetA
	{
	public:
		//Ÿ�� ����
		void SetTarget(std::shared_ptr<CWidgetB> a_oTargetPtr)
		{
			m_oTargetPtr = a_oTargetPtr;
		}
		//������ ����Ѵ� 
		void ShowInfo(void)
		{
			printf("CWidgetA.ShowInfo(void)�Լ� ȣ��\n");
		}
	public:
		virtual ~CWidgetA(void)
		{
			printf("CWidgetA.~CWidget(void)�Ҹ��� ȣ��\n");
		}

	private:
		std::shared_ptr<CWidgetB> m_oTargetPtr;
	};
	
	class CWidgetB
	{
	public:
		/*
		weak ptr ��ü�� �ܵ����� ����ϴ� ���� �Ұ��� �ϸ� �ش� ������ ��ü�� ����ϱ� ���ؼ� 
		�ݵ�� shared ptr ��ü�� ���ؼ� �ش� ������ ��ü�� ����������Ѵ� 
		�� weak ptr �� ���� ������ shared ptr �� ���ϰ� �ִ� ��ȯ ������ �����ϱ� ���ؼ� ���� �����̱⶧���� 
		shared ptr�� ���� ���̴� weak ptr ���簡 ���ǹ� �ϱ� �����̴�.
		*/

		//Ÿ�� ����
		void SetTarget(std::shared_ptr<CWidgetA> a_oTargetPtr) 
		{
			m_oTargetPtr = a_oTargetPtr;
			/*
			weak ptr ��ü�� ����ϸ� shared ptr ��ü�� ���� �߻��Ҽ��ִ� ��ȯ ���� ������ �����ϴ� ���� �����ϴ�
			�� weak ptr ��ü�� ���������� ���� ���� ������� �����ϱ� ������ ����Ű�� ����� ���۷��� ī��Ʈ�� ���� ��Ű�� �ʽ��ϴ�
			�� weak ptr ��ü�� �ٸ� ����Ʈ ������ ��üó�� ����Ű�� ��� �����ϱ� ���� ������ �����ڸ� �������� �ʽ��ϴ�.
			
			�̴� weak ptr ��ü�� ����Ű�� ��� �����ϴ� ������ ���� ����� ���� �޸� �� �����ϴ��� �Ǵ� �Ҽ����� �����̴�
			�� ��۸� �������� ���輺�� �����ϱ� �����̴�
			��۸� �����ʹ� �ּҰ��� ������ �ִ� ���� �ּ��� ������ ����ְų� �ٸ� ��ü�� �ִ� ��츦 �ǹ��Ѵ�
			���� �ش� ������ ��ü�� ������� ����Ű�� ��� �����ϱ� ���ؼ��� lock �Լ��� ���� ����Ű�� ����� ���� ��ȿ���� �Ǵ�����
			
			lock �Լ��� ��ȯ ������ �����ִ� shared ptr ������ ��ü�� ����ؾ��Ѵ�
			lock �Լ��� ȣ��Ǵ� ������ ����� �޸� �� �������� ���� ��� �� �����Ͱ� ��ȯ�ȴ�
			*/
			if (m_oTargetPtr.lock()!=nullptr)
			{
				m_oTargetPtr.lock()->ShowInfo();
			}
		}
	public:
		virtual ~CWidgetB(void)
		{
			printf("CWidgetB.~CWidget(void)�Ҹ��� ȣ��\n");
		}

	private:
		std::weak_ptr<CWidgetA> m_oTargetPtr;
	};


#elif E08_LAMBDA
	/*
	�Ϲ������� ������ ĸ�������� ���� �������� �ܺ� ������ ������ִ� ���� ���������� �޸� ���簡 �� �߻��Ѵ�
	������ ���� ĸ���� �ܺ� ������ ���� ȣ��Ǵ� ������ ��� �����Ѵٴ� ������ ���� ��� �ݵ�� �ش� ������ �� �������� ĸ���ؾ��Ѵ�
	
	�� ���� ���� ĸ�Ĵ� ������ ���� �ּҸ��� ���ϰ��ִ� ���̱� ������ �ش� ������ �޸𸮸� ����Ű�� ��۸� �����͸� �����ϰ� �ȴ�

	c++���� �Լ� �������� ������ �����ϴ� function Ŭ������ �����Ѵ� �ش� Ŭ������ ����ϸ� �Ϲ����� �Լ� �Ӹ� �ƴ϶� 
	Ư�� ��ü�� �ɹ� �Լ�, ���� �Լ� ���� �ش� Ŭ������ ���ؼ� �����ϴ� ���� �����ϴ� �� �ڵ带 �ۼ��Կ� �־ Ư�� �Լ��� ���� ������ ������ 
	������� �ʰ� �ش� �Լ��� Ư���Լ��� ��ȯ������ ����ϰų� �Ű� ������ �����ϴ� ���� �����ϴ�
	*/
	std::function<int(void)> GetLambda(int a_nVal)
	{
		return [&](void)->int
		{
			return a_nVal * a_nVal;
		};
	}
	//���� �ʱ�ȭ�Ѵ�
	void InitVals(int *a_pnVals, int a_nSize, const std::function<int(int)> &a_rFunc)
	{
		for (int i = 0; i < a_nSize; i++)
		{
			a_pnVals[i] = a_rFunc(i);
		}
	}
	//���� ����Ѵ�
	void PrintVals(int *a_pnVals, int a_nSize, const std::function<void(int,int)> &a_rFunc)
	{
		for (int i = 0; i < a_nSize; i++)
		{
			a_rFunc(i, a_pnVals[i]);
		}
		printf("\n");
	}

	//���� ���� �񱳸� �����Ѵ�
	bool CompareByAscending(int a_nLhs, int a_nRhs)
	{
		return a_nLhs > a_nRhs;
	}

#elif E08_MEM_FUNC_PTR
	//������
	class CData
	{
	public:
		//���� ���� ��ȯ�Ѵ�
		int GetPowerVal(int a_nVal)
		{
			return a_nVal * a_nVal;
		}
		//���� ���
		void ShowInfo(void)
		{
			printf("Cdata.ShowInfo(void) : %d\n", m_nVal);
		}
	public:
		CData(int a_nVal)
			:m_nVal(a_nVal)
		{
			//do nothing
		}

	private:
		int m_nVal = 0;
	};

#endif // E08_AUTO



	void E08(const int argc, const char ** args)
	{
		#if E08_AUTO
		/*
		auto Ű���带 ����ϸ� Ư�� ���� ������ �ڷ����� �����Ϸ��� �ڵ����� �����ϰ� ����� ���� �����ϴ�
		�� �ڷ����� �̸��� �� ��� auto Ű���带 ����ϸ� Ÿ���ο� ���� ���� �Ⱓ�� �����ϴ� ���� �����ϴ�

		�� �ش� Ű���带 ������� ��� �������� �ݵ�� �ʱ�ȭ ���� ���������Ѵ�
		�̴� �����Ϸ��� �ʱ�ȭ ���� �ڷ����� ������� auto�� ��õ��ڷ����� �����ϱ� �����̴�
		*/
		auto nValA = 0;
		auto fValB = 0.0f;
		auto pszStr = "Hello";


		int anVals[5] = { 1,2,3,4,5 };
		#elif E08_RANGE_BASE_FOR
		printf("�Ϲ����� for�� ���\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", anVals[i]);
		}
		printf("\n������� for ���\n");
		/*
		������� for���� ���� �ݺ����� �����Ҷ� �߸��� ������ ��������ν� �߻��ϴ� �Ǽ��� ���̱� ���� ���Ӱ� ������ �ݺ����̴�
		�� �ش� �ݺ����� ����ϸ� �ݺ��� ���� ������ ���������� �Ǵ��ؼ� �����ϱ⶧���� �߸��� ������ ����ϴ� �Ǽ��� �����ϴ� ���� �����ϴ�

		�� �ش� �ݺ����� �ݺ��� �ѹ��� �����Ҷ� ���� Ư�� �÷��ǿ� �ִ� ��Ҹ� �纻�� �����ϴ� �������� �����ϱ� ������
		���� �ش� �ݺ��� ���ο��� ���� ����� ���� �����ϱ� ���ؼ��� ���۷����� ����ؾ��Ѵ�
		*/
		for (int &rnVal : anVals)
		{
			rnVal *= 2;
		}

		for (int nVal : anVals)
		{
			printf("%d ", nVal);
		}

		#elif E08_SMART_POINTER
		#if AUTO_PTR||UNIQUE_PTR||SHARED_PTR
		std::auto_ptr<CWidget> oPtrA(new CWidget());
		std::auto_ptr<CWidget> oPtrB;

		printf("auto ptr ���� ������\n");
		if (oPtrA.get() != nullptr)
		{
			printf("PtrA��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		if (oPtrB.get() != nullptr)
		{
			printf("PtrB��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		oPtrB = oPtrA;
		printf("auto ptr ���� ������\n");
		if (oPtrA.get() != nullptr)
		{
			printf("PtrA��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		if (oPtrB.get() != nullptr)
		{
			printf("PtrB��ü�� ������ ������ �ֽ��ϴ�.\n");
		}

		//���ð� ���� ������ �� ����ؾ���

		/*
		����Ʈ ������ ��ü�� Ȱ���Ҷ� ����� ���� ���ƾ��� ������ ����Ʈ ������ ��ü ��ü�� �������� �����ϴ� ���̴�
		�̷� ��� ����Ʈ �������� �Ҹ��ڰ� �ڵ����� ȣ�� ���� �ʱ� ������ �޸� ������ ���� ���ϴ� ����Ʈ �����͸� ����� ����� �߻��Ѵ�
		�̴� ����Ʈ �����Ͱ� ���������� �޸��� ������ �õ��ϴ� ������ �ش� ������ ��ü�� �Ҹ��ڰ� ȣ��Ǿ��� ��� �̱� �����̴�
		���� ����Ʈ �����͸� ���ÿ� �����Ұ�� �̴� �� ����Ʈ ������ �����ΰ� �޸𸮸� ���� �Ҽ��ִٴ� ���� �ǹ��Ѵ�
		*/
		//std::auto_ptr<CWidget>*pPtrC = new std::auto_ptr<CWidget>(new CWidget());
		#elif UNIQUE_PTR
		std::unique_ptr<CWidget> oUniquePtrA(new CWidget());
		std::unique_ptr<CWidget> oUniquePtrB;

		printf("unique_ptr ���� ������\n");
		if (oUniquePtrA.get() != nullptr)
		{
			printf("UPtrA��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		if (oUniquePtrB.get() != nullptr)
		{
			printf("UPtrB��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		/*
		unique ptr ��ü�� auto ptr��ü�� �ٸ��� �ܼ��� �ش簴ü�� �Ҵ��ߴٰ� ���� ������ �Ǵ� ���� �ƴϴ� �̴� �ǵ�ġ �ʰ� �Ҵ� ������ �����ν� ���ʿ���
		������ ��ȯ�� ���ӵǴ� ������ �����ϱ� ���ؼ��� ���� unique ptr ��ü�� ������ �����ϱ� ���ؼ��� �ݵ�� move�Լ��� ����ؼ� ��������� ������ �����ϰڴٰ� 
		�����Ϸ����� �˷�����Ѵ�
		*/
		oUniquePtrB = std::move(oUniquePtrA);

		printf("unique_ptr ���� ������\n");
		if (oUniquePtrA.get() != nullptr)
		{
			printf("UPtrA��ü�� ������ ������ �ֽ��ϴ�.\n");
		}
		if (oUniquePtrB.get() != nullptr)
		{
			printf("UPtrB��ü�� ������ ������ �ֽ��ϴ�.\n");
		}

		#elif SHARED_PTR
		std::shared_ptr<CWidget> oSharedPtrA(new CWidget());
		std::shared_ptr<CWidget> oSharedPtrB;
		/*
		shared ptr ��ü�� ���������� use count��� �ɹ� �Լ��� ���ϰ� ������ 
		�ش� �Լ��� ����ϸ� ����Ű�� �ִ� ����� ���۷��� ī��Ʈ�� �������� ���� �����ϴ�
		*/

		printf("\nshared ptr �Ҵ���\n");
		printf("ref count %d \n", oSharedPtrA.use_count());

		/*
		shared ptr ��ü�� �ٸ� ��ü�� �Ҵ��� ��� ���������� ����Ű�� �ִ� 
		����� ���۷��� ī��Ʈ�� �����ϴ� ���� Ȯ�� �Ҽ��ִ�.
		*/

		oSharedPtrB = oSharedPtrA;
		
		printf("\nshared ptr �Ҵ���\n");
		printf("ref count %d \n", oSharedPtrA.use_count());

		/*
		shared ptr ��ü�� reset�ɹ��Լ��� ����ϸ� �ش� ������ ��ü�� ����Ű�� �ִ� ����� ������ ������ �����ϴ�
		�� �ش� �Լ��� ȣ��Ǵ� ���� ����Ű���ִ� ����� ���۷��� ī��Ʈ�� �����ϴ� ���� �˼��ִ�
		
		oSharedPtrA.swap
		�� shared ptr��ü�� ����Ű�� ����� ���� ��ȯ �ϰ� �ʹٸ� swap �ɹ� �Լ��� ����ϸ� �ȴ�
		ex	 std::shared_ptr<int> oPtrA(new int(10));
			 std::shared_ptr<int> oPtrB(new int(20));
			 oPtrA.swap(oPtrB)
		*/

		oSharedPtrA.reset();
		

		printf("\nshared ptr a ���� ������\n");
		printf("ref count %d \n", oSharedPtrB.use_count());
		#elif WEAK_PTR 
		std::shared_ptr<CWidgetA> oWidgetAPtr(new CWidgetA());
		std::shared_ptr<CWidgetB> oWidgetBPtr(new CWidgetB());
		
		oWidgetAPtr->SetTarget(oWidgetBPtr);
		oWidgetBPtr->SetTarget(oWidgetAPtr);

		#endif
		#elif E08_LAMBDA
		
		printf("\n���� ����� ���ÿ� ȣ�� ���\n");
		/*
		���ٸ� ������ �ٷ� ȣ�� ���� ��� �ش� ���ٴ� ���̻� ������ �Ұ����� ������ ��ȸ�� �Լ��� �ȴ� 
		*/
		[](int a_nLhs, int a_nRhs)
		{
			printf("%d + %d = %d\n", a_nLhs, a_nRhs, a_nLhs + a_nRhs);
		}(10, 20);

		/*
		���ٴ� Ư�� ������ ����ǰ� ���Ǵ� ���� �Լ��̸� �ش� �Լ��� �Լ������͸� ����ϴ� �� ó��
		�ٸ� ���� ������ ���ٸ� �Ҵ���ʿ��Ҷ� ȣ���ϴ� ���� �����ϴ�

		�̶� ������ �ڷ����� ����ڴ� �˼����� ������ �ش� ���ٸ� Ư�� ������ �����ϱ� ���ؼ� auto Ű���带 ����ؼ� �����Ϸ���
		�ڵ����� �ڷ����� �����ϵ��� ����� ����Ѵ� 
		*/
		printf("\n���� ������ �Ҵ� �� ���� ���\n");
		auto oLambdaA = [](int a_nLhs, int a_nRhs)
		{
			printf("%d + %d = %d\n", a_nLhs, a_nRhs, a_nLhs + a_nRhs);
		};
		
		oLambdaA(10, 20);
		oLambdaA(30, 40);

		int nLhs=0;
		int nRhs=0;

		printf("\n���� 2�� �Է�\n");
		scanf("%d %d", &nLhs, &nRhs);
		/*
		���ٴ� ĸ������ ����ϸ� ���� �ܺο� �����ϴ� ������ �Ű����� ���޾��� ���� �Լ� ���ο��� ����ϴ� ���� �����ϴ�
		�� �Ϲ����� �Լ��� �ܺο� �����ϴ� ������ �����ϱ� ���ؼ��� �ݵ�� �Լ� �Է����� �ش� ������ ������ �Ǵ� ���۷����� �����ؾ������� ���ٴ�
		ĸ������ ����ϸ� �ܺ� ������ �Ű� ������ ���� ���� �ʰ� ����ϴ� ���� �����ϴ�

		���ٿܺ� ���� ĸ�� ���� 
		-������ ĸ��
		-�������� ĸ��
		�� ���� ĸ�Ķ�?
		���� �ܺο� �����ϴ� ������ �纻�� �����ϴ� ������� �����ϴ� ĸ�� ����̴�
		�� ĸ�ĵ� ������ �ܺ��� ������ �ٸ� ������ �����̱� ������ ���� �Լ� ���ο��� 
		�ش� ������ �����Ѵ� �ϴ��� �ܺο� �����ϴ� ���� �������� ������ ��ġ�� �ʴ´�
		
		���� ���� ĸ�Ķ�?
		���� �ܺο� �����ϴ� ������ ������ �����ϴ� ������� �����ϴ� ĸ�� ����̴� 
		���� ���� �������� ĸ�ĵ� ������ ���� ���ο��� ������ ��� ���� �������� ������ ��ģ��
		*/
		auto oLambdaB = [nLhs,nRhs](void)
		{
			printf("%d + %d = %d\n", nLhs, nRhs, nLhs + nRhs);
		};

		oLambdaB();

		auto oLambdaC = [&nLhs, &nRhs](void)
		{
			nLhs *= 2;
			nRhs *= 2;
		};
		oLambdaC();

		printf("\n�������� ĸ�� ���\n");
		printf("nLhs %d  nRhs %d ", nLhs, nRhs);
		
		/*
		���������� ĸ�ĵ� �纻�� �⺻������ ������ �Ұ����� ����� ĸ�İ� �Ǳ� ������ ���� ���� �Լ� ���ο���
		�ش� ������ �����ϰ� ������ mutable Ű���带 ����ؼ� ����� �ƴ� ������ �ܺ��� ������ ĸ���ؾ��Ѵ�
		*/
		auto oLambdaD = [nLhs, nRhs](void) mutable //mutable�� ����� �����Ҽ��ְ� �����
		{
			nLhs *= 2;
			nRhs *= 2;
		};

		oLambdaD();

		printf("\n������ ĸ�� ���\n");
		printf("nLhs %d  nRhs %d ", nLhs, nRhs);
		/*
		���� �Լ��� ��ȯ ���� ���� �ڷ����� ����ϰ� ���� ��� ���� �Լ��� �Ű� ���� ���� �ڿ��� ��ȯ ���� ���� �ڷ����� ����ϸ� �ȴ�
		�� c++���� �Լ��� �տ� ��ȯ���� ����ϴ� ���� �⺻���� ����������
		�̸� �Ű� ���� ���� �ڿ� ����ϴ� �͵� �����ϴ�
		*/
		auto oLambdaE = [nLhs, nRhs](void) mutable ->int //mutable�� ����� �����Ҽ��ְ� �����
		{
			return nLhs + nRhs;
		};
		printf("\n���� �Լ� ��ȯ ���\n");
		printf("%d + %d = %d\n", nLhs, nRhs, oLambdaE());

		auto oLambdaF = GetLambda(10);

		printf("\n���� ��ȯ �Լ� ȣ�� ���\n");
		printf("%d * %d = %d", 10, 10, oLambdaF());

		int anVals[10] = { 0 };
		const int nSize = sizeof(anVals) / sizeof(anVals[0]);
		InitVals(anVals, nSize, [](int a_nIdx)->int
		{
			return rand() % 100;
		});

		printf("\n�迭 ���� ��\n");

		PrintVals(anVals, nSize, [](int a_nIdx, int a_nVal)->void
		{
			printf("%d ", a_nVal);
		});

		std::sort(anVals, anVals + nSize, CompareByAscending);

		printf("\n�迭 ���� ��\n");

		PrintVals(anVals, nSize, [](int a_nIdx, int a_nVal)->void
		{
			printf("%d ", a_nVal);
		});
		#elif E08_MEM_FUNC_PTR
		CData oDataA(10);
		CData oDataB(20);

		printf("\n�ɹ� �Լ� ���� ȣ�� ���\n");
		oDataA.ShowInfo();
		oDataB.ShowInfo();

		void(CData::*pfnMemFuncA)(void) = &CData::ShowInfo;
		void(CData::*pfnMemFuncB)(void) = &CData::ShowInfo;
		
		printf("\n�ɹ� �Լ� ������ ȣ�� ���\n");
		(oDataA.*pfnMemFuncA)();
		(oDataB.*pfnMemFuncB)();

		std::function<void(void)> oFuncA = std::bind(&CData::ShowInfo, &oDataA);
		std::function<void(void)> oFuncB = std::bind(&CData::ShowInfo, &oDataB);

		std::function<int(int)> oFuncC = std::bind(&CData::GetPowerVal, &oDataA, std::placeholders::_1);
		std::function<int(int)> oFuncD = std::bind(&CData::GetPowerVal, &oDataB, std::placeholders::_1);


		printf("\nfunction ��ü�� ���� �Լ� ȣ�� ���\n");
		oFuncA();
		oFuncB();

		printf("\n20 ^ 2 : %d \n",oFuncC(20));
		printf("\n30 ^ 2 : %d \n", oFuncC(30));

		#endif // E08_AUTO
	}
}
