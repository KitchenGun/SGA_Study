#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;


int func(int num)
{
	for (int i = 4; i <= num; i++)
	{
		if (dp[i][1] == 0)
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		if (dp[i][2] == 0)
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		if (dp[i][3] == 0)
			dp[i][3] = (dp[i - 3][2] + dp[i - 3][1]) % 1000000009;
	}

	return (dp[num][1] + dp[num][2] + dp[num][3]) % 1000000009;
}


int main()
{
	dp.assign(100001, vector<long long>(4, 0));

	dp[1][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;



	int n;
	cin >> n;

	while (n--)
	{
		int temp;
		cin >> temp;

		cout << func(temp) << endl;
	}

}