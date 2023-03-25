#include <iostream>
using namespace std;

int main()
{
	int count;

	cin>>count;

	int point =2;
	while(count>0)
	{
		count--;
		point =(point-1+point);
	}

	cout<<point*point;
}