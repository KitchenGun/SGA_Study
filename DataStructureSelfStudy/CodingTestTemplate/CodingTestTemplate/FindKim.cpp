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
    answer ="�輭���� ";
    answer.append(to_string(point));
    answer.append("�� �ִ�");

    return answer;
}

int main()
{
    cout<< solution({"Jane", "Kim"});
}