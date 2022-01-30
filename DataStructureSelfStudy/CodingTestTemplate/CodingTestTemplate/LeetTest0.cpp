#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int x)
{
	string a = to_string(x);
	reverse(a.begin(), a.end());

	if (x == stoll(a))
	{
		return true;
	}
	else 
		return false;
}

int main()
{
	cout<<isPalindrome(1234567899);
}