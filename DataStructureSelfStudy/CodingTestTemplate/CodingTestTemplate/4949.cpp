#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str;

	do
	{
		getline(cin, str);
		stack<char> checklist;
		bool check = true;
		if (str == ".")
		{
			break;
		}

		for(char temp : str)
		{
			if(temp == '['||temp=='(')
			{
				checklist.push(temp);
			}
			else if(temp == ')')
			{
				if (!checklist.empty() && checklist.top() == '(') {
					checklist.pop();
				}
				else 
				{
					check = false;
					cout<<"no"<<endl;
					break;
				}
			}
			else if (temp == ']') {
				if (!checklist.empty() && checklist.top() == '[') {
					checklist.pop();
				}
				else {
					check = false;
					cout << "no" << endl;
					break;
				}
			}
		}

		if(check)
		{
			if(checklist.empty())
			{
				cout<<"yes"<<endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	while(str != ".");
	
}