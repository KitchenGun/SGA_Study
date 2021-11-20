#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//그리디 알고리즘
	/*
	int n, k;
	int result=0;
	cin >> n >> k;

	while (true)
	{
		int target = (n / k) * k;
		result += (n - target);
		n = target;
		if (n < k)break;
		result++;
		n /= k;
		result += (n - 1);
		cout << result << endl;
	}
	*/

	/*
	string str;

	cin >> str;

	int result = str[0] - '0';
	for (int i = 1; i < str.size(); ++i)
	{
		int num = str[i] - '0';
		if (num <= 1 || result <= 1)
		{
			result += num;
		}
		else
		{
			result *= num;
		}
	}
	cout << result << endl;
	*/

	int n; 
	vector<int> arr;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	int result = 0;
	int cnt = 0;
	for (int i =0;i<n;++i)
	{
		cnt += 1;
		if (cnt >= arr[i])
		{
			result += 1;
			cnt = 0;
		}
	}
	cout << result << endl;
}