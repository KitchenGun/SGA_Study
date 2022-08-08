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
    queue<int> q;//�ٸ� ���̸�ŭ ����� �����Ұ���

    while (1)
    {
        if (idx == truck_weights.size())//������ Ʈ���� ���
        {
            answer+=bridge_length;
            break;
        }

        answer++;

        int temp = truck_weights[idx];//���� ���������ϴ� Ʈ��
        //Ʈ���� �ٸ��� ������ ���
        if (q.size() == bridge_length)
        {
            curweight-=q.front();
            q.pop();
        }
        //�ٸ��� ���԰� �ɰ�� �ٸ����� Ʈ�� �ø�
        if (curweight + temp <= weight)
        {
            curweight+=temp;
            q.push(temp);
            idx++;
        }
        else//���԰� �ȵɰ�� �� ��ü �ֱ�
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