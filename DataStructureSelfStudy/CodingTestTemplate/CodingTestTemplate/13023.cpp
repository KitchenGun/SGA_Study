#include <iostream>

#include <vector>

using namespace std;

bool ans=false;

void dfs(int start,int count,vector<vector<int>>&arr,vector<bool>& visit)
{
	if (count == 4)
	{
		ans=true;
		return;
	}
	
	for (int j = 0; j < arr[start].size(); j++) 
	{
		int nxt = arr[start][j];
		if (visit[nxt]) 
			continue;
		visit[nxt] = 1;
		dfs(nxt,count+1, arr, visit);
		visit[nxt] = 0;
	}
}


int main()
{
	int n,m;
	vector<vector<int>> arr;
	vector<bool> visit; 

	cin>>n>>m;

	arr.assign(n,vector<int>(0,0));
	visit.assign(n,false);

	for (int i = 0; i < m; i++)
	{
		int a,b;

		cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i,0,arr,visit);
		visit.assign(n, false);
		if(ans)
			break;
	}
	cout<<ans;
}
