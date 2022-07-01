#include <iostream>
#include <vector>
using namespace std;

int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	return gcd(y,x%y);
}


int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int t;
		vector<int> arr;
		cin>>t;
		for (int i = 0; i < t; i++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}

		long long ans = 0;

		for (int i = 0; i < t; i++)
			for (int j = i + 1; j < t; j++)
				ans += gcd(arr[i], arr[j]);

		cout << ans << endl;
	}
}