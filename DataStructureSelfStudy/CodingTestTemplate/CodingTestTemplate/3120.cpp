#include <iostream>
#include <vector>
#include <queue>

using namespace std;



void dfs(vector<int>&dgree,int start,int end)
{
	queue<int> q;
	vector<int> remote ={1,-1,5,-5,10,-10};
	q.push(start);
	dgree[start] = 0;
	while (!q.empty())
	{
		int now = q.front();
		for (int temp : remote)
		{
			if(now+temp>=0&&now+temp<=40)
			{
				if(dgree[now+temp]>dgree[now]+1)
				{
					dgree[now+temp] = dgree[now] + 1;
					if(now+temp == end)
						return;
					q.push(now+temp);
				}
			}
		}
		q.pop();
	}
}


int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> dgree(41,INT32_MAX);

	dfs(dgree,n,m);
	cout<<dgree[m];
}