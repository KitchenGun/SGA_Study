#include <iostream>
using namespace std;
int num[10] = { 1,5,9,10,4,7,3,8,2,6 };
int numCount = 10;

void quickSort(int *data, int start, int end)
{
	if (start >= end)
	{//원소가 1개인 경우 
		return;
	}
	int key = start;//키는 첫번째 원소
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)//엇갈릴때까지 반복
	{

		while (data[i] <= data[key] && i <= end) //키값보다 큰값을 만날때 까지
		{
			i++;
		}
		while (data[j] >= data[key] && j > start)//키 값보다 작은 값을 만날때 까지//범위를 넘어가지 않도록
		{
			j--;
		}

		if (i > j)//연재 엇갈린 상태라면 키값과 교체
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else//엇갈리지 않았다면 i와 j를 교체
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);

}

int main()
{
	quickSort(num, 0, numCount - 1);
	for (int i = 0; i < 10; ++i)
	{
		cout << " " << num[i];
	}
}