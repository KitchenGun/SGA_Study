#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
    string name = "ABABAAAAABA";
    string temp(name.length(), 'A');
    int answer = 0;
    for (int i = 0; i<name.length();++i)
    {
        int min = 0;
        //위 아래 이동

        if (name[i] == 'A')
        {
            int target = i;
            while (target < name.length() && name[target] == 'A')
                target += 1; //A로만 이루어진 문자열 찾기
            int left = i == 0 ? 0 : i - 1; //찾은 문자열 왼쪽에서의 이동횟수
            int right = name.length() - target;  //찾은 문자열 오른쪽에서의 이동횟수
            shift = min(shift, left + right + min(left, right)); //가장 작은값 찾기
        }
        
        if (name[name.length()-1] != (temp[i]))
            ++answer;

        temp[i] - 'A' > 'Z' - temp[i] + 1 ? answer += temp[i] - 'A' : answer += 'Z' - temp[i] + 1;
    }
    
    cout << answer;
}