#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesMap;

    for (auto& clothInfo : clothes)
    {
        ++clothesMap[clothInfo[1]];//���� �̸��� �ʿ���� ���� ������ �ʿ��ϱ⶧���� ������ map�� ����
    }

    for (auto& iter : clothesMap)
    {
        answer *= (iter.second + 1);//���Դ� ��쵵 �����Ͽ��� ����
    }

    return --answer;//�ƹ��͵� ���Դ� ���� ���⶧���� �̷��� ���
}

int main()
{

    cout<<solution({{"yellow_hat", "headgear"},{"yellow_hat", "headgear"},{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"},{"blue_sunglasses", "eyewear"},{"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}} );

}