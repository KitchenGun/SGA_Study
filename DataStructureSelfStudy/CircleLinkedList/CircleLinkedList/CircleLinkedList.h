#pragma once

struct  Node
{
	Node* Prev;
	int Data;
	Node* Next;
};

class CircleLinkedList
{
public:
	Node* Create(int data);
	void Destroy(Node* Target);
	void Push(Node* node);
	void Insert(Node* current, Node* node);
	void Remove(Node* node);

	Node* Head = nullptr;
};