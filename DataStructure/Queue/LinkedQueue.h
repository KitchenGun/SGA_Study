#pragma once


template<typename T> class Linked_Queue
{
public:
	struct Node;
public:

	Linked_Queue()
	{

	}

	~Linked_Queue()
	{
		while (IsEmpty() == false)
		{
			Dequeue();
		}
	}

	void Enqueue(T data)
	{
		Node* node = new Node();
		node->Data = data;

		if (front == NULL)
		{
			front = node;
			rear = node;

			count++;

			return;
		}

		rear->Next = node;
		rear = node;

		count++;
	}

	T Dequeue()
	{
		Node* node = front;

		if (front->Next == NULL)
			front = rear = NULL;
		else
			front = front->Next;
		count--;
		
		T val = node->Data;

		delete node;
		node = NULL;
		
		return val;

	}

	bool IsEmpty()
	{
		return front == NULL;
	}

	int Count()
	{
		return count;
	}

private:
	struct Node
	{
		T Data;
		Node* Next;
	};
private:
	Node* front = NULL;
	Node* rear = NULL;

	int count = 0;
};