#include <iostream>
using namespace std;

void Minus(int &temp,int &i)
{
	if (temp > i)
	{
		temp -= i;
		i++;
		Minus(temp, i);
	}
}


int main()
{
	int n = 0;
	cin >> n;

	int i = 1;
	Minus(n, i);


	if (i % 2 != 0)
	{
		cout << i - (n - 1) << "/" << n;
	}
	else
	{
		cout << n << "/" << i-(n-1);
	}
}