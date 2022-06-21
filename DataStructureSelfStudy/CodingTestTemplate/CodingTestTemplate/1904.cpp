#include <iostream>
#include <vector>

using namespace std;

int temp[1000001];

int DP(int val)
{
	if(val==1)
		return 1;
	else if(val ==2)
		return 2;
	else if(temp[val]!=0)
		return temp[val];
	else
		return temp[val]=(DP(val-1)+DP(val-2))%15746;
}

int main()
{
	int n;
	cin>>n;

	cout<<DP(n)<<endl;
}