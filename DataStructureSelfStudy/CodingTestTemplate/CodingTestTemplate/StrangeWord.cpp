#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int size = s.size();
    int count =0;

    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            count = 0;
            answer.push_back(' ');
            continue;
        }

        if (count % 2 == 0)
        {
            answer.push_back(toupper(s[i]));
            count++;
        }
        else
        {
            answer.push_back(tolower(s[i]));
            count++;
        }
    }
    

    return answer;
}


int main()
{
    cout<<solution("try hello world");
}