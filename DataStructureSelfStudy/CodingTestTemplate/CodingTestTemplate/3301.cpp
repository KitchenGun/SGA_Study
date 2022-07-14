#include <iostream>
#include <vector>

using namespace std;

void cal(int &result, int n)
{
	vector<int> coins = { 10,50,100,500,1000,5000,10000,50000 };
	int t = coins.size()-1;
	while(n!=0)
	{
		if (n - coins[t] >= 0)
		{
			n-=coins[t];
			result++;
			if (n == 0)
				return;
		}
		else
		{
			t--;
		}
	}
}


int main()
{
	int n;
	int result = 0;

	cin>>n;

	cal(result,n);

	cout<<result;
	
}