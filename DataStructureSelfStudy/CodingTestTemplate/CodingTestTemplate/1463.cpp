#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	

	int n;

	cin>>n;
	vector<int>dp(n+1, 0);
	dp[1] = 0;

	for (int i = 2; i <= n; i++)//2���� ����
	{
		dp[i] = dp[i - 1] + 1;//���� ū���� ����
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);//3���� ��������� ���� ���� ����
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);//2�� ������ ��� ���� ���� ����
		}

	}
	cout << dp[n]<<endl;

	return 0;
}