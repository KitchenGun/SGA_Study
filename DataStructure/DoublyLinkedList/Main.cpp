#include<stdio.h>
 
struct Node
{
	Node* Prev;
	int Data;
	Node* Next;
};

Node* Create(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->Prev = node->Next = NULL;
	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

void Push(Node** head, Node* node)
{
	if ((*head) == NULL)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = *head;
		while (tail->Next!=NULL)
		{
			tail = tail->Next;
		}
		tail->Next = node;
		node->Prev = tail;
	}
}

void Insert(Node* current, Node* node)
{
	node->Next = current->Next;
	node->Prev = current;

	if (current->Next !=NULL)
	{
		current->Next->Prev = node;
	}
	current->Next = node;
}

void InsertHead(Node** head, Node* node)
{
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		node->Next = *head;
		*head = node;
	}
}

void Remove(Node** head, Node* remove)
{
	if (*head==remove)
	{
		*head = remove->Next;
		if (*head != NULL)
		{
			(*head)->Prev = NULL;
		}
	}
	else
	{
		Node* current = remove;

		remove->Prev->Next = current->Next;
		if (remove->Next != NULL)
		{
			remove->Next->Prev = current->Prev;
		}
	}
	remove->Prev = NULL;
	remove->Next = NULL;
}