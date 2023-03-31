#include <iostream>

using namespace std;

int warr[21][21][21];


int DP(int a, int b, int c)
{
	if(a<=0|| b <= 0 || c <= 0)//첫 조건
		return 1;
	else if(a > 20 || b > 20 || c > 20)//2번째 조건
		return DP(20,20,20);
	else if (warr[a][b][c] != 0)//3번째 조건
		return warr[a][b][c];
	else if (a < b && b < c)
		warr[a][b][c] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
	else
		warr[a][b][c] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);

	return warr[a][b][c];
}

int main()
{
	int a=0,b=0,c=0;

	while (1)
	{
		cin>>a>>b>>c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << DP(a, b, c) << endl;
	}
	return 0;
}