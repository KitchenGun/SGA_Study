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
		//시작 , 끝 ,비교 함수
		std::sort(datas, datas + USHRT_MAX, Compare);
	}
	printf("소요 시간 : %f\n", timer.End());

	for (int i = 0; i < 50; i++)
		printf("%d ", datas[i]);
}