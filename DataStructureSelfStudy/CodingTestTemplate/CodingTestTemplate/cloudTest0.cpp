#include <iostream>
#include <string>
using namespace std;
int main() {
	int input;
	int result = 0;
	cin >> input;

	string temp;

	for (int i = 1; i < input; i++)
	{
		temp = to_string(i);
		int pos = 0;
		for (int j = 0; j < temp.length(); j++)
		{
			if(temp[j]=='3'|| temp[j] == '6'|| temp[j] == '9')
				result++;
		}
	}

	cout << result;


	return 0;
}