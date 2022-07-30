#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;

	vector<int> arr(n,0);

	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		arr[a]++;
	}

	
	for (int i = 0; i < n; i++)
	{
		bool isDetail = true;
		for (int j = 0; j < n; j++)
		{
			if (i != j && arr[i] == arr[j])
			{
				isDetail = false;
			}
		}

		if (isDetail)
		{
			ans++;
		}
	}


	cout<<ans;
}