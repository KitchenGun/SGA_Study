#include "E04.h"

//#define E04_INHERITANCE	1
//#define E04_PRACTICE		2
#define E04_POLYMORPHISM	3

namespace E04Space
{
#if E04_INHERITANCE
	//부모클래스
	class CParent
	{
	public:
		/*
		부모클래스와 자식 클래스는 서로 다른 영역이기 때문에 동일한 원형을 지니는 함수를 구현하는 것이 가능하다
		이때 우선순위는 자식 클래스에 정의 되어있는 함수가 더 높은 우선순위를 가진다
		만약 자식 클래스의 함수 내부에서 부모 클래스의 동일한 이름을 지니는 함수를 호출하고 싶다면 :: 범위 지정연산자를 사용하면 된다
		*/
		//정보를 출력한다
		void PrintInfo()
		{
			printf("부모객체 정보\n");
			printf("int : %d\n", m_nValue);
			printf("float : %f\n", m_fValue);
		}

	public:
		//생성자
		CParent(int a_nValue, float a_fValue)
			:
			m_nValue(a_nValue),
			m_fValue(a_fValue)
		{
			printf("Cparent(int,float)부모클래스 생성자 호출\n");
		}
		//소멸자
		~CParent(void)
		{
			printf("Cparent(int,float) 부모클래스 소멸자 호출\n");
		}
	protected:
		int m_nValue = 0;
		float m_fValue = 0.0f;
	};
	//자식 클래스
	class CChild : public CParent
	{
	public:
		//정보를 출력
		void PrintInfo()
		{
			CParent::PrintInfo();
			printf("\n자식객체 정보\n");
			printf("string : %s\n", m_szString);
		}
	public:
		/*
		클래스가 상속 관계일때 생성자의 올바른 호출 순서는 부모 클래스에서 자식 순서로 호출되는 것이다. 만약 부모 클래스의 생성자를 호출하는 구문을 생략했을 경우
		컴파일러에 의해서 자동으로 부모 클래스의 기본 생성자를 호출하는 구문이 추가 된다.

		따라서 부모 클래스에 기본 생성자가 존재하지 않을 경우
		반드시 자식 클래스의 생성자를 맴버 이니셜라이저 구문을 통해서 부모클래스의 생성자를 명시적을 호출해줘야한다
		*/
		//생성자
		CChild(void) : CChild(0, 0.0f, "")//부모클래스 먼저 있어야 하기때문에 이렇게 자식 객체에서 선언 해야함 위임 생성자 사용
		{
			printf("Cchild(void)자식클래스 생성자 호출\n");
		}
		CChild(int a_nValue, float a_fValue, const char *a_pszString)
			:
			CParent(a_nValue, a_fValue)
		{
			strcpy(m_szString, a_pszString);
			printf("Cchild(int,float,const char*)자식클래스 생성자 호출\n");
		}
		/*
		특정 클래스 상속 관계에 있을때 소멸자의 호출 순서는 생성자와 달리 자식 클래스에서 부모 순서로 호출된다
		*/
		//소멸자
		~CChild(void)
		{
			printf("Cchild(void)자식클래스 소멸자 호출\n");
		}
	private:
		char m_szString[100] = "";
	};
#elif E04_PRACTICE
	//배열
	class CArray
	{
	public:
		enum
		{
			DEF_SIZE = 5
		};
	public: //operator
		/*
		이미 생성이 완료된 객체에 다른 객체의 정보를 복사하기 위해서는 할당 연산자 오버로딩 이라고 하는 특수한 맴버 함수를 구현해야한다

		해당 함수 또한 컴파일러에 의해서 자동으로 만들어지는 함수 
		할당연산자 오버로딩이 존재하지 않을 경우 컴파일러가 자동으로 얕은 복사를 수행하는 해당 함수를 추가 한다.
		*/
		CArray& operator=(const CArray &a_rOther)//객체를 대상으로 연산자를 쓸수있게 만드는 부분 
		{
			SAFE_DELETE_ARRAY(m_pnValues);
			
			m_nSize = a_rOther.m_nSize;
			m_nNumValues = a_rOther.m_nNumValues;

			m_pnValues = new int[a_rOther.m_nSize];
			memcpy(m_pnValues, a_rOther.m_pnValues, sizeof(int)*a_rOther.m_nSize);

			/*
			c++ 모든 맴버 함수에는 해당 함수를 호출한 객체를 가리키는 this 포인터가 전달 된다
			this 포인터는 현재 해당함수를 호출한 객체를 가리키는 용도이며 해당 포인터가 존재하기 때문에 맴버 함수에서 맴버 변수에 접근하는 것이 가능하다
			->는 포인터에서 값을 전달할때 싸용함 
			*/
			return *this;
		}

