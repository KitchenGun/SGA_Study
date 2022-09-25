#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    for (char& temp : s)
    {
        if('a'<=temp && temp <= 'z')
        {
            if(temp+n<='z')
                temp +=n;
            else
            {
                temp = 'a'+((temp+(n-1)) - 'z');
            }
        }
        else if ('A' <= temp && temp <= 'Z')
        {
            if (temp + n <= 'Z')
                temp += n;
            else
            {
                temp = 'A' + ((temp + (n - 1)) - 'Z');
            }
        }
    }

    return s;
}


int main()
{
    cout<<solution("a B z",4);
}