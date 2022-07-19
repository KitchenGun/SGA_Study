#include <iostream>
#include <queue>
#include <vector>

using namespace std;


bool iswall(pair<int, int> pos)//벽충돌 확인
{
	if((0<=pos.first&&pos.first<10)&&(0<=pos.second&&pos.second<10))
		return false;
	else
		return true;
}

void bfs(vector<vector<char>>& map, pair<int, int>start)
{//bfs 탐색을 통해서 색칠할 부분 파악
	vector<pair<int,int>> dir = { {0,1},{0,-1},{1,0},{-1,0}};

	queue<pair<int,int>> q;
	q.push(start);
	map[start.first][start.second] = '*';

	while (!q.empty())
	{
		pair<int,int>pos = q.front();
		for (int i = 0; i < (int)dir.size(); i++)
		{
			pair<int, int> nextpos = {pos.first + dir[i].first,pos.second + dir[i].second };
			if (!iswall(nextpos))//벽충돌 확인
			{
				if (map[nextpos.first][nextpos.second]=='_')//색칠이 가능한 부분인지 확인
				{
					q.push(nextpos);
					map[nextpos.first][nextpos.second] = '*';
				}
			}
		}
		q.pop();//탐색한 부분 큐에서 pop
	}
}



int main()
{

	vector<vector<char>> map(10,vector<char>(10));
	//맵 입력
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{	
			cin>>map[i][j];
		}
	}

	pair<int,int> pos;
	//좌표 입력
	cin>>pos.second>>pos.first;

	//좌표가 색칠이 가능하면 색칠
	if(map[pos.first][pos.second]!='*')
		bfs(map,pos);
	//출력
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}

}