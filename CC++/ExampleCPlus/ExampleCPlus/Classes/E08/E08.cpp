#include "E08.h"

//#define E08_AUTO			1
//#define E08_RANGE_BASE_FOR	2
#define E08_SMART_POINTER	3
#define E08_LAMBDA			4

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

#elif E08_LAMBDA

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

		#elif E08_LAMBDA

		#endif // E08_AUTO



		

		
	
	}
}
