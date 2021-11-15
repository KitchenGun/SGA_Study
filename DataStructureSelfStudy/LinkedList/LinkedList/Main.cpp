#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList* LL = new LinkedList();

	for(int i =0;i<5;++i)
	{
		LL->Push(LL->Create(i));
	}

	for (int i = 0; i < LL->GetNodeCount(); i++)
	{
		printf("LinkedList[%d] : {%d}\n", i, LL->GetNode(i)->Data);
	}
	printf("\n");
	//getnode
	Node* temp = LL->GetNode(3);
	printf("LinkedList[3] : {%d}\n", temp->Data);
	printf("\n");
	//insert
	Node* newNode = LL->Create(-1);
	LL->InsertHead(newNode);
	printf("LinkedList[%d] : {%d}\n", 0,LL->GetNode(0)->Data);
	printf("\n");
	//Remove
	LL->Remove(temp);
	for (int i = 0; i < LL->GetNodeCount(); i++)
	{
		printf("LinkedList[%d] : {%d}\n", i, LL->GetNode(i)->Data);
	}
	printf("\n");
}