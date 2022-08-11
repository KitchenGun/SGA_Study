#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;


//int TimeToVal(string s)//string 시간을 int로 변환
//{
//    int value = 0;
//    value += (s[0] - '0') * 10 * 60 * 100;
//    value += (s[1] - '0') * 60 * 100;
//    value += (s[3] - '0') * 10 * 100;
//    value += (s[4] - '0') * 100;
//    value += (s[6] - '0') * 10;
//    value += (s[7] - '0');
//   return value;
//}
//
//
//int main()
//{
//    int result=0;
//
//    vector<int> time(3);
//    string  completeTimeStr;
//    int  completeTimeInt;
//    //input
//    for (int i = 0; i < 3; i++)
//    {
//        string temp;
//        int value=0;
//        cin >> temp;
//        time[i] = TimeToVal(temp);
//    }
//    cin >> completeTimeStr;
//    completeTimeInt = TimeToVal(completeTimeStr);
//
//    //compare
//    for (int i = 0; i < 3;i++)
//    {
//        if (completeTimeInt<=time[i])
//        {
//            result++;
//        }
//    }
//
//    //output
//    cout << result;
//}


int main()
{
	bool isPossible = true;
	string password;
	vector<char> specialChar ={'!','@', '#', '$', '%', '^','&','*'};

	getline(cin, password);

	//type check
	{
		vector<bool> checklist(4,false);
		for (char temp : password)
		{
			if (temp >= 'A' && temp <= 'Z')//1
			{
				checklist[0] = true;
			}
			if (temp >= 'a' && temp <= 'z')//2
			{
				checklist[1] = true;
			}
			if (temp >= '0' && temp <= '9')//3
			{
				checklist[2] = true;
			}
			
			for (char specialc : specialChar)//4
			{
				if (specialc == temp)
				{
					checklist[3] = true;
					break;
				}
			}
		}
		int result = 0;
		//check checklist
		for (bool check : checklist)
		{
			if (check == true)
			{
				result++;
			}
		}

		if (result < 3)
		{
			cout<<1;
			isPossible = false;
		}
	}


	//size check
	if (password.size() < 8 || password.size() >15)
	{
		cout<<2;
		isPossible = false;
	}

	//ovelap check
	{
		string temp = password;
		char target = temp[0];
		bool isOverlap=false;
		for (int i = 1; i < temp.size()-1; i++)
		{
			if (target == temp[i])
			{
				if (target == temp[i + 1])
				{
					isOverlap = true;
					break;
				}
			}
			else
			{
				target = temp[i];
			}
		}
		if (isOverlap)
		{
			cout<<3;
			isPossible = false;
		}

	}

	//special exception
	{
		for (char temp : password)
		{
			bool isPass = false;
			
			if (temp >= 'A' && temp <= 'Z')//1
			{
				isPass = true;
			}
			else if (temp >= 'a' && temp <= 'z')//2
			{
				isPass = true;
			}
			else if (temp >= '0' && temp <= '9')//3
			{
				isPass = true;
			}
			else
			{
				for (char specialc : specialChar)//4
				{
					if (specialc == temp)
					{
						isPass = true;
						break;
					}
				}

				if (isPass == false)
				{
					cout << 4;
					isPossible = false;
					break;
				}
			}
		}
	}

	//if is possible
	if(isPossible)
		cout<<0;
	return 0;
}

/*
int main()
{
	map<int,pair<int,int>> data;
	int user;
	int datacount;
	cin>>user;
	cin>>datacount;

	for (int i = 0; i < datacount; i++)
	{
		int time;
		int user;
		int complete;

		cin>>time>>user>>complete;

		if (data.find(user) == data.end())//처음 들어오는 유저 데이터
		{
			//완주 관련 오류
			if (complete == 1)
			{
				cout<< "NO";
				return 0;
			}
			data[user] = { time,complete };
		}
		else//기존의 유저 데이터 업데이트
		{
			//완주 관련 오류 
			if (complete == 0 && data[user].second == 0)
			{
				cout << "NO";
				return 0;
			}
			else if (complete == 1 && data[user].second == 1)
			{
				cout << "NO";
				return 0;
			}
			//속도 관련 데이터
			if (complete == 1)
			{
				if (time - data[user].first < 60)
				{
					cout << "NO";
					return 0;
				}
			}
			data[user] = { time,complete };
		}
			
	}


	for (auto temp : data)
	{
		if(temp.second.second==0)
		{
			cout << "NO";
			return 0;
		}
	}


	cout<<"YES";
	return 0;

}*/

