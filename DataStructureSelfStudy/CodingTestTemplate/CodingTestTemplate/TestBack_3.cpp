#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	int result = 0;
	vector<int> Array;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		Array.push_back(temp);
	}

	sort(Array.begin(), Array.end());
	int temp=0;
	for (int i = 0; i < n; i++)
	{
		temp += Array[i];
		result += temp;
	}
	cout << result;
}