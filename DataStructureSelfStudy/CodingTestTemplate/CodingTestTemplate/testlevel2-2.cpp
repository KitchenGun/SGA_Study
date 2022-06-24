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

int solution(string s)//stack���� ����
{
    int answer =0;

    if(s.empty()||s.size()%2==1)
        return 0;


    stack<char> stk;
    for (size_t nIndex = 0; nIndex < s.size(); ++nIndex)
    {
        if (stk.empty() || stk.top() != s[nIndex])//���ÿ� ����ִ� �Ͱ� ������ �������� ��ġ���� ��
            stk.push(s[nIndex]);
        else//��ġ�Ұ�� ������ ����
            stk.pop();

    }

    if (stk.empty())//���� ��ȸ�ϰ� ���ÿ� ���� ���� ������ 1
        ++answer;

    return answer;

}


int main()
{
    cout<<solution("aacc");
}