#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int cal(int value, int count , int selectCoinIdx)
{
	if (value - coin[selectCoinIdx] == 0)
	{
		++count;
		return count;
	}
	else
	{
		if (value - coin[selectCoinIdx] > 0)
		{
			value-=coin[selectCoinIdx];
			count++;
		}
		else
		{
			selectCoinIdx--;
		}
		return cal(value,count,selectCoinIdx);
	}
}



int main()
{
	int n;
	int val;
	//input
	cin>>n>>val;
	coin.assign(n,0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		coin[i] = temp;
	}
	//cal
	cout<<cal(val,0,n-1);
}