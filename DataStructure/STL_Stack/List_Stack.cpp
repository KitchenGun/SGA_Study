#include <stdio.h>
#include "List_Stack.h"


//스텍은 입력된 자료의 순서를 뒤집을 때 사용된다
void main()
{
	Stack<string> stack;

	stack.Push(Stack<string>::Create("abc"));
	stack.Push(Stack<string>::Create("def"));
	stack.Push(Stack<string>::Create("ghi"));
	stack.Push(Stack<string>::Create("jkl"));

	printf("size  %d\n", stack.Size());

	int count = stack.Size();
	for (int i = 0; i < count; i++)
	{
		if (stack.IsEmpty() == true)
		{
			break;
		}
		Stack<string>::Node* temp = stack.Pop();
		printf("pop : %s\n", temp->Data.c_str());
		Stack<string>::Destroy(temp);

		if (stack.IsEmpty() == false)
			printf("top : %s\n", stack.Top()->Data.c_str());
		else
			printf("Stack is empty\n");
	}
}