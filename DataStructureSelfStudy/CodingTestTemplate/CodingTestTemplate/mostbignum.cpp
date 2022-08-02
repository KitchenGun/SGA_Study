#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//stl을 사용할 경우 시간 초과
//string solution(vector<int> numbers) 
//{
//    string answer = "";
//    
//    vector<long long> nums;
//    sort(numbers.begin(),numbers.end());
//    do
//    {
//        string temp;
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            temp += to_string(numbers[i]);
//            nums.push_back(stoll(temp));
//        }
//    }
//    while(next_permutation(numbers.begin(), numbers.end()));
//
//    sort(nums.begin(),nums.end());
//    
//    answer=to_string(nums[nums.size()-1]);
//
//    return answer;
//}

bool comp(const string &a,const string &b)
{
    return a+b>b+a;
}


string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> tmp;
	for (int i = 0; i < numbers.size(); i++)
	{
		tmp.push_back(to_string(numbers[i]));
	}

	sort(tmp.begin(), tmp.end(), comp);

	for (int i = 0; i < tmp.size(); i++)
	{
		answer += tmp[i];
	}
	if (answer[0] == '0') 
		return "0";
	return answer;
}



int main()
{
    cout<<solution({6, 10, 2});
}