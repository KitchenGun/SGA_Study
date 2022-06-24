#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string temp)
{
	if (temp.empty() || temp.size() % 2 == 1)
		return false;
	stack<char> stk;
	for (int j = 0; j < temp.size(); j++)
	{
		if (temp[j] == '(')
			stk.push('(');
		else
		{
			if (stk.empty())
				return false;
			else if (stk.top() == '(')
				stk.pop();
		}
	}
	if (stk.empty())
		return true;
	else
		return false;
}


int main()
{
	int n =0;
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		string temp;

		cin>>temp;

		cout<<(check(temp)?"YES":"NO")<<endl;
	}
}