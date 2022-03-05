#include <iostream>
using namespace std;
int main()
{
	int input;
	cin >> input;

	int reVal = 1000 - input;
	int coin[4] = { 500,100,50,10 };
	int result[4] = { 0,0,0,0 };
	int curCoinidx = 0;
	while (reVal != 0)
	{
		for (int i = 1; reVal >= 0; i++)
		{
			reVal -= coin[curCoinidx];

			if (reVal < 0)
			{
				reVal += coin[curCoinidx];
				result[curCoinidx] = i - 1;
				break;
			}
			else 
			{
				result[curCoinidx]++;
			}
		}
		if (reVal == 0)
		{
			break;
		}
		else
			curCoinidx++;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}