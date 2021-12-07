#include "CircleLinkedList.h"


Node* CircleLinkedList::Create(int data)
{
	Node* newNode = new Node;
	newNode->Data = data;
	newNode->Prev = newNode->Next = nullptr;
	return newNode;
}

void CircleLinkedList::Destroy(Node* Target)
{
	delete Target;
	Target = nullptr;
}

void CircleLinkedList::Push(Node* node)
{
	if (Head == nullptr)
	{
		Head = node;
		Head->Next = Head;
		Head->Prev = Head;
	}
	else
	{
		Node* tail = Head->Prev;
		Head->Prev = node;
		tail->Next = node;

		node->Next = Head;
		node->Prev = tail;
	}
}

void CircleLinkedList::Insert(Node* current, Node* node)
{
	node->Next = current->Next;
	node->Prev = current;

	current->Next->Prev = node;
	current->Next = node;
}

void CircleLinkedList::Remove(Node* node)
{
	if (Head == node)
	{
		Head->Prev->Next = Head->Next;
		Head->Next->Prev = Head->Prev;

		Head = node->Next;
	}
	else
	{
		node->Prev->Next = node->Next;
		node->Next->Prev = node->Prev;
	}

	node->Prev = node->Next = nullptr;
}
