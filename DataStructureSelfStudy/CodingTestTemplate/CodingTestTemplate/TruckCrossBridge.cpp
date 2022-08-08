#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int idx = 0;
    int answer = 0;
    int curweight = 0;
    queue<int> q;//다리 길이만큼 사이즈를 유지할것임

    while (1)
    {
        if (idx == truck_weights.size())//마지막 트럭일 경우
        {
            answer+=bridge_length;
            break;
        }

        answer++;

        int temp = truck_weights[idx];//지금 지나가야하는 트럭
        //트럭이 다리를 지나간 경우
        if (q.size() == bridge_length)
        {
            curweight-=q.front();
            q.pop();
        }
        //다리에 무게가 될경우 다리위에 트럭 올림
        if (curweight + temp <= weight)
        {
            curweight+=temp;
            q.push(temp);
            idx++;
        }
        else//무게가 안될경우 빈 객체 넣기
        {
            q.push(0);
        }
    }
     
    return answer;
}



int main()
{
    cout<<solution(20,10,{7, 4, 5, 6});
}