#include <iostream>
#include<string>
#include <stack>
using namespace std;


//ȿ���� ��� ����  stack�� ����߾����
/*
int solution(string s)
{

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {    
            s.erase(s.begin() + (i - 1), s.begin() + (i+1));
            i=0;
        }
        if (i+1 >= s.size())
            break;
    }

    if (s.size() == 0)
        return 1;
    else
        return 0;

}
*/

int solution(string s)
{

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            s.erase(s.begin() + (i - 1), s.begin() + (i + 1));
            i = 0;
        }
        if (i + 1 >= s.size())
            break;
    }

    if (s.size() == 0)
        return 1;
    else
        return 0;

}


int main()
{
    cout<<solution("aacc");
}