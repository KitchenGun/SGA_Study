#include <iostream>
#include <stdio.h>
using namespace std;

template<typename T> void Print(T data)
{
	cout << "�Լ�" << data << endl;
}
template<typename T> void Print(int data)
{
	printf("sp�Լ� %d\n",data);
}
template<typename T> void Print(char data)
{
	printf("sp�Լ� %c\n", data);
}


void main()
{
	int i = 10;
	Print<int>(i);
	char b = 'A';
	Print<char>(b);

	float t = 20.0f;
	Print<float>(t);

	//��ø� ���ؾ��Ѵ�
	//double td = 20.0L;
	//Print<int>(td);
}