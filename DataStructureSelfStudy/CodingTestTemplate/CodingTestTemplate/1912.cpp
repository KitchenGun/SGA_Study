#include <iostream>

using namespace std;


int fac(int n,int val)
{
	if(n!=0)
	{	
		val *= n;
		val = fac(n-1,val);
	}
	return val;
}


int main()
{
	int answer =0;
	int a;
	cin>>a;

	answer = fac(a,1);
	cout<<answer;
}