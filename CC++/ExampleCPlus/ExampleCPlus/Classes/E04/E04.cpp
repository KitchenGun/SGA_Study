#include "E04.h"

//#define E04_INHERITANCE	1
//#define E04_POLYMORPHISM	2
#define E04_PRACTICE		3

#if E04_PRACTICE

//#define PRACTICE_A	1;
#define PRACTICE_B	2;

#endif 
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
#if PRACTICE_A
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
			printf("%d ", a_oArray.GetValue(i));
		}
		printf("\n");
	}



#elif PRACTICE_B
enum class EMenu
{
	NONE = -1,
	ADD_TRIANGLE,
	ADD_RECTANGLE,
	ADD_LINE,
	DRAW_SHAPES,
	EXIT,
	MAX_VALUE

};

enum class EColor
{
	NONE = -1,
	RED,
	GREEN,
	BLUE,
	MAX_VALUE
};

class CShape
{
public:
	//색상 반환
	const char* GetColorStr(void)const
	{
		static const char*apszColorStrs[] = {
		"빨간색",
		"녹색",
		"파란색"
		};

		return apszColorStrs[(int)m_eColor];
	}
	/*
	c++언어는 mutable 키워드를 맴버 변수 앞에 명시함으로 써 해당 변수를 상수 맴버 함수 내부에서 변경이 가능하다
	const cast 와 마찬가지로 mutable 키워드는 사용하지 않는 것이 좋은 습관이다. 
	*/
	//도형을 그린다
	virtual void DrawShape(void)= 0;
protected://생성자
	/*
	c++클래스의 생성자를 public 수준이 아닌 다른 보호 수준으로 명시했을 경우 
	이는 객체를 생성할수있는 범위를 제한 시키는 것을 의미한다
	즉 protected  수준일 경우 해당 생성자는 자식 클래스 또는 내부에서만 호출 가능하기 때문에 이는 곧 외부에서 
	해당 객체를 직접적으로 생성하는 것이 불가능 하다는 것을 의미한다
	*/
	CShape(const EColor a_eColor)
	:
	m_eColor(a_eColor)
	{
		//do nothing
	}
protected:
	mutable EColor m_eColor = EColor::NONE;
};
/*
c++언어는 클래스 상속시 해당 클래스의 상속 수준을 명시하는 것이 가능하다
이는 부모 클래스의 최소 보안 수준을 명시하는 것으로 써 만약 protected로 상송을 시도할 경우 
부모 클래스의 private 와 protected 수준은 그대로 상속이 되지만 public 수준은 protected로 보정이 되어서 상속이 된다
(public 이외로 상속 시도시 부모클래스의 맴버는 외부에서 접근 불가능 하다)
*/
class CTriangle :public CShape
{
public:
	//도형을 그린다
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s 삼각형을 그린다\n",pszColorStr);
	}

public:
	//생성자
	CTriangle(const EColor a_eColor)
	:
	CShape(a_eColor)
	{
		//do nothing
	}
};

class CRectangle :public CShape
{
public:
	//도형을 그린다
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s 사각형을 그린다\n", pszColorStr);
	}

public:
	//생성자
	CRectangle(const EColor a_eColor)
	:
	CShape(a_eColor)
	{
		//do nothing
	}
};

class CLine :public CShape
{
public:
	//도형을 그린다
	virtual void DrawShape()override
	{
		const char *pszColorStr = this->GetColorStr();
		printf("%s 선을 그린다\n", pszColorStr);
	}

public:
	//생성자
	CLine(const EColor a_eColor)
		:
		CShape(a_eColor)
	{
		//do nothing
	}
};

class CCanvas
{
public://함수
	void AddShape(std::shared_ptr<CShape> a_oShapePtr)
	{
		m_oShapeList.push_back(a_oShapePtr);
	}
	//도형 그린다
	void DrawShapes(void)
	{
		for (int i = 0; i < m_oShapeList.size(); ++i)
		{
			m_oShapeList[i]->DrawShape();
		}
	}
public://소멸자
	virtual ~CCanvas(void)
	{
		//for (int i = 0; i < m_nNumShapes; ++i)
		//{
		//	SAFE_DELETE(m_apShapes[i]);
		//}
	}
private:
	//변수
	int m_nNumShapes = 0;
	std::vector<std::shared_ptr<CShape>> m_oShapeList;
	//CShape *m_apShapes[100];
};

