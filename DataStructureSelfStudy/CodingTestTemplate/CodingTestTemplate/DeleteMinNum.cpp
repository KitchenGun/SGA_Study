#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    if (arr.size() <= 1)
    {
        answer.push_back(-1);
    }
    else
    {
        int minIndex = 0;
        for (int i = 1; i < arr.size(); i++)
        {
           int minVal=min(arr[minIndex],arr[i]);
           if (minVal == arr[i])
           {
               minIndex = i;
           }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (i != minIndex)
            {
                answer.push_back(arr[i]);
            }
        }
    }


    return answer;
}



int main()
{
    for(int temp:solution({4,3,2,1}))
    {
        cout<<temp;
    }
}