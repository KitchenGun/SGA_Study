#include <stdio.h>
#include "Circular_Queue.h"

void main()
{
	Circular_Queue<int> queue(10);
	queue.Enqueue(0);
	printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	queue.Enqueue(1);
	printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	queue.Enqueue(2);
	printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	queue.Enqueue(3);
	printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	for (int i = 0; i < 3; i++)
	{
		printf("Dequeue : %d,", queue.Dequeue());
		printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	}
	
	int count = 100;
	while (queue.isFull()==false)
	{
		queue.Enqueue(count++);
	}
	printf("Capacity : %d, Size : %d\n", queue.Capacity(), queue.Size());
	printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	printf("is full : %d\n", queue.isFull() == true ? 1 : 0);

	while (queue.isEmpty() == false)
	{
		printf("Dequeue : %d, ",queue.Dequeue());
		printf("Front : %d, Rear : %d\n", queue.Front(), queue.Rear());
	}
}