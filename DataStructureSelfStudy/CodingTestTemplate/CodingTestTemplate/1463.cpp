#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int>dp(1000001,0);

	int n;

	cin>>n;
	
	for (int i = 2; i <= n; i++)//2���� ����
	{
		dp[i] = dp[i-1]+1;//���� ū���� ����
		if(i%2==0)
			dp[i]=min(dp[i],dp[i/2]+1);//2�� ������ ��� ���� ���� ����
		else if(i%3 ==0)
			dp[i]=min(dp[i],dp[i/3]+1);//3���� ��������� ���� ���� ����
	}
	cout<<dp[n];
}