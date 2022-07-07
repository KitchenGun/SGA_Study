#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isWall(int y,int x,int Ysize,int Xsize)
{
	if((y>=0&&y<Ysize)&&(x>=0&&x<Xsize))
		return false;
	else
		return true;
}


void bfs(vector<vector<int>> &map, vector<vector<bool>> &visit, int y,int x)
{
	queue<pair<int,int>> q;
	pair<int,int> pos;
	vector<int> dir = {0,-1,1};
	pos = {y,x};
	q.push(pos);
	visit[y][x] =true;

	while (!q.empty())
	{
		pos = q.front();
		visit[pos.first][pos.second]=true;
		//find all direction
		for (int i = 0; i < (int)dir.size(); i++)
		{
			for (int j = 0; j < (int)dir.size(); j++)
			{
				if (!(dir[i] == 0 && dir[j] == 0))
				{
					if (!isWall(pos.first + dir[i], pos.second + dir[j], map.size(), map[0].size()))//y+1
					{
						if (map[pos.first + dir[i]][pos.second + dir[j]]&&!visit[pos.first + dir[i]][pos.second + dir[j]])
						{
							q.push({ pos.first + dir[i] ,pos.second + dir[j] });
							visit[pos.first + dir[i]][pos.second + dir[j]] = true;
						}
					}
				}
			}
		}
		q.pop();
	}
}


int main()
{
	int h=1,w=1;
	while (h != 0 && w != 0)
	{
		//입력
		vector<vector<int>> map;
		vector<vector<bool>> visit;
		int result=0;
		cin >> w >> h;
		if(w==0&&h==0)
			continue;
		//초기화
		map.assign(h,vector<int>(w));
		visit.assign(h, vector<bool>(w));
		//좌표 입력
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int info;
				cin>>info;
				map[i][j] = info;
			}
		}
		//탐색
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					bfs(map,visit,i,j);
					result++;
				}
			}
		}
		cout<<result<<endl;
	}
}