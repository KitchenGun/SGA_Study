#include<iostream>
#include<vector>
using namespace std;

long long func(int num)
{
	vector<vector<long long>> arr(101,vector<long long>(10,0));

	arr[1][0] =0;
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] =1;
	}

	for (int i = 2; i <= num; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(j==0)
				arr[i][j] = (arr[i - 1][j + 1]) % 1000000000;
			else if (j == 9)
				arr[i][j] = (arr[i - 1][j - 1]) % 1000000000;
			else
				arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1]) % 1000000000;
		}
	}

	long long result=0;

	for (auto t : arr[num])
	{
		result+=t;
	}

	return result % 1000000000;

}


int main()
{
	int n;
	cin>>n;
	cout<<func(n)<<endl;
}