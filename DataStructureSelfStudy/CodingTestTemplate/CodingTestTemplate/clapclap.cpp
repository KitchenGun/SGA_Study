#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    bool trigger = true;
    for (int i = 0; i < n; i++)
    {
        
        if (trigger)
        {
            answer.append("��");
            trigger = false;
        }
        else
        {
            answer.append("��");
            trigger = true;
        }
    }
    return answer;
}


int main()
{
    cout<<solution(5);
}