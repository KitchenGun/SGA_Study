#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;

bool Sort(string a, string b)
{
    if (a[num] == b[num])
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                if (a[i] < b[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else if (a[num] < b[num])
    {
        return true;
    }
    else
    {
        return false;
    }
}


vector<string> solution(vector<string> strings, int n) 
{
    num = n;
    sort(strings.begin(),strings.end(),Sort);


    return strings;
}


int main()
{
    for (string temp : solution({ "sun", "bed", "car" }, 1))
    {
        cout<<temp;
    }
}