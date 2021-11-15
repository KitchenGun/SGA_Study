#pragma once
struct Node
{
	int Data;
	Node* Next;
};


class LinkedList
{
public:
	Node* Create(int data);
	void Destroy(Node* Target);
	void Push(Node* node);
	void InsertHead(Node* node);
	void Remove(Node* Target);


	Node** GetList() { return &list; }
	Node* GetNode(int count);
	int GetNodeCount();
private:
	Node* list = nullptr;
};

//���� �ּҰ� �������̰� ������
//����Ʈ ���� ���� �����Ͱ� ���� ���