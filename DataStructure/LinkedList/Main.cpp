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

void insertHead(Node** head, Node* node)
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
	if (*head == remove)
	{
		*head = remove->Next;
	}
	else
	{
		Node* current = *head;
		while (current != NULL && current->Next != remove)
		{
			current = current->Next;
		}
		if (current->Next != NULL)
		{
			current->Next = remove->Next;
		}
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
	Node* temp = GetNode(list, 3);
	printf("list[%d] : %d\n", 3, temp->Data);
	printf("\n");

	Node* newNode = Create(-1);
	insertHead(&list, newNode);
	count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf("list[%d] : %d\n", i, current->Data);
	}
	printf("\n");

	Remove(&list, temp);
	count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* current = GetNode(list, i);

		printf("list[%d] : %d\n", i, current->Data);
	}
	printf("\n");
	return 0;
}
//vector 주소가 연속												  (변경이 없는경우 사용하는 것이 유리함 탐색에 용의 하지만 삽입 삭제가 느림)
//list 노드의 다음노드가 주소를 갖고있음(메모리영역이 연속이 아님)     (삽입 삭제가 빠름 탐색은 느림)