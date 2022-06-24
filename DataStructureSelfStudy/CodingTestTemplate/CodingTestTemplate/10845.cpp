#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n =0;
	cin>>n;

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		string order;
		cin>>order;

		if (order == "push")
		{
			int temp;
			cin>>temp;
			q.push(temp);
		}
		else if (order == "pop")
		{
			int temp;
			if(!q.empty())
			{
				temp=q.front();
				q.pop();
				cout<<temp<<endl;
			}
			else
			{
				cout<< -1 << endl;
			}
		}
		else if (order == "size")
		{
			cout<<q.size()<<endl;
		}
		else if (order == "empty")
		{
			cout<<(q.empty()?1:0)<<endl;
		}
		else if (order == "front")
		{
			int temp;
			if (!q.empty())
			{
				temp = q.front();
				cout << temp << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (order == "back")
		{
			int temp;
			if (!q.empty())
			{
				temp = q.back();
				cout << temp << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}