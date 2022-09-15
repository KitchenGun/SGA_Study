#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";
    int point=0;
    for (string temp : seoul)
    {
        if (!strcmp("Kim",temp.c_str()))
        {
            break;
        }
        point++;
    }
    answer ="김서방은 ";
    answer.append(to_string(point));
    answer.append("에 있다");

    return answer;
}

int main()
{
    cout<< solution({"Jane", "Kim"});
}