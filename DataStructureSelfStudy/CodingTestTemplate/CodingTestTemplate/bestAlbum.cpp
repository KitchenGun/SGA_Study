#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;


//vector<int> solution(vector<string> genres, vector<int> plays) ȥ�ڼ� Ǯ������ Ʋ����
//{
//    vector<int> answer;
//
//    map<int,pair<string,int>> info;
//    map<string, set<int>> genresinfo;
//    int maxindex = 0;
//    for (int i = 0; i < genres.size(); i++)
//    {
//        pair<string,int> temp = { genres[i],i };
//        info.insert({plays[i],temp});
//        maxindex = plays[maxindex]<=plays[i]?i: maxindex;
//        if (genresinfo.find(genres[i]) == genresinfo.end())//��ã�� ���
//        {
//            set<int> a;
//            a.insert(plays[i]);
//            genresinfo.insert({genres[i],a});
//
//        }
//        else//ã�����
//        {
//            genresinfo[genres[i]].insert(plays[i]);
//        }
//    }
//
//
//    //���� ���� Ƚ���� ���� ���� ���� ����
//    answer.push_back(info[plays[maxindex]].second);
//
//    //�帣�� ��
//    string gen = info[plays[maxindex]].first;
//    info.erase(plays[maxindex]);
//
//    //�ش��帣 ���� ������ ����
//    if (genresinfo[gen].size() > 0)
//    {
//        set<int>::iterator iter = genresinfo[gen].end();
//        int a = info[*--iter].second;
//        answer.push_back(a);
//        info.erase(a);
//    }
//
//    genresinfo.erase(gen);
//
//    //���� �帣
//    
//    for (map<int, pair<string, int>>::iterator iter = --info.end(); iter != info.begin(); --iter)
//    {
//        pair<string, int> temp = (*iter).second;
//        if (gen != temp.first)
//        {
//            gen = temp.first;
//            break;
//        }
//    }
//
//    answer.push_back(info[*--genresinfo[gen].end()].second);
//
//    //�ش� �帣 ���� ���� ����
//    if (genresinfo[gen].size() > 0)
//    {
//        set<int>::iterator iter = --(genresinfo[gen].end());
//        int a = info[*iter].second;
//        answer.push_back(a);
//    }
//
//    return answer;
//}



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //�� �帣���� Ƚ������
    map<string, int> music;
    //�� �帣���� �����뷡�� ����� ��������
    map<string, map<int, int>> musiclist;

    for (int i = 0; i < genres.size(); i++)
    {
        music[genres[i]]+=plays[i];
        musiclist[genres[i]][i] =plays[i];
    }



    while (!music.empty())
    {
        string gen;
        int max =0;
        for (auto temp : music)
        {
            if (max < temp.second)
            {
                gen = temp.first;
                max = temp.second;
            }

        }
        for (int i = 0; i < 2; i++)
        {
            int val = 0, ind = -1;
            //�뷡�߿��� ���ϳ����� ã��
            for (auto ml : musiclist[gen])
            {
                if (val < ml.second) 
                {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            if(ind!=-1)
            {
                answer.push_back(ind);
                musiclist[gen].erase(ind);
            }
        }
        music.erase(gen);
    }
    return answer;
}



int main()
{
    vector<int> answer;

    answer = solution({"a","classic", "pop", "classic", "classic", "pop"},{3100,500,  600, 150, 800, 2500});

    for (auto temp : answer)
    {
        cout<< temp <<endl;
    }
}