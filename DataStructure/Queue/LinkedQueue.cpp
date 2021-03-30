#include <stdio.h>
#include "LinkedQueue.h"

void main()
{
	Linked_Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	printf("Size : %d\n", queue.Count());

	while (queue.IsEmpty() == false)
	{
		printf("Data : %d\n", queue.Dequeue());
	}
}