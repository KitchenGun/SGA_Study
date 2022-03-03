#include <iostream>
#include <vector>
using namespace std;
int main() {
	int m, n;
	vector<pair<int, int>> Bomb;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '*')
			{
				pair<int, int> pos = { i,j };
				Bomb.push_back(pos);
			}
		}
	}

	int** result = new int* [m];


	for (int i = 0; i < m; i++)
	{
		result[i] = new int[n];
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j]=0;
		}
	}


	for (int i = 0; i < Bomb.size(); i++)
	{
		result[Bomb[i].second][Bomb[i].first] = -1;

		if (Bomb[i].second + 1 < m && result[Bomb[i].second + 1][Bomb[i].first] != -1)//x+1
		{
			result[Bomb[i].second + 1][Bomb[i].first]++;

			if (Bomb[i].first + 1 < n && result[Bomb[i].second + 1][Bomb[i].first + 1] != -1)//x+1 y+1
				result[Bomb[i].second + 1][Bomb[i].first + 1]++;
			if (Bomb[i].first - 1 >= 0 && result[Bomb[i].second + 1][Bomb[i].first - 1] != -1)//x+1 y-1
				result[Bomb[i].second + 1][Bomb[i].first - 1]++;
		}
		if (Bomb[i].first + 1 < n && result[Bomb[i].second][Bomb[i].first + 1] != -1)//y+1
		{
			result[Bomb[i].second][Bomb[i].first + 1]++;

			if (Bomb[i].second - 1 >= 0 && result[Bomb[i].second - 1][Bomb[i].first + 1] != -1)//x-1 y+1
				result[Bomb[i].second - 1][Bomb[i].first + 1]++;
		}

		if (Bomb[i].second - 1 >= 0 && result[Bomb[i].second - 1][Bomb[i].first] != -1)//x-1
		{
			result[Bomb[i].second - 1][Bomb[i].first]++;
			if (Bomb[i].first - 1 >= 0 && result[Bomb[i].second - 1][Bomb[i].first - 1] != -1)//x-1 y-1
				result[Bomb[i].second - 1][Bomb[i].first - 1]++;
		}
		if (Bomb[i].first - 1 >= 0 && result[Bomb[i].second][Bomb[i].first - 1] != -1)//y-1
			result[Bomb[i].second][Bomb[i].first - 1]++;

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (result[i][j] == -1)
				printf("*");
			else
				printf("%d", result[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}