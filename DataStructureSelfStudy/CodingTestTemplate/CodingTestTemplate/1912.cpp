#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int count;

	cin>>count;

	vector<int> dp(count,0);

	int idx=0;

	cin>>dp[0];

	for(int i=1;i<count;i++)
	{
		cin>>dp[i];

		if (dp[i] < dp[i] + dp[i - 1])
		{
			dp[i] += dp[i - 1];
		}
		if(dp[idx]<dp[i])
		{
			idx=i;
		}
	}

	cout<<dp[idx];
}

