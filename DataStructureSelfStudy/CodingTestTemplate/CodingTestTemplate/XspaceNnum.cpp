#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) 
{
    vector<long long> answer;
    int plusVal = x;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(x);
        x+= plusVal;
    }

    return answer;
}


int main()
{
    for (long long temp : solution(2, 5))
    {
        cout<<temp;
    }
}