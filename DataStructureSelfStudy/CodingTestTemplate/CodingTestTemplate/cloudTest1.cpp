#include <iostream>
using namespace std;

int dataCal(int bill, int data)
{
	int cost;
	switch (bill)
	{
	case 29900:
		cost = bill;
		data -= 300;
		break;
	case 34900:
		cost = bill;
		data -= 1000;
		break;
	case 39900:
		cost = bill;
		data -= 2000;
		break;
	case 49900:
		cost = bill;
		data -= 6000;
		break;
	case 59900:
		cost = bill;
		data -= 11000;
		break;
	case 69900:
		cost = bill;
		break;
	}

	if(data<0)
		return cost;


	int excost=0;
	if (bill != 69900)
	{
		if (data >= 5000)
		{
			
			excost += min(180000, data * 20);
		}
		else
		{
			excost += min(25000, data * 20);
		}
	}

	return (cost + excost);

}

int main() {
	int curbill;
	int curdata;
	int curResult;
	cin >> curbill >> curdata;


	curResult = dataCal(curbill, curdata);

	int bestbill = curbill;
	int bestResult = curResult;
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			if (curbill != 29900)
			{
				int calResult= dataCal(29900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 29900;
					bestResult = calResult;
				}
			}
			break;
		case 1:
			if (curbill != 34900)
			{
				int calResult = dataCal(34900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 34900;
					bestResult = calResult;
				}
			}
			break;
		case 2:
			if (curbill != 39900)
			{
				int calResult = dataCal(39900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 39900;
					bestResult = calResult;
				}
			}
			break;
		case 3:
			if (curbill != 49900)
			{
				int calResult = dataCal(49900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 49900;
					bestResult = calResult;
				}
			}
			break;
		case 4:
			if (curbill != 59900)
			{
				int calResult = dataCal(59900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 59900;
					bestResult = calResult;
				}
			}
			break;
		case 5:
			if (curbill != 69900)
			{
				int calResult = dataCal(69900, curdata);
				if (bestResult > calResult)
				{
					bestbill = 69900;
					bestResult = calResult;
				}
			}
			break;
		}
	}


	cout << bestbill << " " << curResult << " " << bestResult;

	return 0;
}