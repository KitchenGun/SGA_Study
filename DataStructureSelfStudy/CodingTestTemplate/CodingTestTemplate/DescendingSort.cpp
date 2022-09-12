#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


long long solution(long long n) 
{
    long long answer = 0;
    string nstr = to_string(n);
    vector<int> s;
    for (char temp : nstr)
    {
        s.push_back((temp-'0'));
    }
    
    nstr="";
    sort(s.begin(),s.end(),greater<int>());
    for (int temp : s)
    {
        nstr.append(to_string(temp));
    }

    answer = stoll(nstr);

    return answer;
}

int main()
{
    cout<<solution(118372);
}