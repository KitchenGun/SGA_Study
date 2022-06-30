#include<iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	string s;
	string result;

	stack<char>opers;
	cin>>s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			result.push_back(s[i]);
		}
		else
		{
			if(s[i] == '(')
				opers.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!opers.empty() && (opers.top() == '*' || opers.top() == '/'))
				{
					result.push_back(opers.top());
					opers.pop();
				}
				opers.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!opers.empty() && opers.top() != '(')
				{
					result.push_back(opers.top());
					opers.pop();
				}
				opers.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (opers.top() != '(')
				{
					result.push_back(opers.top());
					opers.pop();
				}
				opers.pop();
			}
		}
	}

	while (!opers.empty())
	{
		result.push_back(opers.top());
		opers.pop();
	}

	cout<<result;
}