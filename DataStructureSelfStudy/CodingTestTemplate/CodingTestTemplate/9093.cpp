#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int n;

	cin>>n;
	cin.ignore();
	for (int i = 0; i <= n; i++)
	{
		string temp;
		getline(cin,temp);
		temp+=' ';
		stack<char> Reverse;
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == ' ')
			{
				while (!Reverse.empty())
				{
					cout<<Reverse.top();
					Reverse.pop();
				}
				cout<<' ';
			}
			else
			{
				Reverse.push(temp[j]);
			}
		}
	}
}