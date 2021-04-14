#include "E03.h"
namespace E03Space
{
	/*
	C++ 접근제어 지시자 한정자 종류
	public		내 외부 모두 접근 허용
	protected	자식 클래스는 접근 허용 외부에서는 접근 불가능
	private		클래스 내부에서만 접근 허용
	
	C++클래스의 모든 맴버는 기본적으로 private 수준으로 보호되어있기 때문에 만약 외부에서 접근하기위해서는
	반드시 보호 수준을 private 가 아닌 public, protected로 명시해줘야한다.

	일반적으로 클래스의 맴버 변수는 private 수준으로 보호하는 것이 관례이기 때문에 만약 해당 변수를 외부에서 사용하기 위해서는 
	외부에서는 해당 변수에 접근하기 위한 함수를 해당 클래스가 제공해야한다. 특정맴버변수를 제어할수있게 외부에 공개되는 함수를 접근자 함수라고 한다
	즉 접근자 함수는 특정함수 변수의 값을 외부로 반환시키는 getter 내부로 반환 시키는setter를 통틀어서 지칭하는 용어이다. 
	*/
	class CPlayer//클래스는 기본보호수준이 private 구조체는 기본보호수준이 public                 
		//하지만 구조체는 변수만 클래스는 함수와 변수를 선언 가능하다고 생각하자   
	{
	public:
		//HP반환한다
		int GetHP()
		{
			return m_nHP;
		}
		void SetHP(int a_nHP)
		{
			m_nHP = a_nHP;
		}
		//ATK반환한다
		int GetATK()
		{
			return m_nATK;
		}
		void SetATK(int a_nATK)
		{
			m_nATK = a_nATK;
		}

		//공격 
		void Attack(CPlayer *a_pOtherPlayer)
		{
			a_pOtherPlayer->m_nHP -= m_nATK;
		}
	public:
		/*
		c++클래스는 객체화 되기위해서는 반드시 생성자가 호출되야한다
		만약 특정 클래스에 생성자가 존재하지 않을 경우 컴파일러에 의해서 자동으로 기본생성자가 추가 된다
		
		생성자란?
		객체를 초기화 시키기 위한 용도로 사용되는 맴버함수 해당 생성자는 직접 호출이 불가능 오직 컴파일에 의해서만 호출 
		즉 객체를 생성할때 컴파일러가 해당 객체의 생성자를 호출해준다 
		만약 특정 클래스에 생성자를 1개 이상 구현했을경우 컴파일러는 더이상 해당 클래스에 기본생성자를 자동으로 추가해주지 않는다
		따라서 입력값이 없는 기본 생성자를 구현해줘야한다 따라서 필요에 따라 입력값이 없는 기본생성자를 명시적으로 구현해줘야한다
		c++11이상부터는 생성자내부에서 다른 생성자를 호출하는 것이 가능하며 이를 위임 생성자라고 한다 즉 위임 생성자를 활용하면 
		객체를 초기화 시키는 구문을 특정 생성자에만 구현하도록 하는 것이 가능하다 
		*/
		//기본 생성자
		CPlayer(void) : CPlayer(1,0,0)
		{
			//do nothing 
		}
		/*
		생성자를 통해서 맴버 변수 및 상수의 값을 초기화하기 위해서는 반드시 맴버 이니셜라저를 사용해야한다 
		즉 생성자 몸체에서 맴버의 할당하는 것은 이미 맴버가 선언된 이후다 =진정한 초기화 아님
		
		특정 클래스 맴버 상수 초기화 방법은 맴버 이니셜라이저가 유일한 방법이다.
		*/
		//생성자
		CPlayer(int a_nID, int a_nHP, int a_nATK) : m_nHP(a_nHP), m_nATK(a_nATK), m_nID(a_nID) { m_pnValue = new int(); m_pnValues = new int[5]; }
		

		/*
		c++컴파일러는 특정 객체의 사본을 생성하기 위해서 복사 생성자를 활용한다
		즉 복사 생성자는 특정 객체의 정보를 복사하기 위한 용도로 사용되는 생성자를 의미한다
		만약 특정 클래스에 복사 생성자가 존재하지 않을 경우 컴파일러에 의해서 
		자동으로 얕은 복사를 수행하는 복사 생성자가 추가 된다.
		
		얕은 복사가 문제를 발생시키는 원인이 될경우 반드시 명시적으로 복사 생성자를 구현해서 내부적으로 깊은 복사가 수행되도록 로직을 작성해야한다

		c++ 클래스를 설계할때 일반적으로 생성자에서 컴퓨터의 자원을 사용하는 구문이 존재한다면 
		이는 반드시 객체가 소멸 될때 정리해주는 것이 일반적인 관례이다.
		만약 클래스의 맴버 변수중 포인터가 존재할경우 얕은 복사의 문제가 발생하는지 항상 주의 해야한다.
		*/
		//복사 생성자   포인터를 복사할때 조심해야함  얕은 복사의 경우 주소만 복사하기때문에 오류가 발생함
		CPlayer(const CPlayer &a_rPlayer) 
		:
		m_nID(a_rPlayer.m_nID), 
		m_nHP(a_rPlayer.m_nHP),
		m_nATK(a_rPlayer.m_nATK)
		{ 
			/*
			c++에서 동적할당을 하기 위해서는 기존에 c 존재하는 동적 할당 함수를 사용해도 되지만 
			new 키워드를 통해서 동적 할당 하는것 또한 가능하다
			단 객체를 동적 할당하기 위해서는 반드시 new 키워드를 사용해야하며 
			malloc 함수등을 통해서 객체를 동적으로 할당할 경우 생성자 호출되지 않기 때문에  c에서는 객체 class 가없어서 new를 사용해야한다
			결과적으로 해당함수등을 사용해서 객체를 동적으로 생성하는 것이 불가능 하다
			*/
			m_pnValue = new int();
			*m_pnValue = *a_rPlayer.m_pnValue;
			m_pnValues = new int[5];
			memcpy(m_pnValues, a_rPlayer.m_pnValues, sizeof(int) * 5);
		}
		/*
		생성자가 객체를 초기화 시키는 용도로 사용된다면 소멸자를 객체가 사용한 자원을 정리하는 용도로 사용된다
		즉 생성자는 객체가 생성될때 호출되며 소멸자는 객체가 제거 될때 컴파일러에 의해서 호출된다
		
		new 키워드를 통해서 동적으로 할당된 메모리는 반드시 delete 키워드를 통해서 해제를 해야되며 
		new[] 키워드를 통해서 동적으로 할당된 메모리는 delete[] 키워드를 통해서 해제해야한다
		만약 서로다른 키워드를 메모리로 해제 할 경우 올바르게 메모리가 정리 되지 않는 문제가 발생한다 즉 메모리 릭을 유발 가능하다
		*/
		//소멸자
		~CPlayer(void)
		{
			delete m_pnValue;
			delete[] m_pnValues;
		}


	private:
		//c++11부터는 특정 클래스의 맴버를 선언과 동시에 초기값을 지정하는 것이 가능하다 
		//불필요하게 초기화를 위해 생성자를 구현하지 않아도 된다. 
		int m_nHP=0;
		int m_nATK=0;
		int *m_pnValue=nullptr;
		int *m_pnValues=nullptr;

		const int m_nID;
	};

	
	void E03(const int argc, const char ** args)
	{
		CPlayer oPlayerA;
		CPlayer oPlayerB(1,50, 35);
		CPlayer oPlayerC(oPlayerB);
		
		oPlayerA.SetHP(100);
		oPlayerA.SetATK(15);

		oPlayerB.SetHP(50);
		oPlayerB.SetATK(35);

		//소멸자 명시적으로 호출 가능하지만 절대 하지 말아야함
		//oPlayerC.~CPlayer();

		oPlayerA.Attack(&oPlayerB);
		printf("player a 공격 결과\n");
		printf("player a : %d %d \n", oPlayerA.GetHP(), oPlayerA.GetATK());
		printf("player b : %d %d \n", oPlayerB.GetHP(), oPlayerB.GetATK());

		oPlayerB.Attack(&oPlayerA);
		printf("player b 공격 결과\n");
		printf("player a : %d %d \n", oPlayerA.GetHP(), oPlayerA.GetATK());
		printf("player b : %d %d \n", oPlayerB.GetHP(), oPlayerB.GetATK());
	}
}
