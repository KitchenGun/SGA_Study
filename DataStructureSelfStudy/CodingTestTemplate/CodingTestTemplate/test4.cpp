#include <iostream>

using namespace std;

int main()
{
    int max_X;
    int max_Y;
    int array[100][100] = { 0 };
    int count;

    int l, d, x, y;

    max_X=5;
    max_Y=5;
    count=3;


    for (int i = 0; i <= 0; i++)
    {
        l=3;
        d=1;
        x=3;
        y=2;
        x--;
        y--;

        if (d == 0)
        {
            for (int j = x; j < x + l; j++)
            {
                if (array[j][y] == 1)
                    array[j][y] = 0;
                else
                    array[j][y] = 1;
            }
        }
        else
        {
            for (int j = y; j < y + l; j++)
            {
                if (array[x][j] == 1)
                    array[x][j] = 0;
                else
                    array[x][j] = 1;
            }
        }
    }


    for (int i = 0; i < max_Y; i++)
    {
        for (int j = 0; j < max_X; j++)
        {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }

}