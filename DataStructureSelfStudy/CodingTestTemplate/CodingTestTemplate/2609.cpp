#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int c= a%b;
	while (c != 0)
	{
		a =b;
		b=c;
		c = a%b;
	}
	return b;
}

int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}



int main()
{
	int n;
	int a,b;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a>>b;
		cout<<lcm(a,b)<<endl;
	}
}