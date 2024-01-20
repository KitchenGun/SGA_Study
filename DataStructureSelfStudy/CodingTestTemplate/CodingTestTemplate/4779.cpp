#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// 코틀린 스노우플레이크 프랙탈을 생성하는 함수
void LineMaker(int n) 
{
    int size = pow(3,n-1);
    // N = 0 인 경우 "-" 출력
    if (n == 0) 
    {
        cout << "-";
        return;
    }

    LineMaker(n - 1);
    for (int i = 0; i < size; i++) 
    {
        cout << " ";
    }
    LineMaker(n - 1);
}

int main() 
{
    int N;
    // N을 입력받는다
    while (cin >> N)
    {
        LineMaker(N);
        cout << "\n";
    }
    return 0;
}