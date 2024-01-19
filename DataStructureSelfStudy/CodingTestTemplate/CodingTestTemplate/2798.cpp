#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, max;
	cin >> n >> max;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	int result = 0;
	for (int a = 0; a < v.size() - 2; a++)
	{
		for (int b = a + 1; b < v.size() - 1; b++)
			for (int c = b + 1; c < v.size(); c++)
			{
				int temp = v[a] + v[b] + v[c];
				if (temp <= max && result < temp)
				{
					result = temp;
				}
			}
	}
	cout << result;
}