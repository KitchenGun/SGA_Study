#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<int,pair<string,int>> info;
    map<string, set<int>> genresinfo;
    vector<bool> check(genres.size(),false);

    for (int i = 0; i < genres.size(); i++)
    {
        pair<string,int> temp = { genres[i],i };
        info.insert({plays[i],temp});
        if (genresinfo.find(genres[i]) == genresinfo.end())//못찾은 경우
        {
            set<int> a;
            a.insert(plays[i]);
            genresinfo.insert({genres[i],a});

        }
        else//찾은경우
        {
            genresinfo[genres[i]].insert(plays[i]);
        }
    }
    //가장 들은 횟수가 많은 것을 집어 넣음
    answer.push_back(info[genres.size()-1].second);
    check[info[genres.size() - 1].second] = true;
    //미해결
    https://school.programmers.co.kr/learn/courses/30/lessons/42579?language=cpp
    return answer;
}

int main()
{
    vector<int> answer;

    answer = solution({"classic", "pop", "classic", "classic", "pop"},{500, 600, 150, 800, 2500});

    for (auto temp : answer)
    {
        cout<< temp <<endl;
    }
}