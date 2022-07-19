#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>visit, int start)
{
	queue<int>q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int top = q.front();
		cout << top + 1 << endl;
		for (int i = 0; i < (int)graph[top].size(); i++)
		{
			if (!visit[graph[top][i]])
			{
				q.push(graph[top][i]);
				visit[graph[top][i]] = true;
			}
		}
		q.pop();
	}
}
//https://swblossom.tistory.com/84

int main()
{
	//input ������ ���� ����
	int n,m;
	cin>>n>>m;
	//input ���� ����
	vector<vector<int>> graph (n,vector<int>(0));
	vector<int> priority(n,0);
	vector<bool> visit (n,false);
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		priority[b]++;
		graph[a].push_back(b);
	}
	//���� ���� ����ؾ��ϴ� �� ã��
	int min = 700;
	int index = 0;
	for (int i = 0; i < priority.size(); i++)
	{
		if (min > priority[i])
		{
			index = i;
			min = priority[i];
		}
	}

	//Ž��
	bfs(graph,visit,index);
}

