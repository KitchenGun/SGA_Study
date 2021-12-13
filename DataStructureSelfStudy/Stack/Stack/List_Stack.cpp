#include "List_Stack.h"
#include <string>
int main()
{
	ListStack<string>* stack = new ListStack<string>();

	stack->Push(ListStack<string>::Create("abc"));
	stack->Push(ListStack<string>::Create("def"));
	stack->Push(ListStack<string>::Create("ghi"));
	stack->Push(ListStack<string>::Create("jkl"));

	cout << "Size " << stack->Size() << endl;

	int count = stack->Size();
	for (int i = 0; i < count; i++)
	{
		if (stack->IsEmpty())
			break;
		ListStack<string>::Node* temp = stack->Pop();

		cout << temp->Data << endl;
		ListStack<string>::Destroy(temp);

		if (stack->IsEmpty() == false)
		{
			cout <<"top" << stack->GetTop()->Data << endl;
		}
		else
		{
			cout << "is empty" << endl;
		}
	}

}