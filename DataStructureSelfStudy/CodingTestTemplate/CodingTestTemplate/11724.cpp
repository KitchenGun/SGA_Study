#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int result;

void bfs(vector<vector<int>>&arr,vector<bool>&visit,int start)
{
	queue<int> q;

	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int nowNode = q.front();
		for (int i = 0; i < arr[nowNode].size(); i++)
		{
			if(!visit[arr[nowNode][i]])
			{
				q.push(arr[nowNode][i]);
				visit[arr[nowNode][i]]=true;
			}
		}
		q.pop();
	}
	result++;
}


int main()
{
	int n,m;
	result =0;
	cin>>n>>m;

	vector<vector<int>>arr;
	vector<bool> visit;
	arr.assign(n+1,vector<int>(0));
	visit.assign(n+1,false);

	for (int i = 0; i < m; i++)
	{
		int a,b;

		cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		sort(arr[i].begin(),arr[i].end());
	}
	
	for (int i = 1; i < n; i++)
	{
		if(!visit[i])
			bfs(arr, visit,i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
			result++;
	}

	cout<<result;
}