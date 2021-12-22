#pragma once


template<typename T> class Tree
{

public:
	struct  Node;
	
public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->LeftChild == nullptr)
		{
			parent->LeftChild = child;
		}
		else
		{
			Node* node = parent->LeftChild;

			while (node->RightSibiling !=nullptr)
			{
				node = node->RightSibiling;
			}
			node->RightSibiling = child;
		}
	}

	void Print(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
		{
			printf("-");
		}
		std::cout << node->Data<<std::endl;
		
		if (node->LeftChild != nullptr)
		{
			Print(node->LeftChild, depth + 1);
		}
		if (node->RightSibiling != nullptr)
		{
			Print(node->RightSibiling, depth);
		}
	}

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->RightSibiling = node->LeftChild = nullptr;
		return node;
	}

	static void DestroyNode(Node* node)
	{
		delete node;
		node = nullptr;
	}

	void AddSibiling(Node* )
	{

	}

	
public:
	struct Node
	{
		T Data;
		Node* LeftChild;
		Node* RightSibiling;
	};

public:

};