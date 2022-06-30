#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;

	a.append(b);
	c.append(d);

	cout<<stol(a)+stol(c);
}