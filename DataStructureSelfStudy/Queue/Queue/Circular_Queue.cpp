#include <iostream>
#include "Circular_Queue.h"

void main()
{
	Circular_Queue<int> queue(5);
	queue.Enqueue(0);
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	if (queue.IsFull())
	{
		std::cout << "full";
	}
	queue.Enqueue(5);
	queue.Enqueue(6);
	for (int i = 0; i < 5; i++)
	{
		
		printf("dequeue %d\n", queue.Dequeue());
		printf("front %d rear %d\n", queue.Front(), queue.Rear());
	}
	
	
}