#pragma once

struct  Node
{
	char Data;
	Node* Left;
	Node* Right;
};
template<typename T>class BT
{
public:

public:
	BT()
	{

	}

	~BT()
	{
		Destroy(root);//재귀함수를 통해서 노드들을 전부 초기화
	}

	//전위
	void PreOrder(Node* node)
	{
		if (node == nullptr)//노드가 비어있지 않을때까지 탐색
			return;
		std::cout << " " << node->Data;
		PreOrder(node->Left);
		PreOrder(node->Right);
	}
	//중위
	void InOrder(Node* node)
	{
		if (node == nullptr)
			return;
		InOrder(node->Left);
		std::cout << " " << node->Data;
		InOrder(node->Right);
	}
	//후위
	void PostOrder(Node* node)
	{
		if (node == nullptr)
			return;
		PostOrder(node->Left);
		PostOrder(node->Right);
		std::cout << " " << node->Data;
	}

	void Root(Node* node) { root = node; }

private:
	void Destroy(Node* node)
	{
		if (node == nullptr)
			return;
		Destroy(node->Left);
		Destroy(node->Right);

		DestroyNode(node);
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Right = node->Left = nullptr;
		return node;
	}

	static void DestroyNode(Node* node)
	{
		delete node;
		node = nullptr;
	}

private:
	Node* root;

};