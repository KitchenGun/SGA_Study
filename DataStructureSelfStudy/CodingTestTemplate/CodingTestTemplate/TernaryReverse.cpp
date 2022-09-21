#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    stack<char> ternary;
    string num = "";
    while (n > 0)
    {
        ternary.push(n % 3 + '0');
        n/=3;
    }

    while (!ternary.empty())
    {
        num.push_back(ternary.top());
        ternary.pop();
    }
    
    reverse(num.begin(),num.end());

    for(int temp : num)
    {
        ternary.push(temp-'0');
    }
    int powval =1;
    while (!ternary.empty())
    {
        answer+=(ternary.top()*powval);
        powval*=3;
        ternary.pop();
    }
    return answer;
}


int main()
{
    cout<<solution(45);
}