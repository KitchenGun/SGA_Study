#include<iostream>
#include<vector>
using namespace std;


vector<int> dp(1001,0);

int DP(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else
	{
		if(dp[n]==0)
			return dp[n] = (DP(n-1)+DP(n-2))%10007;
		else
			return dp[n];
	}
}

int main()
{
	int n;
	cin>>n;

	cout<<DP(n);
}