#include <iostream>

#include <vector>

using namespace std;

void dfs(int start,vector<vector<int>>&arr,vector<bool>&visit)
{
	
}

void bfs(int start, vector<vector<int>>& arr, vector<bool>& visit)
{

}


int main()
{
	vector<vector<int>> arr;
	vector<bool>visit;
	int n,m,start;
	cin>>n>>m>>start;

	arr.assign(n,vector<int>(0,0));
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	visit.assign(n,false);
	dfs(start,arr,visit);

	cout<<endl;

	visit.assign(n, false);
}