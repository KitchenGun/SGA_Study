#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//vector<int> solution(vector<int> prices) //stack queue를 안쓰고 푸는 법
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

//스택을 사용해서 푸는법   속도 차이도 별로 다르지 않아서 스택 아닌 처음 방식으로 풀어도 정답이였다.
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