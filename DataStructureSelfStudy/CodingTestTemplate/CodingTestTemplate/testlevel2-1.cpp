#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> nums;
    string temp;
    

    for (int i = 0; i < s.size(); i++)//¹è¿­¿¡ »ðÀÔ
    {

        if (isdigit(s[i])||s[i]=='-')
        {
           temp.push_back(s[i]);
        }
        else
        {
            nums.push_back(stoi(temp));
            temp ="";
        }
    }
    nums.push_back(stoi(temp));

    sort(nums.begin(), nums.end());

    answer.append(to_string(nums.at(0)));
    answer.append(" ");
    answer.append(to_string(nums.at(nums.size() - 1)));

    return answer;
}

int main()
{
    cout<<solution("10 2 3 -40");
}