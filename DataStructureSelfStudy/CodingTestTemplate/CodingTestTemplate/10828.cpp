#include<iostream>
#include <stack>

using namespace std;
int main()
{
	int n =0;
	cin>>n;
	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		string order;
		int num;
		cin>>order;
		if(order=="push")
		{
			cin>>num;
			stk.push(num);
		}
		else if(order == "pop")
		{
			if(stk.empty())
				cout<<-1<<endl;
			else
			{
				cout<<stk.top()<<endl;
				stk.pop();
			}
		}
		else if (order == "size")
		{
			cout<<stk.size()<<endl;
		}
		else if (order == "empty")
		{
			if (stk.empty())
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else if (order == "top")
		{
			if (stk.empty())
				cout << -1 << endl;
			else
			{
				cout << stk.top() << endl;
			}
		}

	}
}