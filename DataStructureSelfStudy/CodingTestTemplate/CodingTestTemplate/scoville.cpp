#include <iostream>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    priority_queue<long,vector<long>,greater<long>> pq(scoville.begin(),scoville.end());

    while (pq.size()>1&& pq.top() <= K)
    {
        answer++;
        long top = pq.top();
        pq.pop();
        long second = pq.top();
        pq.pop();
        long newScoville = top + (second * 2);
        pq.push(newScoville);
    }
    if(pq.top()<K)
        return -1;
    else
        return answer;
}


int main()
{
    cout<< solution({1, 2, 3, 9, 10, 12},7);
}