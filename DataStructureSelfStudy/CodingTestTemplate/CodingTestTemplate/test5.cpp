#include <iostream>

using namespace std;

int main()
{
    int ground[10][10]=
    {
        1,1,1,1,1,1,1,1,1,1,
        1,0,0,1,0,0,0,0,0,1,
        1,0,0,1,1,1,0,0,0,1,
        1,0,0,0,0,0,0,1,0,1,
        1,0,0,0,0,0,0,1,0,1,
        1,0,0,0,0,1,0,1,0,1,
        1,0,0,0,0,1,2,1,0,1,
        1,0,0,0,0,1,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1
    };

    pair<int, int> pos = { 1,1 };
    pair<int, int> goal = { 6,6 };

    ground[pos.first][pos.second] = 9;
    while (1)
    {
        if (ground[pos.first][pos.second + 1] == 0)
        {
            pos = { pos.first,pos.second + 1 };
        }
        else if (ground[pos.first + 1][pos.second] == 0)
        {
            pos = { pos.first + 1,pos.second };
        }
        ground[pos.first][pos.second] = 9;
        if (ground[pos.first][pos.second + 1] == 2)
        {
            pos = { pos.first,pos.second + 1 };
        }
        else if (ground[pos.first + 1][pos.second] == 2)
        {
            pos = { pos.first + 1,pos.second };
        }
        if (pos == goal)
        {
            break;
        }
        if (ground[pos.first + 1][pos.second] == 1 && ground[pos.first][pos.second + 1] == 1)
        {
            break;
        }
    }

    if (pos == goal)
    {
        ground[goal.first][ goal.second] = 9;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", ground[i][j]);
        }
        printf("\n");
    }

}