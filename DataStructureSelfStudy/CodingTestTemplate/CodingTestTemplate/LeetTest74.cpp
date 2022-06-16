#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    vector<vector<int>> matrix = {{1}};

    int target = 1;

    int m = matrix.size()-1;
    int n = matrix[0].size()-1;

    if (target >= matrix[0][0] && target <= matrix[m][n])
    {

        for (int i = 0; i <= m; i++)
        {
            if (target == matrix[i][0])
            {
                cout << "True";
                return 0;
            }
            else
            {
                for (int j = 0; j <= n; j++)
                {
                    if (matrix[i][j] == target)
                    {
                        cout<<"True";
                        return 0;
                    }
                }
            }
        }
        cout << "False";
        return 0;
    }
    else
    {
        cout << "False";
        return 0;
    }
}