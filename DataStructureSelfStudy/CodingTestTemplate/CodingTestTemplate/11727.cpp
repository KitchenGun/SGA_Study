#include<iostream>
#include<vector>
#define conditional 10007
using namespace std;



vector<int>dparray(10000,-1);

int DP(int val)
{
	if(val==1)
		return 1;
	if(val == 2)
		return 3;
	if(dparray[val]!=-1)
		return dparray[val];
	else
		return dparray[val] = (DP(val-1)+2*DP(val-2))%conditional;
}

int main()
{
	int x;
	cin>>x;

	cout<<DP(x);
}