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
		//소멸자
		virtual ~CWidget(void)
		{
			printf("CWidget.~CWidget(void)소멸자 호출\n");
		}
	};

#elif E08_LAMBDA

#endif // E08_AUTO



	void E08(const int argc, const char ** args)
	{
		#if E08_AUTO
		/*
		auto 키워드를 사용하면 특정 지역 변수의 자료형을 컴파일러에 자동으로 지정하게 만드는 것이 가능하다
		즉 자료형의 이름이 길 경우 auto 키워드를 사용하면 타이핑에 대한 개발 기간을 단축하는 것이 가능하다

		단 해당 키워드를 사용했을 경우 변수에는 반드시 초기화 값을 명시해줘야한다
		이는 컴파일러가 초기화 값의 자료형을 기반으로 auto로 명시된자료형을 결정하기 때문이다
		*/
		auto nValA = 0;
		auto fValB = 0.0f;
		auto pszStr = "Hello";


		int anVals[5] = { 1,2,3,4,5 };
		#elif E08_RANGE_BASE_FOR
		printf("일반적인 for문 결과\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", anVals[i]);
		}
		printf("\n범위기반 for 결과\n");
		/*
		범위기반 for문은 기존 반복문을 구성할때 잘못된 범위를 명시함으로써 발생하는 실수를 줄이기 위해 새롭게 등장한 반복문이다
		즉 해당 반복문을 사용하면 반복에 대한 범위를 내부적으로 판단해서 동작하기때문에 잘못된 범위를 명시하는 실수를 방지하는 것이 가능하다

		단 해당 반복문은 반복을 한번씩 진행할때 마다 특정 컬렉션에 있는 요소를 사본에 복사하는 개념으로 동작하기 때문에
		만약 해당 반복문 내부에서 원본 요소의 값을 변경하기 위해서는 레퍼런스를 사용해야한다
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

		printf("auto ptr 권한 위임전\n");
		if (oPtrA.get() != nullptr)
		{
			printf("PtrA객체가 권한을 가지고 있습니다.\n");
		}
		if (oPtrB.get() != nullptr)
		{
			printf("PtrB객체가 권한을 가지고 있습니다.\n");
		}
		oPtrB = oPtrA;
		printf("auto ptr 권한 위임후\n");
		if (oPtrA.get() != nullptr)
		{
			printf("PtrA객체가 권한을 가지고 있습니다.\n");
		}
		if (oPtrB.get() != nullptr)
		{
			printf("PtrB객체가 권한을 가지고 있습니다.\n");
		}

		//스택과 힙의 구조를 꼭 기억해야함

		/*
		스마트 포인터 객체를 활용할때 절대로 하지 말아야할 행위는 스마트 포인터 객체 자체를 동적으로 생성하는 것이다
		이럴 경우 스마트 포인터의 소멸자가 자동으로 호출 되지 않기 때문에 메모리 관리를 하지 못하는 스마트 포인터를 만드는 결과를 발생한다
		이는 스마트 포인터가 내부적으로 메모리의 관리를 시도하는 시점이 해당 포인터 객체의 소멸자가 호출되었을 경우 이기 때문이다
		따라서 스마트 포인터를 스택에 생성할경우 이는 곳 스마트 포인터 스스로가 메모리를 관리 할수있다는 것을 의미한다
		*/
		//std::auto_ptr<CWidget>*pPtrC = new std::auto_ptr<CWidget>(new CWidget());


		std::unique_ptr<CWidget> oUniquePtrA(new CWidget());
		std::unique_ptr<CWidget> oUniquePtrB;

		printf("unique_ptr 권한 위임전\n");
		if (oUniquePtrA.get() != nullptr)
		{
			printf("UPtrA객체가 권한을 가지고 있습니다.\n");
		}
		if (oUniquePtrB.get() != nullptr)
		{
			printf("UPtrB객체가 권한을 가지고 있습니다.\n");
		}
		/*
		unique ptr 객체는 auto ptr객체와 다르게 단순히 해당객체를 할당했다고 권한 위임이 되는 것이 아니다 이는 의도치 않게 할당 연산을 함으로써 불필요한
		순간에 권환이 위임되는 문제를 방지하기 위해서다 따라서 unique ptr 객체가 권한을 위임하기 위해서는 반드시 move함수를 사용해서 명시적으로 권한을 위힘하겠다고 
		컴파일러에게 알려줘야한다
		*/
		oUniquePtrB = std::move(oUniquePtrA);

		printf("unique_ptr 권한 위임후\n");
		if (oUniquePtrA.get() != nullptr)
		{
			printf("UPtrA객체가 권한을 가지고 있습니다.\n");
		}
		if (oUniquePtrB.get() != nullptr)
		{
			printf("UPtrB객체가 권한을 가지고 있습니다.\n");
		}

		#elif E08_LAMBDA

		#endif // E08_AUTO



		

		
	
	}
}
