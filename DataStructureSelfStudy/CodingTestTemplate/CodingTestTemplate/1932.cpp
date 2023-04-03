#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<vector<int>>arr(505,vector<int>(505));

	vector<vector<int>>path(505, vector<int>(505));
	int count =0;

	cin>>count;


	for(int i=0;i<count;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int temp;
			cin>>temp;
			arr[i][j] = temp;
		}
	}

	path[0][0] = arr[0][0];

	for (int i = 1; i < count; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if(j==0)
				path[i][j] = path[i-1][j] + arr[i][j];
			else if(j==i)
			{
				path[i][j] = path[i - 1][j -1] + arr[i][j];
			}
			else
			{
				path[i][j] = max(path[i - 1][j-1] + arr[i][j], path[i - 1][j] + arr[i][j]);
			}
		}
	}

	sort(path[count-1].begin(),path[count-1].end());

	cout<<path[count-1].back();

}