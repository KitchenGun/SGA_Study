#include <iostream>
#include <vector>

using namespace std;

long long solution(long long price, long long money, long long count)
{
    long long answer = 0;

    for (int i = 1; i <= count; i++)
    {
        answer+=price*i;
    }
    answer-=money;

    if (answer <= 0)
    {
        return 0;
    }

    return answer;
}


int main()
{
    long long price, money, count;

    cin >> price >> money >> count;

    cout << solution(price, money, count);

    return 0;
}