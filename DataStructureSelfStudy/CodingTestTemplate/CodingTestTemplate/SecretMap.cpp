#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int ArrSize;

string Binary(int n)
{
    stack<char> s;
    string answer="";
    while (n!=0)
    {
        if (n % 2 != 0)
        {
            s.push('#');
        }
        else
        {
            s.push(' ');
        }
        n/=2;
    }

    if (s.size() < ArrSize)
    {
        int temp = ArrSize - s.size();
        for(int i =0;i< temp;i++)
        {
            s.push(' ');
        }
    }

    while (!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    ArrSize = n;

    for (int i = 0; i < ArrSize; i++)
    {
        string a,b,c;
        a = Binary(arr1[i]);
        b = Binary(arr2[i]);
        
        for (int i = 0; i < ArrSize; i++)
        {
            if (a[i] == ' ' && b[i] == ' ')
            {
                c.push_back(' ');
            }
            else
            {
                c.push_back('#');
            }
        }
        answer.push_back(c);
    }

    return answer;
}



int main()
{
    vector<string> temp = solution(5, {9, 20, 28, 18, 11},{ 30, 1, 21, 17, 28 });


    for (string a : temp)
    {
        cout<<a<<endl;
    }
}