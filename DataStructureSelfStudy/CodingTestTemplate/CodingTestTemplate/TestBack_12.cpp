#include <iostream>
using namespace std;

int main()
{
	string s;
	int result=0;

	cin >> s;


	for (char temp : s)
	{
		int tempn = temp - 'A';
		if (tempn < 3)//c
		{
			result += 3;
		}
		else if (tempn < 6)//f
		{
			result += 4;
		}
		else if (tempn < 9)//i
		{
			result += 5;
		}
		else if (tempn < 12)//l
		{
			result += 6;
		}
		else if (tempn < 15)//o
		{
			result += 7;
		}
		else if (tempn < 19)//s
		{
			result += 8;
		}
		else if (tempn < 22)//v
		{
			result += 9;
		}
		else if (tempn < 26)//z
		{
			result += 10;
		}
	}
	cout << result;
}