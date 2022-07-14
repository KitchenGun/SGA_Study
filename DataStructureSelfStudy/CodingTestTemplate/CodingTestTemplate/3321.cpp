#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int tcount;
	int dprize, tprize;
	int dkcal;
	vector<int> tkcal;
	cin >> tcount >> dprize >> tprize >> dkcal;
	for (int i = 0; i < tcount; i++)
	{
		int temp;
		cin >> temp;
		tkcal.push_back(temp);
	}
	sort(tkcal.begin(), tkcal.end());
	int totalprize = dprize;
	int totalkcal = dkcal;
	for (int i = tcount - 1; i > 0; i--)
	{
		int totalper = totalkcal / totalprize;
		if (totalper < tkcal[i] / tprize)
		{
			totalkcal += tkcal[i];
			totalprize += tprize;
		}
	}

	cout << totalkcal / totalprize;
}