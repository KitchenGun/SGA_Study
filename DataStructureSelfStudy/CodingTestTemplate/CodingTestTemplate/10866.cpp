#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int n =0;
	cin>>n;
	deque<int> dq;
	for (int i=0;i<n;i++)
	{
		string order;
		cin>>order;

		if (order == "push_front")
		{
			int t;
			cin>>t;
			dq.push_front(t);
		}
		else if (order == "push_back")
		{
			int t;
			cin >> t;
			dq.push_back(t);
		}
		else if (order == "pop_front")
		{
			int t;
			if (dq.empty())
			{
				cout<<-1<<endl;
			}
			else
			{
				t = dq.front();
				dq.pop_front();
				cout << t << endl;
			}
		}
		else if (order == "pop_back")
		{
			int t;
			if (dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				t = dq.back();
				dq.pop_back();
				cout << t << endl;
			}
		}
		else if (order == "size")
		{
			cout<<dq.size()<<endl;
		}
		else if (order == "empty")
		{
			cout<<(dq.empty()?1:0)<<endl;
		}
		else if (order == "front")
		{
			int t;
			if (dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				t = dq.front();
				cout << t << endl;
			}
		}
		else if (order == "back")
		{
			int t;
			if (dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				t = dq.back();
				cout << t << endl;
			}
		}
	}
}