#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void bfs(vector<int> &check,vector<vector<int>>edge)
{
    queue<int> q;
    q.push(0);
    check[0] = 1;
    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        for (int n : edge[target])
        {
            if (check[n] == 0)
            {
                check[n] = check[target]+1;
                q.push(n);
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    int maxrange = 0;
    vector<vector<int>> edges(n);
    for (vector<int> info : edge)
    {
        edges[info[0]-1].push_back(info[1]-1);
        edges[info[1]-1].push_back(info[0]-1);
    }


    vector<int> check(n,0);

    bfs(check, edges);


    for (int i = 0; i < n; i++)
    {
        maxrange = max(maxrange,check[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (maxrange == check[i])
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout<<solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}} );
}