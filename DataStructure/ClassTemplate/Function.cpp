#include <iostream>
#include <stdio.h>
using namespace std;

template<typename T> void Print(T data)
{
	cout << "함수" << data << endl;
}
template<typename T> void Print(int data)
{
	printf("sp함수 %d\n",data);
}
template<typename T> void Print(char data)
{
	printf("sp함수 %c\n", data);
}


void main()
{
	int i = 10;
	Print<int>(i);
	char b = 'A';
	Print<char>(b);

	float t = 20.0f;
	Print<float>(t);

	//명시를 잘해야한다
	//double td = 20.0L;
	//Print<int>(td);
}