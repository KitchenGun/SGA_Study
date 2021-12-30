#include <iostream>
#include <Windows.h>
#include <algorithm>
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

bool Compare(const int& val1, const int& val2)
{
	return val1 < val2;
}

int main()
{
	int datas[USHRT_MAX];
	ReadData(datas);

	Timer timer;
	timer.Start();
	{
		//���� , �� ,�� �Լ�
		std::sort(datas, datas + USHRT_MAX, Compare);
	}
	printf("�ҿ� �ð� : %f\n", timer.End());

	for (int i = 0; i < 50; i++)
		printf("%d ", datas[i]);
}