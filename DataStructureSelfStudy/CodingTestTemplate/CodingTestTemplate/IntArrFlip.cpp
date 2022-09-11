#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;


    string nstr = to_string(n);
    stack<char> arr;
    for (char temp : nstr)
    {
        arr.push(temp);
    }

    while (!arr.empty())
    {
        answer.push_back(arr.top()-'0');
        arr.pop();
    }

    return answer;
}


int main()
{
    for (int temp : solution(12345))
    {
        cout<<temp;
    }
}