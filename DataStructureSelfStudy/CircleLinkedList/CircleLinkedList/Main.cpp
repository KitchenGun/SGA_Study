#include <iostream>
#include "CircleLinkedList.h"

using namespace std;
int main()
{
	CircleLinkedList* cl = new CircleLinkedList;

	for (int i = 0; i < 5; i++)
	{
		cl->Push(cl->Create(i));
	}

	Node* temp = cl->Head;
	do
	{
		cout << temp->Data << endl;
		temp = temp->Next;
	} while (temp != cl->Head);
}