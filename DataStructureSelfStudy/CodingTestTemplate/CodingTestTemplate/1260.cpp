#include <iostream>
#include<queue>
#include<set>
#include <vector>

using namespace std;

void dfs(int start,vector<set<int>>&arr,vector<bool>&visit)
{
	visit[start] = true;
	cout<<start+1<<" ";

	for (set<int>::iterator it = arr[start].begin(); it != arr[start].end(); it++)
	{
		if (!visit[*it])
		{
			dfs(*it,arr,visit);
		}
	}
}

void bfs(int start, vector<set<int>>& arr, vector<bool>& visit)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int here =q.front();
		cout<<q.front()+1 << " ";
		q.pop();

		for (set<int>::iterator it = arr[here].begin();it != arr[here].end();it++)
		{
			if (!visit[*it])
			{
				q.push(*it);
				visit[*it]=true;
			}
		}
	}
}


int main()
{
	vector<set<int>> arr;
	vector<bool>visit;
	int n,m,start;
	cin>>n>>m>>start;

	arr.assign(n, set<int>{});
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		arr[a].insert(b);
		arr[b].insert(a);
	}

	visit.assign(n,false);
	dfs(start-1,arr,visit);
	cout<<endl;
	visit.assign(n, false);
	bfs(start-1,arr,visit);

}