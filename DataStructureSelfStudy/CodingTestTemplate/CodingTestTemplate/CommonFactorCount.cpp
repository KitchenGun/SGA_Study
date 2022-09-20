#include <iostream>
#include <string>
#include <vector>

using namespace std;



int func(int target)
{
    int count=0;
    for (int i = 1; i <= target; i++)
    {
        if (target % i == 0)
        {
            count++;
        }
    }
    return count;
}



int solution(int left, int right) 
{
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        int count = func(i);

        if (count % 2 == 0)
        {
            answer+=i;
        }
        else
        {
            answer-=i;
        }
    }

    return answer;
}


int main()
{
    cout<<solution(13,17);

}