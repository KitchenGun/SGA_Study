#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList* LL = new LinkedList();

	for(int i =0;i<5;++i)
	{
		LL->Push(LL->GetList(),LL->Create(i));
	}

	for (int i = 0; i < 5; i++)
	{
		printf("LinkedList[%d] : {%d}\n", i, LL->GetNode(i)->Data);
	}


}