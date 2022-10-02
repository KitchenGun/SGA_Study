#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;



string makeNoZero(string s,int &count)
{
    string onestr;

    for (char a : s)
    {
        if (a == '1')
            onestr.push_back(a);
        else 
            count++;
    }
    return onestr;
}

string makeBinary(int size)
{
    stack<int> stk;
    string ans ="";
    while (size != 0)
    {
        if (size % 2 == 0)
        {
            stk.push(0);
            size /= 2;
        }
        else
        {
            stk.push(1);
            size /= 2;
        }
    }

    while (!stk.empty())
    {
        ans.push_back('0'+(stk.top()));
        stk.pop();
    }
   
    return ans;
}

vector<int> solution(string s) 
{
    vector<int> answer(2,0);

    while (s != "1")
    {
        s = makeNoZero(s,answer[1]);
        if (s != "1")
            s = makeBinary(s.size());
        answer[0]++;
    }

    return answer;
}


int main()
{
    cout<<solution("110010101001")[0]<<" "<< solution("110010101001")[1];
}