#pragma once

template<typename T> class Tree
{
public:
	struct Node;
public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->LeftChild == NULL)//���� �ڽ��� ������ �������� ����
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
		//���� ���ø� �̶� � �ڷ����� ǥ�� �ϵ��� �ؾ������� char�� �ϰڽ��ϴ�.
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

	static Node* CreateNode(T data)//��� ����
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