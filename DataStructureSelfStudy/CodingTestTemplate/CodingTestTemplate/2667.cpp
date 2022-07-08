#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool isWall(int y, int x, int n)
{
	if ((y >= 0 && y < n) && (x >= 0 && x < n))
		return false;
	else
		return true;
}


int bfs(vector<vector<int>>&map,vector<vector<bool>>&visit,int y,int x)
{
	vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
	int count=0;
	queue<pair<int,int>> q;
	pair<int,int> pos = {y,x};
	q.push(pos);
	visit[pos.first][pos.second]=true;
	count++;
	while (!q.empty())
	{
		pos = q.front();
		for (int i = 0; i < (int)dir.size(); i++)
		{
			if (!isWall(pos.first + dir[i].first, pos.second + dir[i].second, (int)map.size()))
			{
				if(!visit[pos.first + dir[i].first][pos.second + dir[i].second]&&map[pos.first + dir[i].first][pos.second + dir[i].second])
				{	
					q.push({ pos.first + dir[i].first, pos.second + dir[i].second });
					visit[pos.first + dir[i].first][pos.second + dir[i].second] = true;
					count++;
				}
			}
		}
		q.pop();
	}

	return count;
}

int main()
{
	int n;
	cin>>n;

	vector<vector<int>> map(n,vector<int>(n,0));
	vector<vector<bool>> visit(n,vector<bool>(n,false));
	int count=0;
	vector<int> result;

	//input
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = temp[j]-'0';
		}
	}

	//find
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j]&&!visit[i][j])
			{
				result.push_back(bfs(map,visit,i,j));
				count++;
			}
		}
	}

	//print
	cout<<count<<endl;
	sort(result.begin(),result.end());
	for (int temp : result)
	{
		cout<<temp<<endl;
	}
}