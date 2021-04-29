#include "E08.h"

//#define E08_AUTO			1
//#define E08_RANGE_BASE_FOR	2
//#define E08_SMART_POINTER	3
#define E08_LAMBDA			4

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
		//소멸자
		virtual ~CWidget(void)
		{
			printf("CWidget.~CWidget(void)소멸자 호출\n");
		}
	};


	class CWidgetB;

	class CWidgetA
	{
	public:
		//타겟 변경
		void SetTarget(std::shared_ptr<CWidgetB> a_oTargetPtr)
		{
			m_oTargetPtr = a_oTargetPtr;
		}
		//정보를 출력한다 
		void ShowInfo(void)
		{
			printf("CWidgetA.ShowInfo(void)함수 호출\n");
		}
	public:
		virtual ~CWidgetA(void)
		{
			printf("CWidgetA.~CWidget(void)소멸자 호출\n");
		}

	private:
		std::shared_ptr<CWidgetB> m_oTargetPtr;
	};
	
	class CWidgetB
	{
	public:
		/*
		weak ptr 객체는 단독으로 사용하는 것이 불가능 하며 해당 포인터 객체를 사용하기 위해서 
		반드시 shared ptr 객체를 통해서 해당 포인터 객체를 생성해줘야한다 
		즉 weak ptr 의 존재 이유가 shared ptr 의 지니고 있는 순환 참조를 방지하기 위해서 나온 개념이기때문에 
		shared ptr의 도움 없이는 weak ptr 존재가 무의미 하기 때문이다.
		*/

		//타겟 변경
		void SetTarget(std::shared_ptr<CWidgetA> a_oTargetPtr) 
		{
			m_oTargetPtr = a_oTargetPtr;
			/*
			weak ptr 객체를 사용하면 shared ptr 객체를 통해 발생할수있는 순환 참조 문제를 방지하는 것이 가능하다
			즉 weak ptr 객체는 내부적으로 약한 참조 방식으로 동작하기 때문에 가리키는 대상의 레퍼런스 카운트를 증가 시키지 않습니다
			단 weak ptr 객체는 다른 스마트 포인터 객체처럼 가리키는 대상에 접근하기 위한 포인터 연산자를 지원하지 않습니다.
			
			이는 weak ptr 객체가 가리키는 대상에 접근하는 시점에 접근 대상이 아직 메모리 상에 존재하는지 판단 할수없기 때문이다
			즉 댕글링 포인터의 위험성이 존재하기 때문이다
			댕글링 포인터는 주소값은 가지고 있는 실제 주소의 공간이 비어있거나 다른 객체가 있는 경우를 의미한다
			따라서 해당 포인터 객체를 기반으로 가리키는 대상에 접근하기 위해서는 lock 함수를 통해 가리키는 대상이 아직 유효한지 판단한후
			
			lock 함수가 반환 값으로 돌려주는 shared ptr 포인터 객체를 사용해야한다
			lock 함수를 호출되는 시점에 대상이 메모리 상에 존재하지 않을 경우 널 포인터가 반환된다
			*/
			if (m_oTargetPtr.lock()!=nullptr)
			{
				m_oTargetPtr.lock()->ShowInfo();
			}
		}
	public:
		virtual ~CWidgetB(void)
		{
			printf("CWidgetB.~CWidget(void)소멸자 호출\n");
		}

	private:
		std::weak_ptr<CWidgetA> m_oTargetPtr;
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
		#if AUTO_PTR||UNIQUE_PTR||SHARED_PTR
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
		#elif UNIQUE_PTR
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

		#elif SHARED_PTR
		std::shared_ptr<CWidget> oSharedPtrA(new CWidget());
		std::shared_ptr<CWidget> oSharedPtrB;
		/*
		shared ptr 객체는 내부적으로 use count라는 맴버 함수를 지니고 있으며 
		해당 함수를 사용하면 가리키고 있는 대상의 레퍼런스 카운트를 가져오는 것이 가능하다
		*/

		printf("\nshared ptr 할당전\n");
		printf("ref count %d \n", oSharedPtrA.use_count());

		/*
		shared ptr 객체를 다른 객체에 할당할 경우 내부적으로 가리키고 있는 
		대상의 레퍼런스 카운트가 증가하는 것을 확인 할수있다.
		*/

		oSharedPtrB = oSharedPtrA;
		
		printf("\nshared ptr 할당후\n");
		printf("ref count %d \n", oSharedPtrA.use_count());

		/*
		shared ptr 객체의 reset맴버함수를 사용하면 해당 포인터 객체가 가리키고 있는 대상의 참조를 해제가 가능하다
		즉 해당 함수가 호출되는 순가 가리키고있는 대상의 레퍼런스 카운트가 감소하는 것으 알수있다
		
		oSharedPtrA.swap
		두 shared ptr객체가 가리키는 대상을 서로 교환 하고 싶다면 swap 맴버 함수를 사용하면 된다
		ex	 std::shared_ptr<int> oPtrA(new int(10));
			 std::shared_ptr<int> oPtrB(new int(20));
			 oPtrA.swap(oPtrB)
		*/

		oSharedPtrA.reset();
		

		printf("\nshared ptr a 참조 해제후\n");
		printf("ref count %d \n", oSharedPtrB.use_count());
		#elif WEAK_PTR 
		std::shared_ptr<CWidgetA> oWidgetAPtr(new CWidgetA());
		std::shared_ptr<CWidgetB> oWidgetBPtr(new CWidgetB());
		
		oWidgetAPtr->SetTarget(oWidgetBPtr);
		oWidgetBPtr->SetTarget(oWidgetAPtr);

		#endif
		#elif E08_LAMBDA
		
		printf("\n람다 선언과 동시에 호출 결과\n");
		/*
		람다를 선언후 바로 호출 했을 경우 해당 람다는 더이상 재사용이 불가능한 진정한 일회성 함수가 된다 
		*/
		[](int a_nLhs, int a_nRhs)
		{
			printf("%d + %d = %d\n", a_nLhs, a_nRhs, a_nLhs + a_nRhs);
		}(10, 20);

		/*
		람다는 특정 지역에 선언되고 사용되는 내장 함수이며 해당 함수를 함수포인터를 사용하는 것 처럼
		다른 지역 변수에 람다를 할당및필요할때 호출하는 것이 가능하다

		이때 람다의 자료형을 사용자는 알수없기 때문에 해당 람다를 특정 변수에 보관하기 위해서 auto 키워드를 사용해서 컴파일러가
		자동으로 자료형을 결정하도록 만들어 줘야한다 
		*/
		printf("\n람다 선언후 할당 및 재사용 결과\n");
		auto oLambdaA = [](int a_nLhs, int a_nRhs)
		{
			printf("%d + %d = %d\n", a_nLhs, a_nRhs, a_nLhs + a_nRhs);
		};
		
		oLambdaA(10, 20);
		oLambdaA(30, 40);

		int nLhs=0;
		int nRhs=0;

		printf("\n정수 2개 입력\n");
		scanf("%d %d", &nLhs, &nRhs);
		/*
		람다는 캡쳐절을 사용하면 람다 외부에 존재하는 변수를 매개변수 전달없이 람다 함수 내부에서 사용하는 것이 가능하다
		즉 일반적인 함수는 외부에 존재하는 변수에 접근하기 위해서는 반드시 함수 입력으로 해당 변수의 포인터 또는 레퍼런스를 전달해야하지만 람다는
		캡쳐절을 사용하면 외부 변수를 매개 변수로 전달 받지 않고도 사용하는 것이 가능하다

		람다외부 변수 캡쳐 형식 
		-값형식 캡쳐
		-참조형식 캡쳐
		값 형식 캡쳐란?
		람다 외부에 존재하는 변수의 사본을 생성하는 방식으로 동작하는 캡쳐 방식이다
		즉 캡쳐된 변수는 외부의 변수와 다른 별도의 변수이기 때문에 람다 함수 내부에서 
		해당 변수를 수정한다 하더라도 외부에 존재하는 원본 변수에는 영향을 미치지 않는다
		
		참조 형식 캡쳐란?
		람다 외부에 존재하는 변수의 참조를 생성하는 방식으로 동작하는 캡쳐 방식이다 
		따라서 참조 형식으로 캡쳐된 변수를 람다 내부에서 수정할 경우 원본 변수에도 영향을 미친다
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

		printf("\n참조형식 캡쳐 결과\n");
		printf("nLhs %d  nRhs %d ", nLhs, nRhs);
		
		/*
		값형식으로 캡쳐된 사본은 기본적으로 수정이 불가능한 상수로 캡쳐가 되기 때문에 만약 람다 함수 내부에서
		해당 변수를 수정하고 싶으면 mutable 키워드를 사용해서 상수가 아닌 변수로 외부의 변수가 캡쳐해야한다
		*/
		auto oLambdaD = [nLhs, nRhs](void) mutable //mutable은 상수도 변경할수있게 만든다
		{
			nLhs *= 2;
			nRhs *= 2;
		};

		oLambdaD();

		printf("\n값형식 캡쳐 결과\n");
		printf("nLhs %d  nRhs %d ", nLhs, nRhs);
		/*
		람다 함수의 반환 값에 대한 자료형을 명시하고 싶을 경우 람다 함수의 매개 변수 정보 뒤에서 반환 값에 대한 자료형을 명시하면 된다
		즉 c++언어는 함수의 앞에 반환형을 명시하는 것이 기본적인 문법이지만
		이를 매개 변수 정보 뒤에 명시하는 것도 가능하다
		*/
		auto oLambdaE = [nLhs, nRhs](void) mutable ->int //mutable은 상수도 변경할수있게 만든다
		{
			return nLhs + nRhs;
		};
		printf("\n람다 함수 반환 결과\n");
		printf("%d + %d = %d\n", nLhs, nRhs, oLambdaE());
		#endif // E08_AUTO
	}
}
