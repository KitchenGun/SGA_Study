#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    vector<pair<int,int>> workprogress;
    for (int i = 0; i < speeds.size(); i++)
    {
        pair<int,int> data = {progresses[i],speeds[i]};
        workprogress.push_back(data);
    }
    
  
    int stage = 0;
    while (1)
    {
        for (int i =0;i< workprogress.size();i++)
        {
            workprogress[i].first+= workprogress[i].second;
        }

        int count=0;
        while (workprogress[stage].first >= 100)
        {
            stage++;
            count++;
            if (stage == workprogress.size())
            {
                if (count != 0)
                    answer.push_back(count);
                return answer;
            }
        }
        if(count!=0)
            answer.push_back(count);
        
    }
}



int main()
{
    vector<int> answer;

    answer = solution({93, 30, 55},{1, 30, 5});

    for (auto temp : answer)
    {
        cout << temp << endl;
    }
}