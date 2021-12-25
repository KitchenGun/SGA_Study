#include <iostream>
#include <vector>
using namespace std;

void Func(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';	// 아까 구한 조건식.
	else {
		if (n / 3 == 0)	// num을 나눌 때 까지 나누다가 안나눠지면
			cout << '*';
		else
			Func(i, j, n / 3);
	}
}

int main()
{
	int n = 0;
	vector<vector<char>> Array;
	cin >> n;

	for (int i =0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			Func(i, j, n);
		}
		cout <<endl;
	}
}