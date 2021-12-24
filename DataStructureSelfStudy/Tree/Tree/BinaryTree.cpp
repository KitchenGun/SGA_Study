#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
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
}