#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

void Expression(const char* postfix, Node** node)
{
	char* str = const_cast<char*>(postfix);
	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] = '\0';

	switch (token)
	{
	case '*': case '/': case'+':case'-':
	{
		*node = BT<char>::CreateNode(token);

		Expression(postfix, &(*node)->Right);
		Expression(postfix, &(*node)->Left);
		break;
	}
	default:
	{
		*node = BT<char>::CreateNode(token);
		break;
	}
	}
}

int Evaluate(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	switch (node->Data)
	{
	case '*': case '/': case'+':case'-':
	{
		int left = Evaluate(node->Left);
		int Right = Evaluate(node->Right);

		switch (node->Data)
		{
		case'+':
			return left + Right;
			break;
		case'-':
			return left - Right;
			break;
		case'*':
			return left * Right;
			break;
		case'/':
			return left / Right;
			break;
		default:
			break;
		}
		break;
	}
	default:
		char temp[4];
		memset(temp, 0, sizeof(temp));
		temp[0] = node->Data;
		return atoi(temp);
		break;
	}
	return 0;
}

int main()
{
	/*
	BT<char> T;

	Node* A = T.CreateNode('A');
	Node* B = T.CreateNode('B');
	Node* C = T.CreateNode('C');
	Node* D = T.CreateNode('D');
	Node* E = T.CreateNode('E');
	Node* F = T.CreateNode('F');
	Node* G = T.CreateNode('G');
	//		 A
	//	  B     E
	//  C   D F   G

	T.Root(A);
	A->Left = B;
	A->Right = E;

	B->Left=C;
	B->Right = D;

	E->Left = F;
	E->Right = G;


	cout << "전위" << endl;
	T.PreOrder(A);
	cout << endl;
	cout << "중위" << endl;
	T.InOrder(A);
	cout << endl;
	cout << "후위" << endl;
	T.PostOrder(A);
	cout << endl; 
	*/
	//수식 트리
	//(3*4)-(1+4)
	string postfix = "34*14+-";
	Node* root = nullptr;
	Expression(postfix.c_str(), &root);
	BT<char> tree;
	tree.Root(root);
	tree.InOrder(root); 
	//tree.PostOrder(root);
	cout<<" = " << Evaluate(root);
}