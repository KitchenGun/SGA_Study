#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> CoinTypes;
	int CoinCount = 0;
	int Money = 0;
	int resultCount=0;
	//ют╥б
	cin >> CoinCount;
	cin >> Money;

	CoinTypes.resize(CoinCount, 0);
	for (int i = 0; i < CoinCount; i++)
	{
		int temp = 0;
		cin >> temp;
		CoinTypes.push_back(temp);
	}

	sort(CoinTypes.begin(),CoinTypes.end());

	int index =CoinTypes.size()-1;
	while (Money != 0)
	{
		if (Money < 0)
		{
			Money+=CoinTypes[index];

			index--;
			resultCount--;
		}
		else if (Money - CoinTypes[index] == 0)
		{
			resultCount++;
			cout<<resultCount<<endl;
			break;
		}
		else
		{
			Money-=CoinTypes[index];
			resultCount++;
		}
	}

}