#include <iostream>
using namespace std;

int main()
{
	int CoinCount = 0;
	int value = 0.0f;
	int Coin[10] = { 0 };
	int result = 0;
	//ют╥б
	cin >> CoinCount;
	cin >> value;
	for (int i = 0; i < CoinCount;i++)
	{
		cin >> Coin[i];
	}


	for (int i = CoinCount-1; i >= 0; i--)
	{
		if (value / Coin[i] > 0)
		{
			result += value / Coin[i];
			value=value % Coin[i];
		}
	}
	cout << result;
}