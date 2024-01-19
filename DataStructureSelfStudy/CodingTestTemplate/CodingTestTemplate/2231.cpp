#include <iostream>
#include <string>
using namespace std;	

int find_dn(int n)
{
	int dn = n;
	while (n > 0) 
	{
		dn = dn + n % 10;
		n = n / 10;
	}
	return dn;
}

int main()
{
	int N;
	cin>>N;

	// 2. N 이하 모든 수의 분해합을 계산 및 비교한다.
	for (int i = 1; i <= N; i++) 
	{
		if (find_dn(i) == N) 
		{
			cout<<i;
			break;
		}
		if (i == N)
			cout<<0;
	}
}