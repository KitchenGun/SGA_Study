#include <iostream>
#include "Timer.h"
using namespace std;

void InsertSort(int* data, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (data[i - 1] <= data[i])
			continue;
		
		int value = data[i];
		
		for (int j = 0; j < i; j++)
		{
			if (data[j] > value)
			{
				memmove(&data[j + 1], &data[j], sizeof(data[0]) * (i - j));
				data[j] = value;
				break;
			}
		}
	}
}

int main()
{
	Timer timer;
	int dataSet[] = { 5,1,6,4,2,3 };
	int length = sizeof(dataSet) / sizeof(dataSet[0]);

	for (int i = 0; i < length; i++)
	{
		cout << dataSet[i];
	}
	cout << endl;
	timer.Start();
	InsertSort(dataSet, length);
	timer.End();

	for (int i = 0; i < length; i++)
	{
		cout << dataSet[i];
	}
}