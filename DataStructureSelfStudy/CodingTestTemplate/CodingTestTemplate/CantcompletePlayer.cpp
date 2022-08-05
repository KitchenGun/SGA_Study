#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string,int> map;

    for (auto temp : participant)
    {
        map.insert({temp,0});
        map[temp]++;
    }

    for (auto temp : completion)
    {
       map[temp]--;
    }

    for (auto temp : participant)
    {
        if(map[temp]>=1)
            return temp;
    }
}

int main()
{
	cout<< solution({"leo", "kiki", "eden"}, {"kiki", "eden"});
}