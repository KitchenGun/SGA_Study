#include <stdio.h>

struct Node
{//c 스타일
	int Data;
	
	Node* Next;
};

Node* Create(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = NULL;

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
		Node* tail = (*head);
		while (tail->Next!=NULL)
		{
			tail = tail->Next;
		}
		tail->Next = node;
	}
}

Node* GetNode(Node* head, int location)//location 몇번째 데이터 찾아올지
{
	Node* current = head;
	while (current != NULL && --location>=0)
	{
		current = current->Next;
	}
	return current;
}

int GetNodeCount(Node* head)
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

int main()
{
	Node* list = NULL;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&list, node);

	}
	int count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf("list[%d] : %d\n", i, current->Data);
	}
	printf("\n");
	return 0;
}