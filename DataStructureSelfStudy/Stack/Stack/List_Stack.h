#pragma once
#include <iostream>
using namespace std;

template<typename T> class ListStack
{
public:
	struct Node
	{
		Node* Next;
		T Data;
	};

public:
	bool IsEmpty()
	{
		return Head == nullptr;
	}

	Node* GetTop()
	{
		return top;
	}

	void Push(Node* node)
	{
		if (Head != nullptr)
		{
			Node* tail = Head;
			while (tail->Next != nullptr)
			{
				tail = tail->Next;
			}
			tail->Next = node;
		}
		else
		{
			Head = node;
		}
		top = node;
	}

	Node* Pop()
	{
		Node* temp = top;
		if (Head == top)
		{
			top = nullptr;
			Head = nullptr;
		}
		else
		{
			Node* tail = Head;
			while (tail != nullptr && tail->Next != top)
			{
				tail = tail->Next;
			}
			top = tail;
			tail->Next = nullptr;
		}

		return temp;
	}

	int Size()
	{
		int count = 0;
		Node* Current = Head;

		while (Current != nullptr)
		{
			count++;
			Current = Current->Next;
		}

		return count;
	}



	static Node* Create(T data)
	{
		Node* node = new Node();
		node->Data = data;
		return node;
	}

	static void Destroy(Node* node)
	{
		delete node;
		node = nullptr;
	}

private:

	Node* Head = NULL;
	Node* top = NULL;
};