#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isWall(int y, int x, int n)
{
	if ((y >= 0 && y < n) && (x >= 0 && x < n))
		return false;
	else
		return true;
}

void bfs(vector<vector<int>>& map, vector<vector<int>>& count, pair<int, int> start, pair<int, int> end)
{
	vector<pair<int, int>> dir = { { -2,-1}, {-2,1}, {0,-2},{0, 2}, {2,-1}, {2,1} };
	queue<pair<int, int>> q;
	q.push(start);
	count[start.first][start.second] = 0;

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < (int)dir.size(); i++)
		{

			if (!isWall(pos.first + dir[i].first, pos.second + dir[i].second, (int)map.size()))
			{
				if (count[pos.first + dir[i].first][pos.second + dir[i].second] == -1)
				{
					q.push({ pos.first + dir[i].first,pos.second + dir[i].second });
					count[pos.first + dir[i].first][pos.second + dir[i].second] = count[pos.first][pos.second] + 1;
				}
			}
			if (end == pair<int, int>{pos.first + dir[i].first, pos.second + dir[i].second})
			{
				return;
			}
		}
	}


}


int main()
{
	int n;
	pair<int, int> startPos;
	pair<int, int> endPos;
	cin >> n;
	cin >> startPos.first >> startPos.second;
	cin >> endPos.first >> endPos.second;
	n+=1;
	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<vector<int>> count(n, vector<int>(n, -1));

	
	bfs(map, count, startPos, endPos);

	cout << count[endPos.first][endPos.second];
}