#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool FindPrime(int target)
{
    for (int i = 2; i*i <= target; i++)
    {
        if (target % i == 0)
        {
            return false;
        }
    }
    return true;
}


int solution(int n) 
{
    int answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (FindPrime(i))
        {
            answer++;
        }
    }

    return answer;
}


int main()
{
    cout<<solution(5);
}