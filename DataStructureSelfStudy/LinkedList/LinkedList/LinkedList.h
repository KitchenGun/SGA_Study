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
	void Push(Node** head,Node* node);

	Node** GetList() { return &list; }
	Node* GetNode(int count);
	int GetNodeCount(Node* Target);
private:
	Node* list = nullptr;
};