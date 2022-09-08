#include <iostream>
#include <string>
using namespace std;


int solution(int n)
{
    int answer = 0;

    string nStr = to_string(n);

    for (int temp : nStr)
    {
        answer+=temp-'0';
    }

    return answer;
}

int main()
{
    cout<<solution(123);
}