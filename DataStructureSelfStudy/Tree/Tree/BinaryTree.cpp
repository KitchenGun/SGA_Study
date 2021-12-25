#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

void Expression(const char* postfix, Node** node)
{
	char* str = const_cast<char*>(postfix);//const cast�� ����Ͽ��� ������� ����
	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] = '\0';//��ū�� ������ ���ڸ� �ְ� ������ �ش� ���ڿ��� ��ū�� ����

	switch (token)
	{
	case '*': case '/': case'+':case'-'://�����ڰ� ���ð�� ��忡 �����ڸ� �ְ� 
	{
		*node = BT<char>::CreateNode(token);

		Expression(postfix, &(*node)->Right);//�������� �������� ��������� �о����� ���ڿ��� ��ū�� �ִ´�.
		Expression(postfix, &(*node)->Left);
		break;
	}
	default:
	{//����� ������� ��� ��忡 ����� �ְ� ����
		*node = BT<char>::CreateNode(token);
		break;
	}
	}
}

int Evaluate(Node* node)
{
	if (node == nullptr)//��尡 ���� ��� ������� 0���� ��ȯ
	{
		return 0;
	}
	switch (node->Data)
	{
	case '*': case '/': case'+':case'-'://�������� ��� ���ʰ� ������ ��带 ��������� Ž���ؼ� ����� ��ȯ�ϰ�
	{
		int left = Evaluate(node->Left);//int�� ��ȯ�� �ǵ��� ����
		int Right = Evaluate(node->Right);//int�� ��ȯ�� �ǵ��� ����
		//������ ������ ���� ���� �� ���� ���� �����ϰ� ��ȯ�Ѵ�.
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
	//������ �ڵ� ó�� ���ڸ��� �о�������� ����ϴ� �޸𸮸� ���̵��� �ڵ带 �����ߴ�.
	default://����� �����Ͱ� ����� ��� ����� ��ȯ�ϱ����ؼ� �̷��� �������.
		//int���� �����͸� ������ �ִ� ���� �ؿ� �ڽĳ�尡 ���ٰ� ������ �ϰ� ���۵Ǿ���.
		char* temp;					//5�ڸ������� ������ ����
		temp = '\0';
		//memset(temp, 0, sizeof(temp));	//���� �ڸ��� 0���� �ʱ�ȭ
		temp = &node->Data;//[0] = node->Data;			//����� �����ʹ�
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


	cout << "����" << endl;
	T.PreOrder(A);
	cout << endl;
	cout << "����" << endl;
	T.InOrder(A);
	cout << endl;
	cout << "����" << endl;
	T.PostOrder(A);
	cout << endl; 
	*/
	//���� Ʈ��
	//(3*4)-(1+4)
	string postfix = "34-";
	Node* root = nullptr;
	Expression(postfix.c_str(), &root);
	BT<char> tree;
	tree.Root(root);
	tree.InOrder(root); 
	//tree.PostOrder(root);
	cout<<" = " << Evaluate(root);
}