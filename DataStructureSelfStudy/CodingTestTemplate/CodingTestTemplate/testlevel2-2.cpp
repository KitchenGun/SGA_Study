#include <iostream>
#include<string>
#include <stack>
using namespace std;


//효율성 통과 실패  stack을 사용했어야함
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

int solution(string s)//stack으로 변경
{
    int answer =0;

    if(s.empty()||s.size()%2==1)
        return 0;


    stack<char> stk;
    for (size_t nIndex = 0; nIndex < s.size(); ++nIndex)
    {
        if (stk.empty() || stk.top() != s[nIndex])//스택에 집어넣는 것과 다음에 넣을것이 일치한지 비교
            stk.push(s[nIndex]);
        else//일치할경우 꺼내서 삭제
            stk.pop();

    }

    if (stk.empty())//전부 순회하고 스택에 남은 것이 있으면 1
        ++answer;

    return answer;

}


int main()
{
    cout<<solution("aacc");
}