#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//bool comp(pair<int, int> a, pair<int, int> b)
//{
//    return  a.first > b.first;
//}
//
//int solution(vector<int> priorities, int location) 
//{
//    int answer = 0;
//    vector<pair<int,int>> list;
//
//    for (int i = priorities.size()-1; i >= 0; i--)
//    {
//        list.push_back({priorities[i],i});
//    }
//    
//
//    sort(list.begin(),list.end(),comp);
//
//
//    for (int i = 0; i < list.size(); i++)
//    {
//        if (list[i].second == location)
//        {
//            answer = (list.size()-1)-i+1;
//        }
//    }
//
//    return answer;
//}


int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({i,priorities[i]});
    }


    while (!q.empty())
	{
		int index = q.front().first;
		int value = q.front().second;
        q.pop();
        if (value == pq.top())
        {
            pq.pop();
            answer++;
            if(index==location)
                break;
        }
        else
        {
            q.push({index,value});
        }
        
    }

    return answer;
}


int main()
{
    cout<<solution({ 2, 1, 3, 2 }, 2);
}