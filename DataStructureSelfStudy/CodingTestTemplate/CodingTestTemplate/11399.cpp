#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int count;

	cin>>count;

	vector<int> arr;
	

	for(int i =0;i<count;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

	sort(arr.begin(),arr.end());

	int curTime=0;
	int result=0;
	for(int &i:arr)
	{
		curTime+=i;
		result += curTime;
	}
	curTime = 0;



	cout<<result;
}