	public:
		/*
		c++클래스 맴버함수는 const 키워드를 명시하여 해당함수를 
		상부 맴버 함수로 정의 하는 것이 가능하다

		상수 맴버 함수란?
		함수 내부에서 맴버 변수를 수정할수없는 함수를 상수 맴버 함수라고 한다
		즉 해당 함수는 객체가 상수일 경우 컴파일러에게 해당 함수 내부에서는 
		값의 변경이 발생하지 않는다는 보장을 하기 위한 용도이다.
		
		따라서 상수 객체는 일반적인 맴버 함수는 호출 할 수 없으면 상수 맴버 함수만 호출이 가능하다 
		이는 일반적인 맴버함수 내에서 맴버 변수를 수정함에 있어서 발생하는 논리의 모순을 방지하기 위한것이다.
		*/
		//값의 개수를 반환
		int GetNumValues() const
		{
			return m_nNumValues;
		}
		//값을 반환한다
		int GetValue(int a_nIdx)const
		{
			return m_pnValues[a_nIdx];
		}
		//값을 변경한다
		void SetValue(int a_nIdx, int a_nValue)
		{
			m_pnValues[a_nIdx] = a_nValue;
		}
		//값을 추가한다
		void AddValue(int a_nValue)
		{
			//배열이 가득 찼을 경우
			if (m_nNumValues >= m_nSize)
			{
				m_nSize *= 2;
				m_pnValues = (int *)realloc(m_pnValues, sizeof(int)*m_nSize);
			}

			m_pnValues[m_nNumValues++] = a_nValue;
		}


	public://생성자 소멸자
		/*
		c++의 함수에 매개 변수가 존재 할 경우 해당 매개 변수의 입력 값 없이 함수를 호출하는 것이 가능하다
		즉 해당 행위가 가능한 이유는 함수에 입력 값이 없을 경우 자동으로 기본값을 설정할 수 있는 디폴트 매개 변수가 존재하기 때문이다
		
		특정 함수에 입력이 전달 되지 않았을 경우 해당 매개변수에 할당 값을 설정할수있는 기능을 의미한다.
		일반 매개변수와 혼합 사용이 가능하지만 특정 매개 변수에 디폴트 값을 할당했을경우에는 해당 매개변수 다음 부터는 디폴트 값을 명시해줘야한다.
		*/
		//CArray(int a_nParams1,int a_nSize = DEF_SIZE,int a_nParams2) 이건 에러임 
		CArray(int a_nSize = DEF_SIZE)
		:
		m_nSize(a_nSize)
		{
			m_pnValues = new int[a_nSize];
			memset(m_pnValues, 0, sizeof(int)*a_nSize);
		}
		//복사 생성자
		CArray(const CArray &a_rOther)
		{ 
			*this = a_rOther;
		}


		~CArray()
		{
			SAFE_DELETE_ARRAY(m_pnValues);

		}

	private://변수
		int m_nSize;
		int m_nNumValues;

		int *m_pnValues = nullptr;
	};

	//배열 출력
	void PrintArray(const CArray a_oArray)
	{
		for (int i = 0; i < a_oArray.GetNumValues(); ++i)
		{
			printf("%d ", a_oArray.GetValue(i)) ;
		}
		printf("\n");
	}
	


#elif E04_POLYMORPHISM
	//부모클래스
	class CParent
	{

	};
	//자식클래스
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
		부모 클래스의 포인터로 자식 객체를 가리키는 것은 허용되지만 반대로 자식 클래스의 포인터로 부모 객체를 가리키는 것은 불가능 하다
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
