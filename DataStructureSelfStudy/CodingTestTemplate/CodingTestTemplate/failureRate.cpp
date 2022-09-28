#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<int, float> a, pair<int, float> b)
{
    return a.second>b.second?true:false;
}


vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    map<int,float> data;


    for (int i = 1; i <= N; i++)
    {
        data.insert({i,0});
    }

	for (int target = 1; target <= N; target++)
	{
        int reach = 0;
        int pass = 0;

		for (int i = 0; i < stages.size(); i++)
		{
            if (stages[i] >= target)
            {
                reach++;
                if (stages[i] > target)
                {
                    pass++;
                }
            }
		}

        float val = reach - pass;
        data[target] = val / reach;
	}

    map<int,float>::iterator iter;
    vector<pair<int,float>> sortArr;
    for (iter = data.begin(); iter != data.end(); iter++)
    {
        pair<int,float> temp = *iter;
        sortArr.push_back(temp);
    }

    stable_sort(sortArr.begin(),sortArr.end(),comp);

    for (pair<int, float>temp : sortArr)
    {
        answer.push_back(temp.first);
    }


    return answer;
}


int main()
{
    vector<int> temp = solution(5,{2, 1, 2, 6, 2, 4, 3, 3});

    for (int i : temp)
    {
        cout<<i;
    }
}