CShape *CreateShape(EMenu a_eMenu)
{
	/*
	uniform int distribution 객체는 최대 값을 포함한 해당 범위의 난수를 생성한다 즉 최소 0 ~ 최대 2 명시 경우 난수 값의 범위는 0~3까지 이다
	*/
	std::random_device oRandom;
	std::uniform_int_distribution<int> oUniform((int)EColor::RED,(int)EColor::BLUE);

	EColor eColor = static_cast<EColor>(oUniform(oRandom));
	switch (a_eMenu)
	{
	case EMenu::ADD_TRIANGLE: 
		return new CTriangle(eColor); break;
	case EMenu::ADD_RECTANGLE: 
		return new CRectangle(eColor); break;
	case EMenu::ADD_LINE:
		return new CLine(eColor); break;
	}
}
#endif
#elif E04_POLYMORPHISM
	//부모클래스
	class CParent
	{
	public:

		/*
		맴버 함수에 virtual 키워드를 명시하면 해당함수는 가상함수가 된다.
		가상함수란 ?
		특정 클래스가 부모 자식 관계를 형성하고 있을때 만약 부모 클래스의 특정 함수를 자식 클래스에서 동일하게 구현했을 경우
		부모 클래스의 함수가 아니라 자식 클래스의 함수를 호출 하도록 해주는 맴버 함수를 의미한다
		또한 이처럼 부모 클래스의 함수 대신 자식 클래스의 함수가 호출되는 현상을 오버라이드 조건이 성립되었다고 한다.

		단 자식 클래스의 함수가 오버라이드 조건을 만족하기 위해서는 반드시 부모 클래스에 존재하는 맴버함수와 원형이 일치해야한다
		함수 뒤에 ovveride를 붙이면 오류를 띄워준다

		c++언어 오버라이드 구현 원리 
		:
		c++특정 클래스의 가상함수가 하나라도 존재할경우 컴파일러는 함수 포인터로 이루어진 가상함수 테이블을 생성하고 
		해당 테이블을 가리키는 포인터가 자동으로 클래스에 추가 된다
		따라서 가상 함수 테이블에 존재하는 맴버 함수를 호출할 경우 
		해당 함수가 직접적으로 호출 되는 것이 아니라 가상 함수 테이블 참조해서
		해당 테이블에 존재하는 함수 포인터가 가리키는 맴버 함수가 호출된다
		즉 가상 함수 테이블이 컴파일러에 의해서 자동으로 해당 클래스에 추가되기 때문에 
		가상함수를 하나라도 지니고 있는 객체는 절대로 memset으로 초기화 시도하면 안된다
		*/
		//정보를 출력한다
		virtual void ShowInfo()
		{
			printf("CParent.ShowInfo()호출\n");
		}
	public:
		/*
		일반적으로 동적으로 생성된 부모 클래스의 포인터로 제거했을 경우
		자식 클래스의 소멸자가 호출 되지 않는 현상이 발생한다 따라서 해당 현상을 해결하기 위해서는 
		반드시 부모 클래스의 소멸자에 virtual 키워드를 명시하여
		해당 소멸자를 사상 소멸자로 선언해줘야한다

		즉 특정 클래스의 소멸자가 가상 소멸자가 아니라면 이는 해당 클래스를 절대로 상속하지 말라는 것이 암묵적인 관례이다.
		*/
		virtual ~CParent()//가상 소멸자 
		{
			printf("부모 소멸자 호출\n");
		}
	};
	//자식클래스
	class CChild:public CParent
	{
	public:
		/*
		자식 클래스에서 부모클래스와 동일한 원형을 지닌 가상함수 선언했을때 
		해당 함수 또한 컴파일러에 의해서 자동으로 가상 함수로 선언 된다
		가상함수와 동일한 원형을 지닌 함수를 자식에 선언했을 경우 virtual 키워드를 명시해주는 것이 좋은 습관이다.
		c++11버전에서는 override 라는 키워드를 지원해주기 때문에 부모 클래스의 맴버함를 잘못된 원형으로 자식 클래스를 오버라이드 했을 경우
		컴파일러에 의해서 에러발생이 가능 하다 즉 사전에 감지하는 것이 가능하다. 
		
		c++11 이상 부터는 final 키워드를 통해서 해당 맴버 함수를 자식 클래스 에서 더이상 오버라이드가 불가능 하도록 막아버리는 것이 가능하다 즉 클래스
		설계함에 있어서 부모 클래스의 특정 맴버함수를반드시 호출 해야할 경우 해당 키워드를 사용함으로써 자식 클래스에서 오버라이드 시키는 실수방지 가능하다

		*/
		//정보를 출력한다
		virtual void ShowInfo() final override
		{
			this->DoShowInfo();
			printf("CChild.ShowInfo()호출\n");
		}

	protected:
		//순수 가상함수
		/*
		가상 함수에 0 기호를 명시함으로써 해당 함수를 순수 가상함수로 선언하는 것이 가능하다
		순수 가상함수란?
		함수의 구현부를 지니고 있지 않은 가상함수를 의미하며 특정 클래스에 순수 가상 함수가 하나라도 존재할경우 해당 클래스는 객체화 시킬수없는 추상 클래스가 된다
		즉 특정 클래스를 통해서 객체를 생성하기 위해서는 해당 객체에 대한 속성및 행위가 정해져있어야하기 때문에 
		순수 가상함수를 지니고 있다는 것은 해당 행위에 대한 정보가 없다는 것을 의미하며 이는 곧 객체를 생성하기위한 정보가 불안정하다는 것을 의미한다
		순수 가상함수를 지니고 있는 추상 클래스는 직접적으로 객체화 시킬수는 없지만 자식 클래스에서 해당 클래스를 상속함으로 객체화가 가능하다 
		단 이경우 자식클래스에서 반드시 부모클래스에 존재하는 순수 가상 함수를 모두 오버라이드 및 구현해줘야 한다
		만약 오버라이드 하지 않을 경우 객체화 시킬수없는 추상함수 클래스가 된다

		이걸 사용하면 인터페이스를 흉내낼수있다.
		*/
		virtual void DoShowInfo() = 0; 
	public:
		virtual ~CChild()
		{
			printf("자식 소멸자 호출\n");
		}
	};
	//서브 자식 클래스
	class CSubChild : public CChild
	{
	public:
		//값 변환 한다
		int GetValue(void)
		{
			return m_nValue;
		}

		//상수 맴버 함수
		/*
		const cast 형변환 연산자를 사용하면 상수정을 일시적으로 제거하는 것이 가능하다 
		따라서 상수맴버 함수 내부라 하더라도 해당 연산자를 사용하면 맴버 변수의 값을 변경하는 것이 가능하다
		단 const cast는 기존의 논리를 무너뜨리는 행위를 수행하기 때문에 가능하면 사용하지 않는 것이 좋은 습관이다
		(최후의 보루다)
		*/
		void ConstMemFunc(void)const
		{//const cast
			const_cast<CSubChild*>(this)->m_nValue = 10;
		}
	protected:

		virtual void DoShowInfo() override
		{
			printf("CSubChild.DoShowInfo()호출\n");
		}

	private:
		int m_nValue = 0;
	public: //소멸자
	virtual ~CSubChild()
	{
		printf("서브 자식 소멸자 호출\n");
	}
	};

