#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

void Expression(const char* postfix, Node** node)
{
	char* str = const_cast<char*>(postfix);//const cast를 사용하여서 상수성을 제거
	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] = '\0';//토큰에 마지막 문자를 넣고 원본의 해당 문자열의 토큰을 지움

	switch (token)
	{
	case '*': case '/': case'+':case'-'://연산자가 나올경우 노드에 연산자를 넣고 
	{
		*node = BT<char>::CreateNode(token);

		Expression(postfix, &(*node)->Right);//우측부터 좌측으로 재귀적으로 읽어지는 문자열의 토큰을 넣는다.
		Expression(postfix, &(*node)->Left);
		break;
	}
	default:
	{//상수가 들어있을 경우 노드에 상수를 넣고 종료
		*node = BT<char>::CreateNode(token);
		break;
	}
	}
}

int Evaluate(Node* node)
{
	if (node == nullptr)//노드가 없을 경우 결과값을 0으로 반환
	{
		return 0;
	}
	switch (node->Data)
	{
	case '*': case '/': case'+':case'-'://연산자의 경우 왼쪽과 오른쪽 노드를 재귀적으로 탐색해서 결과를 반환하고
	{
		int left = Evaluate(node->Left);//int로 반환이 되도록 만듬
		int Right = Evaluate(node->Right);//int로 반환이 되도록 만듬
		//연산자 종류에 따라서 좌측 값 우측 값을 연산하고 반환한다.
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
	//기존의 코드 처럼 한자리만 읽어들이지만 사용하는 메모리를 줄이도록 코드를 수정했다.
	default://노드의 데이터가 상수일 경우 상수로 반환하기위해서 이렇게 만들었다.
		//int형의 데이터를 가지고 있는 노드는 밑에 자식노드가 없다고 가정을 하고 제작되었다.
		char* temp;					//5자리까지의 공간을 만듬
		temp = '\0';
		//memset(temp, 0, sizeof(temp));	//만든 자리를 0으로 초기화
		temp = &node->Data;//[0] = node->Data;			//노드의 데이터는
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
	string postfix = "34-";
	Node* root = nullptr;
	Expression(postfix.c_str(), &root);
	BT<char> tree;
	tree.Root(root);
	tree.InOrder(root); 
	//tree.PostOrder(root);
	cout<<" = " << Evaluate(root);
}