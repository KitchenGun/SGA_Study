#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int cityCount = 0;
	vector<long> Range,fuel;
	long long result=0;
	cin >> cityCount;

	for (int i = 0; i < cityCount-1; i++)
	{
		long temp = 0;
		cin >> temp;
		Range.push_back(temp);
	}
	int prevTemp = 0;
	for (int i = 0; i < cityCount; i++)
	{
		long temp = 0;
		cin >> temp;
		if (prevTemp != 0 && prevTemp < temp)
		{
			fuel.push_back(prevTemp);
			prevTemp = temp;
		}
		else
		{
			fuel.push_back(temp);
			prevTemp = temp;
		}
	}
	int tempFuel=0;
	for (int i = 0; i < cityCount-1; i++)
	{
		result += (long long)(fuel[i] * Range[i]);
	}
	cout << result;
}