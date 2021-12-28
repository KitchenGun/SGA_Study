#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (s.empty() == false)
	{
		int top = s.top();
		printf("Top : %d\n", top);

		s.pop();
	}
}