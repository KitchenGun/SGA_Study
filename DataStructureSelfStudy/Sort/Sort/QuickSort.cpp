#include <iostream>
#include <Windows.h>
#include "Timer.h"
using namespace std;

void ReadData(int* datas)
{
	FILE* file;
	fopen_s(&file, "RandData.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d", &datas[i]);
	}
	fclose(file);
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int* datas, int left, int right)
{
	int first = left;
	int pivot = datas[first];

	left++;
	while (left <= right)//while문 left right 서로 교차하기 전까지 탐색
	{
		while (datas[left] <= pivot && left < right)//data[left] 값이 pivot보다 작거나 같아야하고 left가 right 보다 작으면 계속 left증가하면서 탐색
			left++;

		while (datas[right] > pivot && left <= right)
			right--;

		if (left < right)
			Swap(&datas[left], &datas[right]);
		else
			break;
	}

	Swap(&datas[first], &datas[right]);

	return right;
}

void QSort(int* datas, int left, int right)
{
	//left가 right보다 작다면 분활 된거임
	if (left < right)
	{
		int index = Partition(datas, left, right);//파티션으로 구한 index를 기준으로 좌우로 분활해서 qsort로 재귀를 탄다

		QSort(datas, left, index - 1);
		QSort(datas, index + 1, right);
	}
}

int main()
{
	int datas[USHRT_MAX];
	ReadData(datas);
	Timer timer;
	timer.Start();
	{
		QSort(datas, 0, USHRT_MAX-1);
	}
	cout << timer.End()<<endl;

	for (int i=0;i<10;i++)
	{
		cout << datas[i] <<endl;
	}
}