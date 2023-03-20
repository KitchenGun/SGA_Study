#include <iostream>
#include  <vector>

using namespace std;

vector<int> coinArr;

int cal(int money)
{
	int result=0;
	for(int i =static_cast<int>(coinArr.size()-1);i>=0;i--)
	{
		while(money>=coinArr[i])
		{
			if(money - coinArr[i]>=0)
			{
				money -= coinArr[i];
				result++;
			}
		}
	}
	return result;
}

int main()
{
	int coinCount =0;
	int money =0;

	cin>>coinCount>>money;

	for(int i=0;i<coinCount;i++)
	{
		int temp;
		cin>>temp;
		coinArr.push_back(temp);
	}

	cout<<cal(money);
}