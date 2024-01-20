#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// ��Ʋ�� ������÷���ũ ����Ż�� �����ϴ� �Լ�
void LineMaker(int n) 
{
    int size = pow(3,n-1);
    // N = 0 �� ��� "-" ���
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
    // N�� �Է¹޴´�
    while (cin >> N)
    {
        LineMaker(N);
        cout << "\n";
    }
    return 0;
}