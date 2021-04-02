#pragma once

template<typename T> class Tree
{
public:
	struct Node;
public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->LeftChild == NULL)//왼쪽 자식이 없으면 왼쪽으로 삽입
		{
			parent->LeftChild = child;
		}
		else
		{
			Node* node = parent->LeftChild;
			while (node->RightSibling != NULL)
				node = node->RightSibling;
			node->RightSibling = child;
		}
	}

	void PrintNode(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
		{
			printf("-");
		}
		//원래 템플릿 이라 어떤 자료형도 표현 하도록 해야하지만 char로 하겠습니다.
		printf("%c\n", node->Data);

		if (node->LeftChild != NULL)
		{
			PrintNode(node->LeftChild, depth + 1);
		}
		if (node->RightSibling != NULL)
		{
			PrintNode(node->RightSibling, depth);
		}
	}

	static Node* CreateNode(T data)//노드 생성
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = node->RightSibling = NULL;

		return node;
	}

	static void DestroyNode(Node* node)
	{
		delete node;
		node = NULL;
	}

public:
	struct Node
	{
		T Data;

		Node* LeftChild;
		Node* RightSibling;
	};
};