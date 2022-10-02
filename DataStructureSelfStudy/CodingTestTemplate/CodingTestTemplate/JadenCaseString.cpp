#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";

    string word;
    for (char& temp : s)
    {
        if (temp == ' ')
        {
           answer.append(word);
           answer.push_back(' ');
           word="";
        }
        else if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z'))
        {
            if (word=="")
            {
                word.push_back(toupper(temp));
            }
            else
            {
                word.push_back(tolower(temp));
            }
        }
        else
        {
            word.push_back(temp);
        }
    }
    answer.append(word);

    return answer;
}


int main()
{
    cout<<solution("3people unFollowed me");
}