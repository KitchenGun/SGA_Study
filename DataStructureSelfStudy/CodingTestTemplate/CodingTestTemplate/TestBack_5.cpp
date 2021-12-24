#include <iostream>
using namespace std;

int Func(int n)
{
	if (n >= 2)
	{
		//stack overflow를 방지하기 위해서 변수를 만듬
		int a =	Func(n - 1) + Func(n - 2);
		return a;
	}
	else if (n == 1)
	{
		return 1;
	}

	return 0;
}

int main()
{
	int n = 0;
	cin >> n;
	cout<<Func(n);
}
