#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;

	cin>>count;

	vector<int>arr={25,10,5,1};
	

	for(int i=0;i<count;i++)
	{
		int money;
		cin>>money;
		int idx =0;
		vector<int> result(4, 0);

		while(money!=0)
		{
			if(money - arr[idx]>=0)
			{
				money -= arr[idx];
				result[idx]++;
			}
			else
			{
				idx++;
			}
		}


		for(int temp:result)
		{
			cout<<temp<<" ";
		}
		cout<<endl;
	}
}