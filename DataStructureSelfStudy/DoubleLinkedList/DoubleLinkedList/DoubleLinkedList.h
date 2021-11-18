#pragma once

struct Node
{
	int Data;
	Node* Prev;
	Node* Next;
};


class DLL
{
public:
	Node* Create(int data);
	void Destroy(Node* node);
	void Push(Node* node);
	void Insert(Node* Current,Node* node);
	void HeadInsert(Node* node);
	void Remove(Node* node);
	Node* GetNode(int location);
	int GetNodeCount();

	Node* GetHead() { return Head; }
private:
	Node* Head=nullptr;

};