#include <iostream>
#include <vector>
#include <queue>


using namespace std;

//int dfs(const vector<vector<bool>>adj,vector<bool>&visit,int cur,const int n)
//{
//	if (visit[cur])
//		return 0;
//
//	visit[cur] = true;
//
//    int nodeCount = 1;
//    for (int next = 1; next < n; next++)
//    {
//        if(!adj[cur][next])
//            continue;
//        nodeCount+=dfs(adj,visit,next,n);
//    }
//
//    return nodeCount;
//}

int bfs(const vector<vector<bool>>adj, vector<bool>& visit, int cur)
{
   queue<int> q;
   int count = 0;
   q.push(cur);
   visit[cur] = true;

   while (!q.empty())
   {
        count++;
        int top = q.front();
        q.pop();
        for (int i=1;i<adj[top].size();i++)
        {
            if (!visit[i]&& adj[top][i])
            {
                q.push(i);
                visit[i] = true;
            }
        }
   }
   return count;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 201;

    vector<vector<bool>> adj (n+1,vector<bool>(n+1,false));
    
    for (vector<int> temp : wires)
    {
        int a,b;

        a = temp[0];
        b = temp[1];

        adj[a][b] = adj[b][a] = true;
    }

    
    for (int i = 0; i < wires.size(); i++) 
    {
        //간선을 하나씩 끊어서 탐색하기
        int a = wires[i][0];
        int b = wires[i][1];

        adj[a][b] = adj[b][a] = false;

        vector<int> count ;
        vector<bool> visit(n + 1, false);

        for (int j = 1; j <= n; j++)
        {
            if(visit[j] != true)
            {    
                int temp = bfs(adj,visit,j);
                count.push_back(temp);
            }
        }

        answer = min(answer,abs(count[0]-count[1]));
        adj[a][b] = adj[b][a] = true;
    }

    return answer;
}

int main()
{
    cout<<solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} );
}