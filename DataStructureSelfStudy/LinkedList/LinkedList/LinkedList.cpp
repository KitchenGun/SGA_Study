#include <iostream>
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

void LinkedList::Push(Node* node)
{
	if (list == nullptr)
	{
		list = node;
	}
	else
	{
		Node* tail = list;
		while (tail->Next!=nullptr)
		{
			tail = tail->Next;
		}
		tail->Next = node;
	}
}

void LinkedList::InsertHead(Node* node)
{

	if (list == nullptr)
	{
		list = node;
	}
	else
	{
		node->Next = list;
		list = node;
	}
}

void LinkedList::Remove(Node* Target)
{
	if (list == Target)
	{
		if (list->Next != nullptr)
		{
			list = Target->Next; 
		}
		else
			list = nullptr;
	}
	else
	{
		//while�Լ��� ������ �ݺ��� (���� ¥�� �ڵ�)
		//int TargetPrevIndex = GetNodeCount(Target)-1;
		//GetNode(TargetPrevIndex)->Next=Target->Next;

		//���Ǻ��� ������ �ڵ�
		Node* Current = list;
		while (Current!=nullptr&&Current->Next!=Target)
		{
			Current = Current->Next;
		}
		if (Current != nullptr)
		{
			if (Target->Next != nullptr)
			{
				Current->Next = Target->Next;
			}
			else
				Current->Next = nullptr;
		}
		else
			printf("\n�ش� ���� �������� ����\n");
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

int LinkedList::GetNodeCount()
{
	int count = 0;
	Node* current = list;

	while (current != NULL)
	{
		current = current->Next;

		count++;
	}

	return count;
}

