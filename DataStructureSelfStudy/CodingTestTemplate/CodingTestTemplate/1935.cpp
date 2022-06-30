#include<iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> alph (26,0);
	string s;
	stack<double>nums;
	double result=0;
	
	cin>>n>>s;

	for (int i=0;i<n;i++)
	{
		cin>>alph[i];
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			nums.push(alph[s[i]-'A']);
		}
		else
		{
			double b = nums.top();
			nums.pop();
			double a = nums.top();
			nums.pop();

			if (s[i] == '+')
			{
				result=a+b;
			}
			else if (s[i] == '-')
			{
				result = a - b;
			}
			else if (s[i] == '*')
			{
				result = a * b;
			}
			else if (s[i] == '/')
			{
				result = a / b;
			}
			nums.push(result);
		}
	}
	cout << fixed;
	cout.precision(2);

	cout<<nums.top()<<endl;
}