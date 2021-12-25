#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//string n;
	//int length = 0;
	//int result = 0;
	//cin >> length;
	//cin >> n;
	//for (char temp : n)
	//{
	//	result += temp - '0';
	//}
	//cout << result;

	vector<int> Alphabet(26,-1);
	string word;

	cin >> word;

	for (int i=0;i<word.length();i++)
	{
		char temp = word[i];
		if(Alphabet[temp - 'a'] ==-1)
			Alphabet[temp - 'a']=i;
	}
	for (int temp : Alphabet)
	{
		cout << temp << " ";
	}
}