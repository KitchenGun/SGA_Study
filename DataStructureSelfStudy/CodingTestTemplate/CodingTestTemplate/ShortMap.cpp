#include <iostream>
#include<algorithm>
#include <vector>
#include <queue>


using namespace std;

bool isWall(pair<int, int> pos,int ymax,int xmax)
{
    if((pos.first>=0&&pos.first<ymax)&&(pos.second>=0&&pos.second<xmax))
        return false;
    
    return true;
}


int bfs(vector<vector<int>> map)
{
    queue<pair<int,int>> q;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    int xsize = map[0].size();
    int ysize = map.size();

    vector<vector<int>> data(ysize,vector<int>(xsize,0));
    q.push({0,0});
    data[0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for (pair<int, int> d : dir)
        {
            pair<int,int> newpos = {top.first+d.first,top.second+d.second};
            if (!isWall(newpos, ysize, xsize))
            {
                if (data[newpos.first][newpos.second] == 0&&map[newpos.first][newpos.second]==1)
                {
                    data[newpos.first][newpos.second] = min(data[top.first][top.second]+1, (data[newpos.first][newpos.second]? data[newpos.first][newpos.second]:INT32_MAX));
                    q.push(newpos);
                }
            }
        }
    }
    //연결되있는지 확인
    return (data[ysize-1][xsize-1]? data[ysize-1][xsize-1]:-1);
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;


    answer = bfs(maps);

    return answer;
}

int main()
{
    
    cout<<solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}} );

}