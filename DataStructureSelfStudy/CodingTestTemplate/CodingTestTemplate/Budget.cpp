#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    sort(d.begin(),d.end());
    

    for (int temp : d)
    {
        if ((budget - temp) < 0)
        {
            break;
        }
        else
        {
            budget-=temp;
            answer++;
        }
    }


    return answer;
}



int main()
{
    cout<<solution({1, 3, 2, 5, 4},	9);
}