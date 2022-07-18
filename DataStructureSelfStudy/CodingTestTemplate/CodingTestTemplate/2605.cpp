#include <iostream>
#include <queue>
#include <vector>

using namespace std;



bool iswall(pair<int, int> pos)
{
	if ((0 <= pos.first && pos.first < 7) && (0 <= pos.second && pos.second < 7))
	{
		return false;
	}
	else
		return true;
}


bool bfs(vector<vector<int>>map, vector<vector<bool>>&visit, pair<int,int> start)
{
	vector<pair<int, int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
	queue<pair<int, int>> q;
	q.push({ start.first,start.second });
	visit[start.first][start.second] = true;
	int Count = 0;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		for (int i = 0; i < dir.size(); i++)
		{
			if (!iswall({ pos.first + dir[i].first,pos.second + dir[i].second }))
			{
				if (!visit[pos.first + dir[i].first][pos.second + dir[i].second] && map[start.first][start.second]==map[pos.first + dir[i].first][pos.second + dir[i].second])
				{
					visit[pos.first + dir[i].first][pos.second + dir[i].second] = true;
					q.push({ pos.first + dir[i].first,pos.second + dir[i].second });
					Count++;
				}
			}
		}
		q.pop();
	}
	if (Count >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	vector<vector<int>> map(7,vector<int>(7));
	int result =0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin>>map[i][j];
		}
	}
	vector<vector<bool>> visit(7, vector<bool>(7));

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(!visit[i][j])
			{
				if(bfs(map,visit,{i,j}))
					result++;
			}
		}
	}
	cout<<result;

}