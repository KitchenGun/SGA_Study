#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans;
vector<int> visit;

void bfs(vector<vector<int>>& computers,int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int target =  q.front();
        visit[start] = true;
        q.pop();
        for (int i = 0; i < computers[target].size(); i++)
        {
            if (target != i&&computers[target][i]==1)
            {
                if(!visit[i])
                {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
}


int solution(int n, vector<vector<int>> computers) 
{
    int ans = 0;
    visit.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if(visit[i]==false)
        {
           bfs(computers,i);
           ans++;
        }
    }
    return ans;
}

int main()
{
	cout<<solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}} );
}