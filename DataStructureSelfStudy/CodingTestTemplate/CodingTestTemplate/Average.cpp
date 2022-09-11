#include <iostream>

#include <vector>
using namespace std;


double solution(vector<int> arr) 
{
    double answer = 0;


    for (int temp : arr)
    {
        answer+=temp;
    }

    answer/=(double)arr.size();

    return answer;
}

int main()
{
    cout<<solution({1,2,3,4});
}