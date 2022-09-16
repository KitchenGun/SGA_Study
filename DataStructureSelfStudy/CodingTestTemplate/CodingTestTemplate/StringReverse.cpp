#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




string solution(string s) 
{
    sort(s.begin(),s.end(),greater<int>());

    return s;
}


int main()
{
    cout<<solution("Zbcdefg");
}