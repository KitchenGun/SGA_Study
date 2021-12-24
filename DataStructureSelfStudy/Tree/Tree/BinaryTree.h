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
		Destroy(root);
	}

	void PreOrder(Node* node)
	{
		if (node == nullptr)
			return;
		std::cout << " " << node->Data;
		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	void InOrder(Node* node)
	{
		if (node == nullptr)
			return;
		InOrder(node->Left);
		std::cout << " " << node->Data;
		InOrder(node->Right);
	}

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