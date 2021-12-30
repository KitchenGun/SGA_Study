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
	while (left <= right)//while�� left right ���� �����ϱ� ������ Ž��
	{
		while (datas[left] <= pivot && left < right)//data[left] ���� pivot���� �۰ų� ���ƾ��ϰ� left�� right ���� ������ ��� left�����ϸ鼭 Ž��
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
	//left�� right���� �۴ٸ� ��Ȱ �Ȱ���
	if (left < right)
	{
		int index = Partition(datas, left, right);//��Ƽ������ ���� index�� �������� �¿�� ��Ȱ�ؼ� qsort�� ��͸� ź��

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