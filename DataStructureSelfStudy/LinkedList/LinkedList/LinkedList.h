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

//벡터 주소가 연속적이게 놓여짐
//리스트 노의 다음 포인터가 다음 노드