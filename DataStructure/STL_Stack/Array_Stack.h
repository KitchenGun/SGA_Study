#pragma once
#define MAX_STACK_COUNT 5

#include<stdio.h>
#include<assert.h>
#include<Windows.h>

template<typename T>class Stack
{
public:
	Stack()
	{
		//memset(value, 0, sizeof(T)*MAX_STACK_COUNT);
		ZeroMemory(values, sizeof(T) * MAX_STACK_COUNT);
	}
	void Push(T val)
	{
		assert(top + 1 < MAX_STACK_COUNT); //assert 에서는 프로그램 실행 관련된 코드가 들어가면 안된다.
		values[++top] = val;
	}

	T Pop()
	{
		bool b = isEmpty();
		assert(b == false);

		T val = values[top];
		ZeroMemory(&values[top], sizeof(T));
		top--;

		return val;
	}

	T Front()
	{
		return values[top];
	}
	T Back()
	{
		assert(top > -1);

		return valuse[0];
	}

	bool isEmpty()
	{
		return top < 0 ? true : false;
	}

private:
	int top = -1;

	T values[MAX_STACK_COUNT];

};