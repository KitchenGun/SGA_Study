#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer(2,0);

    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int unknow = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            unknow++;
        }
        else
        {
            break;
        }
    }


    int j=0;
    for (int i = 0; i < win_nums.size(); i++)
    {
        while(lottos[j] < win_nums[i])
        {
            j++;
            if (j >= win_nums.size())
            {
                break;
            }
        }
        if (j >= win_nums.size())
        {
            break;
        }
        
        if (lottos[j] == win_nums[i])
        {
            answer[0]++;
            j++;
        }
    }

    answer[1]=(answer[0]+unknow>win_nums.size())?win_nums.size(): answer[0] + unknow;

    for (int& temp : answer)
    {
        temp=(6-temp)+1;
        if (temp > 6)
        {
            temp = 6;
        }
    }

    if (answer[0] > answer[1])
    {
        int temp = answer[0];
        answer[0]=answer[1];
        answer[1] = temp;
    }

    return answer;
}


int main()
{
    vector<int> temp = solution({44, 1, 0, 0, 31, 25},{31, 10, 45, 1, 6, 19});

    for (int t : temp)
    {
        cout<<t;
    }
}