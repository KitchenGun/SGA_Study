#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int result = 0;

	getline(cin,s);

	for (char temp : s)
	{
		if (temp == ' ')
			result++;
	}
	
	if (s[0] == ' ')
		result--;
	if (s[s.length() - 1] == ' ')
		result--;
	
	cout << ++result;
	
}