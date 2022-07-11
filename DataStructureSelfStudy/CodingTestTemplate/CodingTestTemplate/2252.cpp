#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;

	cin>>n>>m;

	vector<vector<int>> graph(n,vector<int>(m,-1));
	vector<bool> visit;
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}


}