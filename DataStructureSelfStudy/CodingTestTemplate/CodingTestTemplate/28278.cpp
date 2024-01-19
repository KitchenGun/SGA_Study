#include <iostream>
#include <stack>
using namespace std;

int count = 0;
int N = 0;
stack<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	cin>>count;
	for(int i = 0; i < count; i++)
	{
		int target = 0;
		cin>>target;
		if (target == 1)
		{
			cin>>N;
			s.push(N);
		}
		else if (target == 2)
		{
			if (s.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (target == 3)
		{
			printf("%d\n", (int)s.size());
		}
		else if (target == 4)
		{
			printf("%d\n",(s.empty() ? 1 : 0));
		}
		else
		{
			printf("%d\n", (s.empty() ? -1 : s.top()));
		}
	}
}