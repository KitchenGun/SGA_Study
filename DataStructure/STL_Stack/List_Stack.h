#pragma once

#include <Windows.h>
#include <string>
using namespace std;

template<typename T> class Stack
{
public:
	struct Node;
public:

	bool IsEmpty() { return head == NULL; }
	Node* Top() { return top; }

	void Push(Node* node)
	{
		if (head != NULL)
		{
			Node* tail = head;
			while (tail->Next != NULL)
			{
				tail = tail->Next;
			}
			tail->Next = node;

		}
		else
		{
			head = node;
		}

		top = node;   //연결리스트의 tail과 top은 동일하다
	}

	Node* Pop()
	{
		Node* temp = top;
		if (head == top)
		{
			head = NULL;
			top = NULL;
		}
		else
		{
			Node* tail = head;
			while (tail != NULL && tail->Next != top)
			{
				tail = tail->Next;
			}
			top = tail;
			tail->Next = NULL;
		}

		return temp;
	}

	int Size()
	{
		int count = 0;
		Node* current = head;
		while (current != NULL)
		{
			current = current->Next;
			count++;
		}
		return count;
	}

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	static void Destroy(Node* node)
	{
		delete node;
		node = NULL;
	}
public:
	struct Node
	{
		Node* Next;
		T Data;
	};
private:
	Node* head = NULL;
	Node* top = NULL;
};