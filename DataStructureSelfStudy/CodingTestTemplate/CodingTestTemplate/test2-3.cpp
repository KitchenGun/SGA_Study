#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> entryEnengy;
vector<int> useEnengy;
vector<bool> visit;
int answer;
void dfs(int k, int result)
{
    int num = entryEnengy.size();

    for (int i = 0; i < num; i++)
    {
        if (!visit[i] && k >= entryEnengy[i])
        {
            visit[i] = true;
            dfs(k-useEnengy[i],result+1);
            visit[i]= false;
        }
    }
    answer = max(answer,result);
    return;
}

int solution(int k, vector<vector<int>> dungeons)
{
    answer =0;
    for (auto temp : dungeons)
    {
        entryEnengy.push_back(temp[0]);
        useEnengy.push_back(temp[1]);
        visit.push_back(false);
    }
    dfs(k,0);
    return answer;
}


int main()
{
    cout<<solution(80, {{80, 20}, {50, 40}, {30, 10}} );
}