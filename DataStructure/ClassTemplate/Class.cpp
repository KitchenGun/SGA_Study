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
		cout << "ĳ�����̸�:" << name << endl;
	}
private:
	T name;
};


class Player:public Character<string>//���
{

};

class A
{
public:
	//class ���ο��� ���ǵ� �Լ��� �ڵ����� inlineó���� �ȴ�
	void inlineFunc()
	{

	}

	void Test();
	//�ζ��� ȭ�� ��û�ϴ� �� �ӵ��鿡�� ���̰� ������ �Ϲ��Լ��� �����
		inline void Test1();//cpp������ ��밡��

		_inline void Test2();//cpp�� c ���ʴ� ��밡��//__inline�� ���Ǿ�

		__inline void Test3();//cpp�� c ���ʴ� ��밡��
	//������ �ζ��� ȭ �ϴ� ����
	__forceinline void Test4();//cpp�� c ���ʴ� ��밡�� ������������������ inlineȭ ��Ŵ ������, ��Ȳ�� ���� �ڵ尡 �ζ��� ���� ���� �� ����



};

void main()
{
	Character<int> ob;//���ø� Ŭ������ �μ��� �� ����������Ѵ�
	ob.Set(20);
	ob.Print();

	Player player;
	player.Set("����");
	player.Print();
}


//class ���ο��� ���ǵ� �Լ��� �ڵ����� inlineó���� �ȴ�
inline void A::Test()
{
	//�ζ��� �Լ�
}

void A::Test1()
{
	//���� �ζ����Լ�
}
