#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a=INT32_MAX,b = INT32_MAX;
	for (int i = 0; i < 3; i++)
	{
		int temp;
		cin>>temp;
		if(a>temp)
			a = temp;

	}
	for (int i = 0; i < 2; i++)
	{
		int temp;
		cin >> temp;
		if (b > temp)
			b = temp;
	}
	float result = (a + b) * 1.1f;
	cout<<fixed;
	cout.precision(1);
	cout<<result;
}