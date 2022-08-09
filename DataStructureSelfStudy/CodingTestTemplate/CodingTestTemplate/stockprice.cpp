#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//vector<int> solution(vector<int> prices) //stack queue�� �Ⱦ��� Ǫ�� ��
//{
//    vector<int> answer;
//    answer.assign(prices.size(),0);
//
//    for (int i = 0; i < prices.size(); i++) {
//
//        for (int j = i + 1; j < prices.size(); j++) {
//            answer[i]++;
//            if (prices[i] > prices[j]) break;
//        }
//    }
//    return answer;
//}

//������ ����ؼ� Ǫ�¹�   �ӵ� ���̵� ���� �ٸ��� �ʾƼ� ���� �ƴ� ó�� ������� Ǯ� �����̿���.
vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    stack<int> s;
    int size = prices.size();
    answer.assign(size, 0);

    for (int i = 0; i < size; i++) 
    {
        while (!s.empty() && prices[s.top()] > prices[i]) 
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) 
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}


int main()
{
    vector<int> answer;

    answer = solution({1, 2, 3, 2, 3});

    for (auto temp : answer)
    {
        cout << temp << endl;
    }
}