#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;




long long solution(int a, int b)
{
    long long answer = 0;
    int start =0;
    int end =0;
    if(a<b)
    {
        start = a;
        end = b;
    }
    else
    {
        start = b;
        end = a;
    }

    while (start <= end)
    {
        answer+=start;
        start++;
    }
    
    return answer;
}

int main()
{
    cout<< solution(5,3);
}