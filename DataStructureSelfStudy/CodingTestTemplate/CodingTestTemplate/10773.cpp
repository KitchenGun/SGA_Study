#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;

	int count =0;
	cin>>count;


	for(int i=0;i<count;i++)
	{
		int temp=0;
		cin>>temp;

		if(temp!=0)
		{
			s.push(temp);
		}
		else
		{
			s.pop();
		}
	}


	int result = 0;

	while(!s.empty())
	{
		int temp =0;
		temp=s.top();
		result+=temp;
		s.pop();
	}
	cout<<result;

}