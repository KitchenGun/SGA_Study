#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Func(vector<int> &arr,int n, int key)
{
	int start =0;
	int end = n-1;
	int target = (start+end)/2;
	int count= 0;

	bool isend=false;
	while (end>start)
	{
		if (arr[target] == key)
		{

			if (target == 0)
			{
				isend = true;
			}
			else
			{
				if (arr[target - 1] == key && !isend)
				{
					if (target - 1 >= start)
						target -= 1;
				}
				else
					isend = true;
			}
			

			if(isend)
			{
				isend = true;
				count++;
				if (end > target)
					if (arr[target + 1] == key)
						target++;
					else
						return count;
				else
					return count;
			}
		}
		else if (arr[target] > key)
		{
			end = target-1;
			target = (start + end) / 2;
		}
		else
		{
			start = target + 1;
			target = (start + end) / 2;
		}
	}

	return count;
}



int main(void)
{
	int n;

	cin>>n;

	vector<int> CardArr;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		CardArr.push_back(temp);
	}

	sort(CardArr.begin(),CardArr.end());

	int m;
	
	cin>>m;

	vector<int> SearchArr;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;


		SearchArr.push_back(Func(CardArr,n,temp));
	}

	for (int i = 0; i < m; i++)
	{
		cout<<SearchArr[i]<<" ";
	}

}