#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    bool answer = true;

    string xstr = to_string(x);

    int value =0;

    for (char temp : xstr)
    {
        value+=(temp-'0');
    }


    if (x % value!=0)
    {
        return false;
    }

    return answer;
}


int main()
{
    cout << (solution(13) ? "true" : "false");
}