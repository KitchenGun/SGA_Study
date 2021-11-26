#include <iostream>
#include <vector>
using namespace std;



int rotate(vector<vector<int>>& matrix, pair<int, int> query_start, pair<int, int> query_end)
{
    int first = matrix[query_start.first - 1][query_start.second - 1];
    int minVal = first;
    //1.상단
    for (int i = query_start.first; i < query_end.first; ++i)
    {
        matrix[i-1][query_start.second-1] = matrix[i][query_start.second - 1];
        minVal = min(minVal, matrix[i - 1][query_start.second - 1]);
    }

    //좌측
    for (int i = query_start.second; i < query_end.second; i++)
    {
        matrix[query_end.first - 1][i - 1] = matrix[query_end.first - 1][i];

        minVal = min(minVal, matrix[query_end.first - 1][i - 1]);
    }

    //하단
    for (int i = query_end.first - 2; i >= query_start.first - 1; i--)
    {
        matrix[i + 1][query_end.second - 1] = matrix[i][query_end.second - 1];

        minVal = min(minVal, matrix[i + 1][query_end.second - 1]);
    }

    //우측
    for (int i = query_end.second - 2; i > query_start.second - 1; i--)
    {
        matrix[query_start.first - 1][i + 1] = matrix[query_start.first - 1][i];

        minVal = min(minVal, matrix[query_start.first - 1][i + 1]);
    }

    matrix[query_start.first - 1][query_start.second] = first;
    return minVal;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns));

    //기본 행렬 생성
    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = num++;
        }
    }
    //회전 처리
    for (auto query : queries)
    {
        answer.push_back(rotate(matrix, { query[0], query[1] }, { query[2], query[3]}));
    }
    return answer;
}


int main()
{
    vector<vector<int>> test = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };
    for (int temp : solution(6, 6, test))
    {
        cout << temp << endl;
    }

}