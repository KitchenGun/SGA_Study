#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

void Splite(string temp,string& Target, string& Reporter)
{
    bool toggle = true;
    for (char tempch : temp)
    {
        if (tempch != ' ' && toggle)
        {
            Reporter.push_back(tempch);
        }
        else if (tempch != ' ' && !toggle)
        {
            Target.push_back(tempch);
        }
        else
        {
            toggle = false;
        }
    }
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size());
    map<string,set<string>> reportData;

    for (string temp : id_list)
    {
        set<string> s;
        reportData.insert({temp,s});
    }

    for (string temp : report)
    {
        string Reporter;
        string Target;
        
        Splite(temp,Reporter,Target);

        reportData[Reporter].insert(Target);
    }

    for (int i=0;i<id_list.size();i++)
    {
        if (reportData[id_list[i]].size() >= k)
        {
            set<string>::iterator it = reportData[id_list[i]].begin();
            for(it;it != reportData[id_list[i]].end();it++)
            {
                for (int i = 0; i < id_list.size(); i++)
                {
                    if(*it==id_list[i])
                    {
                        answer[i]++;
                        break;
                    }
                }
            }


        }
    }

    return answer;
}


int main()
{
    vector<int> an = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"},2);

    for (int i = 0; i < an.size(); i++)
    {
        cout<<an[i];
    }
}