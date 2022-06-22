#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long facto(long long num)
{
    if (num == 1)
        return 1;
    return facto(num - 1) * num;
}

vector<int> solution(int n, long long k)
{
    vector<int> answer, vt;
    for (int i = 1; i <= n; i++) {
        vt.push_back(i);
    }
    if (k == 1)//k�� 1�� ��� ���� vt�״��
        return vt;

    k -= 1;
    long long pre = facto(n);
    long long mod, div;

    while (vt.size() != 1) {
        pre /= n;
        mod = k % pre;
        div = k / pre;
        answer.push_back(vt[div]);
        vt.erase(vt.begin() + div);
        k = mod;
        n--;
    }
    answer.push_back(vt[0]);

    return answer;
}


int main()
{
    for (int temp : solution(3, 5))
    {
        cout<<temp;
    }
}