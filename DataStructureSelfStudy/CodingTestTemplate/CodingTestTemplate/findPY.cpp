#include <iostream>
#include <string>
using namespace std;

bool solution(string s)
{
    int p=0,y=0;
    for (char temp : s)
    {
        if (temp == 'p' || temp == 'P')
        {
            p++;
        }
        else if (temp == 'y' || temp == 'Y')
        {
            y++;
        }
    }

    if(p-y==0)
        return true;
    else
        return false;
}



int main()
{
    cout<<(solution("pPoooyY")?"true":"false");
}