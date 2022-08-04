#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//처음 풀이
//int solution(vector<int> nums)
//{
//    int answer = 0;
//    int n = nums.size()/2;
//    sort(nums.begin(), nums.end());
//    nums.erase(unique(nums.begin(),nums.end()),nums.end());
//
//    answer = nums.size();
//
//    if (n < answer)
//    {
//        return n;
//    }
//
//    return answer;
//}

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(),nums.end());

    return (s.size()>(nums.size()/2)?nums.size()/2: s.size());
}



int main()
{
    cout<<solution({3, 1, 2, 3});
}