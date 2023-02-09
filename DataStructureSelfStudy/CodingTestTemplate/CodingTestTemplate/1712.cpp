#include <iostream>
using namespace std;

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;

	if (b >= c)
	{
		cout << -1;
		return 0;
	}

	long long result = a / (c - b) + 1;


	cout << result;
	return 0;
}