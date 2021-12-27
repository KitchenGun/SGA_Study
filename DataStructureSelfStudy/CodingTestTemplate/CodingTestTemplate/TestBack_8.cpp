#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t = 0;
	int n = 0;
	string s;


	cin >> t;

	for (int j = 0; j < t; j++)
	{
		cin >> n;
		cin >> s;
		for (char temp : s)
		{
			for (int i = 0; i < n; i++)
			{
				cout << (char)toupper(temp);
			}
		}
		cout << endl;
	}
}