#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(vector<string> p)
{
	long long answer =0;

	int size = p.size()-1;
	int result =0;

	for (int i = 0; i <= size; i++)
	{
		size = p.size()-1;
		if (p[i] == "+")
		{
			result = stoi(p[i-2])+stoi(p[i-1]);
			for (int j = 0; j < 2; j++)
			{
				p.erase(p.begin()+i-1);
			}
			p[i-2] = to_string(result);
			i=0;
		}
		else if (p[i] == "*")
		{
			result = stoi(p[i - 2]) * stoi(p[i - 1]);
			for (int j = 0; j < 2; j++)
			{
				p.erase(p.begin() + i - 1);
			}
			p[i - 2] = to_string(result);
			i = 0;
		}
		if (p.size()==1)
		{
			answer = stoll(p[0]);
			return answer;
			break;
		}
	}

}


int main()
{
	string a ="12";
	//11+11+*
	//211+*
	//22*
	//4

	cout<< solution({"1","1" ,"+","1" ,"1","+","*" });

}