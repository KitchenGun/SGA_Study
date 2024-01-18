#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	long long N;
	int B;
	cin>>N;
	cin>>B;
	
	vector <int> v;
	
	int i=0;
	while (1)
	{
		v.push_back(N%B);
		N/=B;
		if(N==0) break;
	}
	
	reverse(v.begin(),v.end());

	for (int temp : v)
	{
		if (temp >= 10)
		{
			char c = temp-10+'A';
			cout<<c;
		}
		else
		{
			cout<<temp;
		}
	}

}