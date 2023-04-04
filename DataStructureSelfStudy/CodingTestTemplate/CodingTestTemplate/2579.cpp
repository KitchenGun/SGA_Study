#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	vector<int> dp;
	int count;
	cin >> count;

	dp.assign(count, 0);

	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}



	int result = 0;
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[1] + arr[2], dp[0] + arr[2]);

	for (int i = 3; i < count; i++)
	{
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3] + arr[i - 1]);

	}

	cout << dp[count - 1];
}