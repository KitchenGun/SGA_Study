#include <iostream>
using namespace std;
int num[10] = { 1,5,9,10,4,7,3,8,2,6 };
int numCount = 10;

void quickSort(int *data, int start, int end)
{
	if (start >= end)
	{//���Ұ� 1���� ��� 
		return;
	}
	int key = start;//Ű�� ù��° ����
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)//������������ �ݺ�
	{

		while (data[i] <= data[key] && i <= end) //Ű������ ū���� ������ ����
		{
			i++;
		}
		while (data[j] >= data[key] && j > start)//Ű ������ ���� ���� ������ ����//������ �Ѿ�� �ʵ���
		{
			j--;
		}

		if (i > j)//���� ������ ���¶�� Ű���� ��ü
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else//�������� �ʾҴٸ� i�� j�� ��ü
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