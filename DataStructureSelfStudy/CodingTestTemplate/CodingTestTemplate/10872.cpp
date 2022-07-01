#include<iostream>
using namespace std;


int fac(int num)
{
	if(num<=1)
		return 1;
	return num*fac(num-1);
}


int main()
{
	int n;
	cin>>n;

	cout<<fac(n);

}