#endif // E04_INHERITANCE

	void E04(const int argc, const char ** args)
	{
#if E04_INHERITANCE
		CChild oChild;
		oChild.PrintInfo();

#elif E04_PRACTICE
#if  PRACTICE_A
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

#elif PRACTICE_B
		EMenu eMenu = EMenu::NONE;
		CCanvas oCanvas;
		do
		{
			printf("\n메뉴\n");
			printf("1.삼각형 추가\n");
			printf("2.사각형 추가\n");
			printf("3.선 추가\n");
			printf("4.도형 그리기\n");
			printf("5.종료\n");
			printf("\n 메뉴 선택 : ");
			scanf("%d", &eMenu);

			eMenu = static_cast<EMenu>((int)eMenu - 1);

			switch (eMenu)
			{
			case EMenu::ADD_TRIANGLE:
			case EMenu::ADD_RECTANGLE:
			case EMenu::ADD_LINE:
			{
				CShape *pShape = CreateShape(eMenu);
				oCanvas.AddShape(std::shared_ptr<CShape>(pShape));
				break;
			}
			case EMenu::DRAW_SHAPES:
			{
				oCanvas.DrawShapes();
				break;
			}
			case EMenu::EXIT:
			{
				break;
			}
			default:
				break;
			}

		} while (eMenu != EMenu::EXIT);

#endif //PRACTICE_A
#elif E04_POLYMORPHISM
		/*
		부모 클래스의 포인터로 자식 객체를 가리키는 것은 허용되지만 반대로 자식 클래스의 포인터로 부모 객체를 가리키는 것은 불가능 하다
		*/
		CParent *pParentA = new CParent();
		CParent *pParentB = new CSubChild();
		/*
		c++ 형변환 연산자의 종류
		//형변환 연산자들은 읽는 방법을 잠깐 바꾸는 것이다 이걸 포인터에 저장하지 않으면 원래 상태로 돌아간다
		static_cast			불완전한 다운 캐스팅 지원  (기존 c의 형변환과 동일한 형태)책임은 사용자에게
		dynamic_cast		안전한 다운캐스팅 지원
		const_cast			객체의 상수성 제거 지원  상수성 제거는 최후의 보루
		reinterpert_cast	정수<->주소간의 형변환

		*/
		CChild *pChildA = new CSubChild;
		CChild *pChildB = dynamic_cast<CChild*>(pParentB);
		/*
		dynamic cast 형 변환 연산자에 의해서 다운 캐스팅이 불가능 할경우 null 포인터가 반환 된다는 것을 알수있다
		해당 연산자는 안전한 다운 캐스팅을 지원하기 위해서 내부적으로 안전성을 검사하는 코드들이 자동으로 추가되기 때문에
		이는 곧 퍼포먼스 저하를 유발시킬수 있다.

		단 dynamic cast 형변환 연산자를 사용할때 가상함수가 존재하지 않으면 사용할수없다
		이는 캐스팅 가능 여부를 가상함수 테이블을 대상으로 비교를 시도하기 때문에 가상함수 테이블이 없다면 해당 연산자를 사용하는 것이 불가능하다

		*/
		//자식 클래스 형변환 가능할경우
		if (pChildB != NULL)
		{
			printf("부모->자식 형 변환 가능\n");
		}

		//child 클래스는 추상 클래스이기 때문에 new 키워드를 통해서 객체를 생성하는 것이 불가능하다
		//CChild *pChildB = new CChild;
		//CChild *pChildB = new CParent;

		pParentA->ShowInfo();
		printf("\n");
		pParentB->ShowInfo();
		printf("\n");
		pChildA->ShowInfo();
		printf("\n");
		printf("\n==========상수 맴버 함수 호출=========\n");
		static_cast<CSubChild*>(pChildA)->ConstMemFunc();
		printf("Value : %d\n\n", static_cast<CSubChild*>(pChildA)->GetValue());

		//pChildB->ShowInfo();
		SAFE_DELETE(pParentA);
		printf("\n");
		SAFE_DELETE(pChildA);
		printf("\n");
		SAFE_DELETE(pParentB);//자식을 넣어도 자식소멸자 호출안됨 virtual로 해결
		printf("\n");
		//SAFE_DELETE(pChildB);

#endif // E04_INHERITANCE
	}
}
