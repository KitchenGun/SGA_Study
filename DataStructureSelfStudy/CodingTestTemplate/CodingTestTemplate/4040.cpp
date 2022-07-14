#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> map(n,vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin>>temp;
			map[i][j] = temp;
		}
	}


}