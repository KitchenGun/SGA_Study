#include <iostream>
#include <vector>

using namespace std;

long long temp[101];

long long DP(long long val)
{
	if (val == 0)
		return 0;
	else if (val == 1)
		return 1;
	else if (val == 2)
		return 1;
	else if (val == 3)
		return 1;
	else if (temp[val] != 0)
		return temp[val];
	else
		return temp[val] = DP(val - 2) + DP(val - 3);
}

int main()
{
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << DP(num) << endl;
	}
}