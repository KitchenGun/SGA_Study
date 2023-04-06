#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count;
	cin>>count;

	vector<int>dp(count,0);
	vector<int>arr(count,0);
	for(int i=0;i<count;i++)
	{
		int temp;
		cin>>temp;
		arr[i]=temp;
	}

	dp[0] = arr[0];
	dp[1] = arr[1]+arr[0];
	dp[2] = max(max(arr[1] + arr[0],arr[2]+arr[1]),arr[0]+arr[2]);

	for(int i=3;i<count;i++)
	{
		dp[i] = max(max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]),dp[i-1]);
	}

	cout<<dp[count-1];
}