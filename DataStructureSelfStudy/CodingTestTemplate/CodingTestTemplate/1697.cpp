#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isWall(int n)
{
	if(0 <= n && n<= 100000)
		return false;
	else
		return true;
}


void bfs(vector<int>&map,int start,int end)
{
	queue<int>q;
	int count = 0;
	q.push(start);
	map[start]=0;
	if(start==end)
	{
		return;
	}
	while(!q.empty())
	{
		int pos = q.front();

		if (pos == end)
			return;
		count = map[pos];

		if (!isWall(2 * pos))
		{
			if(map[2*pos]>count+1)
			{
				q.push(2 * pos);
				map[2 * pos] = (count+1);
			}
		}
		if (!isWall(pos + 1))
		{
			if(map[pos + 1] > count + 1)
			{
				q.push(pos + 1);
				map[pos + 1] = (count + 1);
			}
		}
		if (!isWall(pos - 1))
		{
			if (map[pos - 1] > count + 1)
			{
				q.push(pos - 1);
				map[pos - 1] = (count + 1);
			}
		}
		q.pop();
	}
}


int main()
{
	int start;
	int end;
	vector<int>map(100001,INT32_MAX);
	cin>>start>>end;
	bfs(map,start,end);
	cout<< map[end];
}