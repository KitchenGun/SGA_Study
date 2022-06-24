#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	stack<char> left;
	stack<char> right;
	int n =0;

	cin>>s;

	if(!s.empty())
	{
		for (int i = 0; i < (int)s.size(); i++)
		{
			left.push(s[i]);
		}
	}
	
	cin>>n;
	string order;
	for (int i = 0; i < n; i++)
	{
		cin>>order;

		if (order == "L")
		{
			if (!left.empty())
			{
				char temp =left.top();
				left.pop();
				right.push(temp);
			}
		}
		else if (order == "D")
		{
			if (!right.empty())
			{
				char temp = right.top();
				right.pop();
				left.push(temp);
			}
		}
		else if (order == "B")
		{
			if (!left.empty())
			{
				left.pop();
			}
		}
		else
		{
			char addch;
			cin>>addch;
			left.push(addch);
		}
		
	}
	s="";
	int i=0;
	while (!left.empty())
	{
		s.push_back(left.top());
		left.pop();
	}
	reverse(s.begin(),s.end());
	i=0;
	while (!right.empty())
	{
		s.push_back(right.top());
		right.pop();
	}
	cout<<s;
}