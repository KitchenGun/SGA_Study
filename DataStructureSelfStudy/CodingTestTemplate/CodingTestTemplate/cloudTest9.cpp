#include <iostream>
#include <string>
using namespace std;
int main() {
	int start;
	int end;

	cin >> start >> end;

	int result=0;
	for (int i = start; i <= end; i++)
	{
		string stemp = to_string(i);
		int temp = stemp[0] - '0';
		for (int j = 1; j < stemp.length(); j++)
		{
			temp *= stemp[j] - '0';
		}
		result += temp;
	}

	cout << result;

	return 0;
}