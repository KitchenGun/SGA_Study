#include <iostream>
using namespace std;

int numCount = 8;
int sorted[8];//���� �迭�� �ݵ�� ���� ������ ����

void merge(int a[], int m, int middle, int n) 
{
	int i = m;
	int j = middle + 1;
	int k = m;
	//���� ���� ��� �迭�� ����
	while (i <= middle && j <= n)
	{
		if (a[i] < a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//���� ������ ����
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	//���ĵ� �迭�� ����
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}


void MergeSort(int a[], int m, int n)
{
	//ũ�Ⱑ 1���� ū ���
	if (m < n)
	{
		int middle = (m + n) / 2;
		MergeSort(a, m, middle);
		MergeSort(a,middle + 1, n);
		merge(a, m, middle, n);
	}


}

int main()
{
	int array[8] = { 7,6,5,8,3,5,9,1 };

	MergeSort(array, 0, numCount - 1);

	for (int temp : array)
	{
		cout << temp << " ";
	}
}