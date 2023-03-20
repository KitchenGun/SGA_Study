#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int count;
	cin>>count;

	vector<pair<int,int>> arr;
	for(int i=0;i<count;i++)
	{
		pair<int,int> temp;
		cin>>temp.second>>temp.first;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());


	int result=0;
	int endtime = 0;

	for(int i =0;i<count;i++)
	{
		if(arr[i].second >= endtime)
		{
			result++;
			endtime = arr[i].first;
		}
	}
	

	cout<<result;

}