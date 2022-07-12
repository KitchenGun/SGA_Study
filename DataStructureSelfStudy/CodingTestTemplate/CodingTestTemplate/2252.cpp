#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution(vector<vector<int>>& graph,vector<int> &visit)
{
	queue<int> q;

	for (int i = 1; i < graph.size(); i++)
	{
		if(visit[i]==0)
			q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout<<cur<<" ";
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int Next = graph[cur][i];
			visit[Next]--;

			if(visit[Next]==0)
				q.push(Next);
		}
	}
	cout<<endl;
}


int main()
{
	int n,m;

	cin>>n>>m;

	vector<vector<int>> graph(n+1,vector<int>(0));
	vector<int> visit(n+1,0);
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		visit[b]++;
		graph[a].push_back(b);
	}

	solution(graph,visit);

}