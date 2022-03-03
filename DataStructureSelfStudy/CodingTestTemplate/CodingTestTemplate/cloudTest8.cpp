#include <iostream>
#include <vector>
using namespace std;
int main() {
	int input;
	vector<int> array;
	cin >> input;
	double result = 0;
	for (int i = 0; i < input; i++)
	{
		int temp = 0;
		cin >> temp;
		array.push_back(temp);
		result += temp;
	}
	result /= input;

	int upper = 0;
	for (int i = 0; i < input; i++)
	{
		if (array[i] > result)
		{
			upper++;
		}
	}


	cout << fixed;
	cout.precision(1);
	cout << result << " " << upper;


	return 0;
}