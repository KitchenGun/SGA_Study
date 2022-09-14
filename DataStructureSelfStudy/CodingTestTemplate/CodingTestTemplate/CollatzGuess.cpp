#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    int answer = 0;
    long long numl = num;
    while (numl != 1)
    {
        answer++;
        if (numl % 2 == 0)
        {
            numl /= 2;
        }
        else
        {
            numl *=3;
            numl +=1;
        }
        if (answer > 500)
        {
            return -1;
        }
    }
    
   
    return answer;
}



int main()
{
    cout<<solution(626331);
}