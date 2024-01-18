#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a,b;
	cin>>a;
	if(a==0)
		return 0;
	cin>>b;
	vector<int> v;
	
	for(int i=1;i<=a;i++)
	{
		if (a % i == 0)
		{
			v.push_back(i);
		}
	}
	
	if(v.size()<b)
		cout<<0;
	else
	{
		cout<<v[b-1];
	}
	return 0;
}