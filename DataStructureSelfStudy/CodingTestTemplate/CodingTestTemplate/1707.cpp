#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>&arr,vector<int>&info,int start,bool& isBP)
{
	queue<int> q;

	q.push(start);
	info[start] = 1;

	while(!q.empty())
	{
		int nowNode = q.front();

		for (int i = 0; i < arr[q.front()].size(); i++)
		{
			int temp =arr[nowNode][i];
			if (info[temp] == 0)
			{//해당 노드를 처음 마주하는 경우
				q.push(temp);
				if (info[nowNode] == 1)
				{
					info[temp] = 2;
				}
				else
				{
					info[temp] = 1;
				}
			}
			else if(info[temp]==info[nowNode])
			{
				isBP = false;
				return;
			}
		}
		q.pop();
	}

	isBP = true;

	return;
}



int main()
{
	int k;
	cin>>k;

	while (k--)
	{
		int v, e;
		cin>>v>>e;

		vector<vector<int>> arr(v+1,vector<int>(0));

		vector<int> info(v+1,0);

		//입력
		for (int i = 0; i < e; i++)
		{
			int a,b;
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		//정렬
		for (int i = 0; i < arr[i].size(); i++)
		{
			sort(arr[i].begin(), arr[i].end());
		}


		bool isBP = false;
		//탐색
		for (int i = 1; i < v+1; i++)
		{
			if(info[i]==0)
				bfs(arr,info,i,isBP);
			if(!isBP)
				break;
		}

		cout<<(isBP?"YES":"NO")<<endl;

	}
}