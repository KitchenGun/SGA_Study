#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//입력
	int count;
	cin>>count;

	vector<int> array;

	for(int i=0;i<count;i++)
	{
		int temp;
		cin>>temp;
		array.push_back(temp);
	}

	int SortCount;

	cin>>SortCount;

	//정렬
	
	for (int i = 0; i < count; i++)
	{
		int max = array[i];
		int maxi = i;
		for (int j = i + 1; j < count; j++)
		{
			if (SortCount - (j - i) >= 0)
			{
				if (max < array[j])
				{
					max = array[j];
					maxi = j;
				}
			}
		}
		for (int j = maxi; j > i; j--)
			swap(array[j], array[j - 1]);
		SortCount -= (maxi - i);
		if (SortCount <= 0)
			break;
	}
	

	//출력
	for(int temp : array)
	{
		cout<< temp<<" ";
	}
	
	return 0;
}