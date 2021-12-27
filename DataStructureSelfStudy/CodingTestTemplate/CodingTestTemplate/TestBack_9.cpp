#include <iostream>
using namespace std;
#include <vector>


int main()
{
	vector<int> CountArray(26, 0);
	pair<int, int> result = {0,0};
	string s;

	cin >> s;

	for (char temp : s)
	{
		int count=0;
		if (temp <= 'Z')
		{
			count = temp-'A';
		}
		else
		{
			count = temp-'a';
		}
		CountArray[count]++;
	}

	bool isSame = false;
	for (int i = 0; i < 26; i++)
	{
		if (result.second < CountArray[i])
		{
			result = { i,CountArray[i] };
			isSame = false;
		}
		else if (result.second == CountArray[i])
		{
			isSame = true;
		}
	}
	if (isSame)
		cout << "?";
	else
		cout << (char)('A' + result.first);
}