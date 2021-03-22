#include<iostream>
#include<stdio.h>
using namespace std;

template<typename T> class Character
{
public:
	void Set(T name)
	{
		this->name = name;
	}

	void Print()
	{
		cout << "캐릭터이름:" << name << endl;
	}
private:
	T name;
};


class Player:public Character<string>//상속
{

};

class A
{
public:
	//class 내부에서 정의된 함수는 자동으로 inline처리가 된다
	void inlineFunc()
	{

	}

	void Test();
	//인라인 화를 요청하는 것 속도면에서 차이가 없으면 일반함수로 사용함
		inline void Test1();//cpp에서만 사용가능

		_inline void Test2();//cpp와 c 양쪽다 사용가능//__inline과 동의어

		__inline void Test3();//cpp와 c 양쪽다 사용가능
	//강제로 인라인 화 하는 거임
	__forceinline void Test4();//cpp와 c 양쪽다 사용가능 차이점은강제적으로 inline화 시킴 하지만, 상황에 따라 코드가 인라인 되지 않을 수 있음



};

void main()
{
	Character<int> ob;//템플릿 클래스는 인수를 꼭 지정해줘야한다
	ob.Set(20);
	ob.Print();

	Player player;
	player.Set("포링");
	player.Print();
}


//class 내부에서 정의된 함수는 자동으로 inline처리가 된다
inline void A::Test()
{
	//인라인 함수
}

void A::Test1()
{
	//역시 인라인함수
}