/*
int bfs(const vector<vector<int>>room, vector<int>& check,int start)
{
	int redroom=0;
	queue<int> q;
	q.push(start);
	check[start] = 1;
	int curcolor = 1;
	while (!q.empty())
	{
		int cur = q.front();
		curcolor = check[cur];

		q.pop();
		for (auto temp : room[cur])
		{
			if (check[temp] == 0)
			{
				if (curcolor == 1)//빨강일 경우
				{
					check[temp] = 2;
					q.push(temp);
				}
				else// 파랑일 경우
				{
					check[temp] = 1;
					q.push(temp);
				}
			}
		}
	}

	//빨강 방 개수 반환
	for (int temp : check)
	{
		if (temp == 1)
		{
			redroom++;
		}
	}

	return redroom;
}

int main()
{
	int roomcount;
	int adjcount;
	int maxRed=0;
	//input
	cin>> roomcount >> adjcount;
	
	vector<vector<int>> room(roomcount);
	for (int i=0;i<adjcount;i++)
	{
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		room[a].push_back(b);
		room[b].push_back(a);
	}

	//방을 하나씩 넣어서 탐색하기
	for (int i = 0; i < room.size(); i++)
	{
		vector<int> check(roomcount, 0);

		maxRed=max(bfs(room,check,i),maxRed);
	}

	cout<<maxRed;


}*/

/*
bool sortFunc(pair<int, int> a, pair<int, int>b)
{
	return a.second>b.second;
}


int main()
{
	vector<pair<int,int>> normaldata;
	vector<pair<int, int>> notmissdata;
	vector<int> missdata(8,0);
	vector<int> pointdata(8,0);
	set<int> result;
	//input
	for (int i = 0; i < 8; i++)
	{
		int teamID;
		int time;
		cin >> teamID >> time;
		teamID--;
		normaldata.push_back({teamID,time});
		if (time != -1)
		{
			notmissdata.push_back({teamID,time});
		}
		else
		{
			missdata[teamID]++;
		}
	}
	//정렬
	sort(normaldata.begin(),normaldata.end(), sortFunc);
	sort(notmissdata.begin(),notmissdata.end());
	//점수로 변환
	int value = 8;
	for (int i = 0; i < notmissdata.size(); i++)
	{
		pointdata[notmissdata[i].first] += value;
		value--;
	}
	//최고점 찾기
	int max =0;
	for (int i = 0; i < pointdata.size(); i++)
	{
		if(max<pointdata[i])
			max = pointdata[i];
	}
	//최고점 팀 모두 찾기
	vector<int> bestteam;
	for (int i = 0; i < pointdata.size(); i++)
	{
		if (max == pointdata[i])
		{
			bestteam.push_back(i);
		}
	}
	if (bestteam.size() == 1)//동점이 없으면
	{
		result.insert(bestteam[0]+1);
	}
	else//동점이 있을 경우
	{
		bool isFind = false;
		for (auto temp : notmissdata)
		{
			for (int team : bestteam)
			{
				if (temp.first == team)
				{
					result.insert(team+1);
					isFind = true;
				}
			}
			if(isFind)
				break;
		}
	}
	//없는 데이터를 포함하면
	if (!missdata.empty())
	{
		int bestidx = bestteam[0];
		//최고의 팀의 총합 시간을 구함
		int bestteamtime = 0;
		for (auto temp : notmissdata)
		{
			if (temp.first == bestidx)
			{
				bestteamtime+=temp.second;
			}
		}
		for (int i=0;i<8;i++)
		{
			if (missdata[i] > 0)
			{
				int curtime =0;
				for (auto temp : notmissdata)
				{
					if (temp.first == i)
					{
						curtime += temp.second;
					}
				}
				//시간 차이값
				int val = bestteamtime - curtime;
				if (missdata[i] == 1)
				{
					if (val >= 1)
					{
						result.insert(i+1);
					}
				}
				if (missdata[i] == 2)
				{
					if (val >= 3)
					{
						result.insert(i + 1);
					}
				}
				if (missdata[i] == 3)
				{
					if (val >= 6)
					{
						result.insert(i + 1);
					}
				}
				if (missdata[i] == 4)
				{
					if (val >= 10)
					{
						result.insert(i + 1);
					}
				}
			}
		}

	}

	if (notmissdata.empty())
	{
		int idx=0;
		for (int temp : missdata)
		{
			if(temp!=0)
				result.insert(idx+1);
			idx++;
		}
	}

	////-1 전부 99
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		for (auto& temp : data[i])
	//		{
	//			if (temp == -1)
	//			{
	//				totaldata[i] += 99;
	//			}
	//			else
	//			{
	//				totaldata[i] += temp;
	//			}
	//		}
	//	}
	//	addFirst(result, totaldata);
	//}
	//
	////-1 한개씩 1
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		for (auto& temp : data[i])
	//		{
	//			if (temp == -1)
	//			{
	//				totaldata[i] -= 98;
	//				addFirst(result, totaldata);
	//			}
	//			else
	//			{
	//				totaldata[i] += temp;
	//			}
	//		}
	//		for (auto& temp : data[i])
	//		{
	//			if (temp == -1)
	//			{
	//				totaldata[i] += 98;
	//			}
	//		}
	//	}
	//}

	//output
	for (auto temp : result)
	{
		cout << temp;
	}
}
*/