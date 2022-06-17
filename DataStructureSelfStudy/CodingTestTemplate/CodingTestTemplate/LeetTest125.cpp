#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "A man, a plan, a canal: Panama";


    int start = 0;
    int end = s.size() - 1;
    int size = s.size() - 1;

    string temp;
    for (int i = 0; i <= size; i++)
    {
        s[i] = tolower(s[i]);
        if(s[i] >= 'a' && 'z' >= s[i])
        {
            temp.push_back(s[i]);
        }
    }
    end=temp.size()-1;

    if (temp.empty())
    { 
        cout << "True";
        return 0;
    }

    while (end > start)
    {
        if (temp[start] != temp[end])
        {
            cout << "false";
            return 0;
        }
        else
        {
            start++;
            end--;
        }
    }
    cout<<"True";
    return 0;
}
