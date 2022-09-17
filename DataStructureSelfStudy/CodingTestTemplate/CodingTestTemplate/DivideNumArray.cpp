#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> answer;
    sort(arr.begin(),arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
    for (int temp : solution({ 5, 9, 7, 10 },5))
    {
        cout << temp;
    }
}