#include "LinkedList.h"

Node* LinkedList::Create(int data)
{
	Node* node = new Node();
	node->Data = data;
	return node;
}

void LinkedList::Destroy(Node* Target)
{
	delete Target;
	Target = nullptr;
}

void LinkedList::Push(Node** head, Node* node)
{
	if (*head == nullptr)
	{
		*head = node;
	}
	else
	{
		Node* tail = *head;
		while (tail->Next!=nullptr)
		{
			tail = tail->Next;
		}
		tail->Next = node;
	}
}

Node* LinkedList::GetNode(int count)
{
	int NodeNum = 0;
	Node* head = list;
	while (NodeNum != count)
	{
		head =head->Next;
		++NodeNum;
	}
	return head;
}

int LinkedList::GetNodeCount(Node* Target)
{
	int count = 0;
	Node* head = list;

	while (head != Target)
	{
		if (head != Target)
		{
			head = head->Next;
			++count;
		}
	}

	return count;
}
