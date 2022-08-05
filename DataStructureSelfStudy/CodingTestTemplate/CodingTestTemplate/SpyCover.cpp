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
        ++clothesMap[clothInfo[1]];//옷의 이름은 필요없고 옷의 종류만 필요하기때문에 종류로 map을 제작
    }

    for (auto& iter : clothesMap)
    {
        answer *= (iter.second + 1);//안입는 경우도 포함하여서 연산
    }

    return --answer;//아무것도 안입는 경우는 없기때문에 이렇게 계산
}

int main()
{

    cout<<solution({{"yellow_hat", "headgear"},{"yellow_hat", "headgear"},{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"},{"blue_sunglasses", "eyewear"},{"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}} );

}