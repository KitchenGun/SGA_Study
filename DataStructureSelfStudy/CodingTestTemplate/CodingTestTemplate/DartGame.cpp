#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    stack<int> s;
    string num="";
    for (char temp : dartResult)
    {
        if ('0' <= temp && temp <= '9')
        {
            num.push_back(temp);
        }
        else
        {
            if(num!="")
            {
                s.push(stoi(num));
                num="";
            }
            int tempNum1,tempNum2;
            switch (temp)
            {
            case 'S':
                break;
            case 'D':
                tempNum1 = pow(s.top(),2);
                s.pop();
                s.push(tempNum1);
                break;
            case 'T':
                tempNum1 = pow(s.top(), 3);
                s.pop();
                s.push(tempNum1);
                break;
            case '*':
                tempNum1 =s.top()*2;
                s.pop();
                tempNum2 = s.top() * 2;
                s.pop();
                s.push(tempNum2);
                s.push(tempNum1);
                break;
            case '#' :
                tempNum1 = s.top()*-1;
                s.pop();
                s.push(tempNum1);
                break;
            default:
                break;
            }

        }
    }

    while (!s.empty())
    {
        answer+=s.top();
        s.pop();
    }

    return answer;
}


int main()
{
    cout<<solution("1D2S#10S");
}