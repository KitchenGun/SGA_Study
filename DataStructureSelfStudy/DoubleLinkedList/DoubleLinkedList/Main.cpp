#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
	DLL* dll = new DLL();

	Node* node = nullptr;
	
	for (int i = 0; i < 5; ++i)
	{
		node = dll->Create(i);
		dll->Push(node);
	}

	node = dll->Create(-1);
	dll->HeadInsert(node);



	Node* Current = dll->GetNode(3);
	node = dll->Create(100);
	dll->Insert(Current, node);
	dll->Remove(Current);
	dll->Destroy(Current);

	for (int i = 0; i < dll->GetNodeCount(); ++i)
	{
		printf("%d node date : %d\n", i, dll->GetNode(i)->Data);
	}
}