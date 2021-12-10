#pragma once
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
class Stack
{
public:
	Stack()
	{
		//크기를 지정해주지 않으면 범위를 벗어났다고 오류가 발생한다
		values.assign(5, 0);
	}

	void Push(T val)
	{
		top++;
		values[top] = val;
	}

	T Pop()
	{
		bool b = isEmpty();
		if (!b)
		{
			T val = values[top];
			values.erase(values.begin() + top);
			top--;
			return val;
		}
		return NULL;
	}

	bool isEmpty()
	{
		return top < 0;
	}

private:
	int top = -1;
	vector<T> values;
};