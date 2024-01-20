#include <iostream>
#include <stack>	
#include <queue>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	queue<int> q;
	stack<int> s;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	
	int num = 1;
	while (!q.empty())
	{
		if (q.front() == num)
		{
			v.push_back(q.front());
			q.pop();
			num++;
		}
		else if (!s.empty() && s.top() == num)
		{
			v.push_back(s.top());
			s.pop();
			num++;
		}
		else
		{
			s.push(q.front());
			q.pop();
		}
	}
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	bool possible = true;

	for (int i = 0; i < v.size() - 1; i++) 
	{
		if (v[i] > v[i + 1]) {
			possible = false;
			break;
		}
	}
	if(possible)
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;
}