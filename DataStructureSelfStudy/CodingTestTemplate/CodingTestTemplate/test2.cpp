#include <iostream>
#include<string>
#include <vector>
using namespace std;

int Cal(int numCount, string num)
{
	int answer = 0;


	for (int i = 0; i < numCount; i++)
	{
		answer += (num[i] - '0');
	}

	return answer;
}


void quickSort(int* data,int start,int end)
{
	if (start >= end)
	{
		return;
	}

	int key = start;
	int LCursor = start+1;
	int RCursor = end;
	int temp = 0;
	while (LCursor <= RCursor)
	{
		while (data[LCursor] >= data[key] && LCursor <= end)
		{
			LCursor++;
		}
		while (data[RCursor] <= data[key] && RCursor > start)
		{
			RCursor--;
		}
		
		if (LCursor > RCursor)
		{
			temp = data[RCursor];
			data[RCursor] = data[key];
			data[key] = temp;
		}
		else
		{
			temp = data[RCursor];
			data[RCursor] = data[LCursor];
			data[LCursor] = temp;
		}
	}

	quickSort(data, start, RCursor - 1);
	quickSort(data, RCursor+1, end);

}


int main()
{
	int Array[10] = { 5,2,3,1,4,2,3,5,1,7 };
	quickSort(Array, 0, 9);

	for (int temp : Array)
	{
		cout << temp;
	}
}