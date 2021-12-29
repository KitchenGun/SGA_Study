#include <iostream>
#include <vector>
#include "Timer.h"
using namespace std;

void BubbleSort(vector<int> &dataSet, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (dataSet[j] < dataSet[j + 1])
			{
				int temp = dataSet[j + 1];
				dataSet[j + 1] = dataSet[j];
				dataSet[j] = temp;
			}
		}

		for (int temp : dataSet)
		{
			cout << temp;
		}
		cout << endl;
	}
}

int main()
{
	Timer timer;
	vector<int> nlist = { 1,4,3,2,5 };
	for (int temp : nlist)
	{
		cout << temp;
	}
	cout << endl;
	timer.Start();
	BubbleSort(nlist, 5);
	cout << (float)timer.End() << endl;
	for (int temp : nlist)
	{
		cout << temp;
	}
}