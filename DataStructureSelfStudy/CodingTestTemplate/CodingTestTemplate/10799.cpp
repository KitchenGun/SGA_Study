#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string s;
	stack<char> stk;
	getline(cin,s);
	int count =0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stk.push('(');
		}
		else 
		{
			if (s[i - 1] == '(')
			{
				stk.pop();
				count+=stk.size();
			}
			else if(s[i - 1] == ')')
			{
				stk.pop();
				count++;
			}
		}
	}
	cout<<count;
}