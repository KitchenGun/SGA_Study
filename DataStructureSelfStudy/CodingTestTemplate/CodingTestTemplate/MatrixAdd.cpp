#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer(arr1.size(),vector<int>(arr1[0].size()));


    for (int y = 0; y < arr1.size(); y++)
    {
        for (int x = 0; x < arr1[0].size(); x++)
        {
            answer[y][x] = arr1[y][x]+arr2[y][x];
        }
    }

    return answer;
}


int main()
{
   solution({{1,2},{2,3}},{{4,6},{7,9}});

}