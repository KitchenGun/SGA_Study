#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
    string name = "ABABAAAAABA";
    string temp(name.length(), 'A');
    int answer = 0;
    for (int i = 0; i<name.length();++i)
    {
        int min = 0;
        //�� �Ʒ� �̵�

        if (name[i] == 'A')
        {
            int target = i;
            while (target < name.length() && name[target] == 'A')
                target += 1; //A�θ� �̷���� ���ڿ� ã��
            int left = i == 0 ? 0 : i - 1; //ã�� ���ڿ� ���ʿ����� �̵�Ƚ��
            int right = name.length() - target;  //ã�� ���ڿ� �����ʿ����� �̵�Ƚ��
            shift = min(shift, left + right + min(left, right)); //���� ������ ã��
        }
        
        if (name[name.length()-1] != (temp[i]))
            ++answer;

        temp[i] - 'A' > 'Z' - temp[i] + 1 ? answer += temp[i] - 'A' : answer += 'Z' - temp[i] + 1;
    }
    
    cout << answer;
}