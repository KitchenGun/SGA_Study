#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

string answer;
stack<char> Re;

void stackPop()
{
	while (!Re.empty())
	{
		answer.push_back(Re.top());
		Re.pop();
	}
}


int main()
{
	vector<char> St;
	string s;
	getline(cin,s);
	s.push_back(' ');
	bool isRe = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			isRe = false;
			stackPop();
			answer.push_back('<');

		}
		else if(s[i] == '>')
		{
			isRe = true;
			answer.push_back('>');
		}
		else if (s[i] == ' ')
		{
			stackPop();
			answer.push_back(' ');
		}
		else
		{
			if (isRe)
			{
				Re.push(s[i]);
			}
			else
			{
				answer.push_back(s[i]);
			}

		}
	}
	cout<<answer;
}