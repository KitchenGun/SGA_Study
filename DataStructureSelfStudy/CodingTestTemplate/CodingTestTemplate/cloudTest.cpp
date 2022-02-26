#include <iostream>
using namespace std;
int main() {
	int start;
	int end;

	cin >> start >> end;


	bool IsFind = false;
	for (int i = start; i < end; i++)
	{
		int add = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
				add += j;
		}

		if (add == i)
		{
			IsFind = true;
		}

		if (IsFind)
		{
			cout << i << " ";
			IsFind = false;
		}
	}

	return 0;
}