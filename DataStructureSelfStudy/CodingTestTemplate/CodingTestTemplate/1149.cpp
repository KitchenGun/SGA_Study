#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main()
{
	vector<vector<int>> map(1001,vector<int>(3,0));
	vector<vector<int>> dp(1001, vector<int>(3, 0));
	int n;
	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		int r,g,b;
		cin>>r>>g>>b;

		map[i][0] = r;
		map[i][1] = g;
		map[i][2] = b;
	}
	dp[0][0]= dp[0][1] = dp[0][2] = 0;
	map[0][0] = map[0][1] = map[0][2] = 0;

	for(int i= 1;i <= n;i++) 
	{ 
		dp[i][0] = min(dp[i- 1][1], dp[i - 1][2]) + map[i][0];
		dp[i][1] = min(dp[i- 1][0], dp[i - 1][2]) + map[i][1];
		dp[i][2] = min(dp[i- 1][0], dp[i - 1][1]) + map[i][2];
	}
	
	cout<< min(min(dp[n][0], dp[n][1]), dp[n][2])<<endl;

}