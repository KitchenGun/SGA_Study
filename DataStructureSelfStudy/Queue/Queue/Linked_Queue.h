#pragma once

template<class T>class Linked_Queue
{
private:
	struct Node
	{
		Node* Next=nullptr;
		int Data;
	};
public:
	void Enqueue(T data)
	{
		Node* node = new Node();
		node->Data = data;
		if (front == nullptr)
		{
			front = node;
			rear = node;
			count++;
		}
		else
		{
			rear->Next = node;
			rear = node;
			count++;
		}
	}

	T Dequeue()
	{
		Node* node = front;
		if (front->Next == nullptr)
			front = rear = nullptr;
		else
			front = front->Next;
		
		count--;

		T val = node->Data;
		delete node;
		node = nullptr;
		return val;
	}

	bool IsEmpty()
	{
		return front == nullptr;
	}

	int Count() { return count; }
private:
	int count = 0;
	Node* front = nullptr;
	Node* rear = nullptr;
};