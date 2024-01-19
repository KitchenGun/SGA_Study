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

	// 2. N ���� ��� ���� �������� ��� �� ���Ѵ�.
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