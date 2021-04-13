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

	private:
		int m_nHP;
		int m_nATK;
	};

	
	void E03(const int argc, const char ** args)
	{
		CPlayer oPlayerA;
		CPlayer oPlayerB;
		oPlayerA.SetHP(100);
		oPlayerA.SetATK(15);
		oPlayerB.SetHP(50);
		oPlayerB.SetATK(35);


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
