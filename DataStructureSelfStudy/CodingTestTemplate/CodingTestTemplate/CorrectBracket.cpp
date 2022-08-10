#include <iostream>
#include <vector>
#include <stack>


using namespace std;



bool solution(string s)
{
    bool answer = true;
    stack<char> ss;

    for (auto temp : s)
    {
        if (temp == '(')
        {
            ss.push(temp);
        }
        else
        {
            if(!ss.empty())
                ss.pop();
            else
                return false;
        }
    }
    if(!ss.empty())
        answer = false;
    return answer;
}

int main()
{
	cout<<solution(")()(");
}