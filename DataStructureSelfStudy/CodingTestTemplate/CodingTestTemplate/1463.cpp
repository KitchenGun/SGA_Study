#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int>dp(1000001,0);

	int n;

	cin>>n;
	
	for (int i = 2; i <= n; i++)//2부터 시작
	{
		dp[i] = dp[i-1]+1;//가장 큰값을 넣음
		if(i%2==0)
			dp[i]=min(dp[i],dp[i/2]+1);//2로 나눠질 경우 작은 값을 넣음
		else if(i%3 ==0)
			dp[i]=min(dp[i],dp[i/3]+1);//3으로 나눠질경우 작은 값을 넣음
	}
	cout<<dp[n];
}