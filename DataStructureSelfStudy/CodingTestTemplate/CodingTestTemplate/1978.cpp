#include<iostream>
#include <cmath>
using namespace std;


bool func(int num)
{
	if(num<2)
		return false;
	else
	{
		for (int i = 2; i < num; i++)
		{
			if(num%i==0)
				return false;
		}
	}
	return true;
}


int main()
{
	int n;
	int count=0;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		if(func(temp))
			count++;
	}
	cout<<count;
}