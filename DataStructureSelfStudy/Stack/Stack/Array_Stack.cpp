#include "Array_Stack.h"


int main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	

	while (!stack.isEmpty())
	{
		cout << stack.Pop() << endl;
	}
}