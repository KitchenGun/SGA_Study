#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    string strNum;
    vector<int> nums;
    for (char temp : s)
    {
        if (temp == ' ')
        {
            nums.push_back(stoi(strNum));
            strNum="";
        }
        else
        {
            strNum.push_back(temp);
        }
    }
    nums.push_back(stoi(strNum));

    sort(nums.begin(),nums.end());

    int min = *nums.begin();
    int max = *(nums.end()-1);
    
    answer.append(to_string(min));
    answer.append(" ");
    answer.append(to_string(max));


    return answer;
}


int main()
{
    cout<<solution("1 2 3 4");
}