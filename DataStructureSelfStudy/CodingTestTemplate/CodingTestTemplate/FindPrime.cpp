#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int answer;

bool isPrime(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}


int solution(string numbers)
{
    answer = 0;
    vector<char> arr;
    vector<int> nums;
    for (int temp : numbers)
    {
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());

    do 
    {
        string temp;
        for (int i = 0; i < arr.size(); i++)
        {
            temp+=(arr[i]);
            nums.push_back(stoi(temp));
        }
        
    }while(next_permutation(arr.begin(),arr.end()));

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()),nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (isPrime(nums[i]))
        {
            answer++;
        }
    }

    return answer;
}



int main()
{
    cout<<solution("011");
}