#include <iostream>
#include "Linked_Queue.h"

int main()
{
	Linked_Queue<int> queue;
	queue.Enqueue(0);
	std::cout << queue.Count() <<std::endl;
	queue.Enqueue(1);
	std::cout << queue.Count() << std::endl;
	queue.Enqueue(2);
	std::cout << queue.Count() << std::endl;
	queue.Enqueue(3);
	std::cout << queue.Count() << std::endl;
	while (!queue.IsEmpty())
	{
		std::cout << queue.Dequeue() << std::endl;
		std::cout << queue.Count() << std::endl;
	}
}