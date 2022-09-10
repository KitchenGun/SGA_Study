#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    int a = 1;

    while (a <= n)
    {
        if(n%a==0)
            answer+=a;
        a++;
    }

    return answer;
}


int main()
{
    cout<<solution(5);
}