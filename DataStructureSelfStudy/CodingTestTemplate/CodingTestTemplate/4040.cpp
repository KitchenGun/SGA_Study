#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<char>> &map,int start,int end)
{
	vector<int> room;
	for (int i = 0; i < map[start].size(); i++)
	{
		if (map[start][i] == 'O')//empty
		{
			room.push_back(i);
		}
	}
	int result=0;

	while (start < end)
	{
		int index =0;
		for (int j = 1; j <= end; j++)
		{
			if (map[start][j] == 'O')
			{
				for (int k = start + 1; k <= end; k++)
				{
					if (!map[k][j])
					{
						index = max(index,k-1);
						break;
					}

					if (k == end)
					{
						index =end;
					}
				}
			}
		}
		if (index == 0)
		{
			return -1;
		}
		start = index+1;
		result++;
	}
	return result;
	
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> map(n,vector<char>(m+1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char temp;
			cin>>temp;
			map[i][j] = temp;
		}
	}
	int start,end;
	cin>>start>>end;
	cout<<solution(map,start,end);
}