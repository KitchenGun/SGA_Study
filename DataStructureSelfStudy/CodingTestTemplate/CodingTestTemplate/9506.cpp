#include <iostream>
#include <vector>
using namespace std;

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)
			return 0;

		vector<int> v;
		v.push_back(1);
		for (int i = 2; i <= n / 2; i++)
		{
			if (n % i == 0)
				v.push_back(i);
		}
		int result = 0;
		for (int i : v)
		{
			result += i;
		}
		if (result == n)
		{
			cout << n << " = 1";
			for (int i : v)
			{
				if(i!=1)
					cout << " + " << i;
			}
			cout << endl;
		}
		else
		{
			cout << n << " is NOT perfect." << endl;
		}
	}
}
