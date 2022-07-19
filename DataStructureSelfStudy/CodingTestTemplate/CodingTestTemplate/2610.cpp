#include <iostream>
#include <queue>
#include <vector>

using namespace std;


bool iswall(pair<int, int> pos)//���浹 Ȯ��
{
	if((0<=pos.first&&pos.first<10)&&(0<=pos.second&&pos.second<10))
		return false;
	else
		return true;
}

void bfs(vector<vector<char>>& map, pair<int, int>start)
{//bfs Ž���� ���ؼ� ��ĥ�� �κ� �ľ�
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
			if (!iswall(nextpos))//���浹 Ȯ��
			{
				if (map[nextpos.first][nextpos.second]=='_')//��ĥ�� ������ �κ����� Ȯ��
				{
					q.push(nextpos);
					map[nextpos.first][nextpos.second] = '*';
				}
			}
		}
		q.pop();//Ž���� �κ� ť���� pop
	}
}



int main()
{

	vector<vector<char>> map(10,vector<char>(10));
	//�� �Է�
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{	
			cin>>map[i][j];
		}
	}

	pair<int,int> pos;
	//��ǥ �Է�
	cin>>pos.second>>pos.first;

	//��ǥ�� ��ĥ�� �����ϸ� ��ĥ
	if(map[pos.first][pos.second]!='*')
		bfs(map,pos);
	//���
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}

}