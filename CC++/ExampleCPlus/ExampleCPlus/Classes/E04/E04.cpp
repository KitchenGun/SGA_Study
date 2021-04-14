#include "E04.h"
namespace E04Space
{
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
	private:
		char m_szString[100] = "";
	};

	void E04(const int argc, const char ** args)
	{
		CParent oParent;
		oParent.PrintInfo();

		CChild oChild;
		oChild.PrintInfo(); 

	}
}
