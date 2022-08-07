#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    queue<int> q;

    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
    }

    int target = q.front();
    answer.push_back(target);

    while (!q.empty())
    {
        if (q.front() == target)
        {
            q.pop();
        }
        else
        {
            target=q.front();
            answer.push_back(target);
            q.pop();
        }
    }
    return answer;
}

int main()
{
    vector<int> answer;

    answer = solution({1, 1, 3, 3, 0, 1, 1});

    for (auto temp : answer)
    {
        cout << temp << endl;
    }
}