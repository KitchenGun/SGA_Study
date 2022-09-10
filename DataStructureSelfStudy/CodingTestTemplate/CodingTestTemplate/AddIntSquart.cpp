#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

long long solution(long long n) 
{
    long double answerld = 0;
    long long answer = 0;
    answer =answerld= sqrtl(n);

    if(answerld - answer !=0)
        return -1;
    else
        answer = ((answer + 1) * (answer+1));
    return answer;
}




int main()
{
    cout<< solution(121);
}