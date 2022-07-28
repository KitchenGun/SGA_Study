#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    for (int i =0;i<sizes.size();i++)
    {
        sort(sizes[i].begin(), sizes[i].end());
    }

    int w=0,h=0;

    for (auto temp : sizes)
    {
        if(w<temp[0])
            w = temp[0];
        if(h<temp[1])
            h = temp[1];
    }

    answer = h*w;


    return answer;
}

int main()
{
	cout<<solution({{60, 50}, {30, 70}, {60, 30}, {80, 40}});
}