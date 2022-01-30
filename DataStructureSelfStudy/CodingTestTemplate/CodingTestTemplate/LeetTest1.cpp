#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;



int romanToInt(string s) 
{
	unordered_map<char,int> RomanNum = 
	{
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000}
	};

	int result=0;
	for (int i = 0; i < s.size(); i++)
	{
		if(i+1<s.size())
		{
			if (RomanNum.find(s[i])->second < RomanNum.find(s[i + 1])->second)
			{
				result += RomanNum.find(s[i + 1])->second - RomanNum.find(s[i])->second;
				i++;
			}
			else
			{
				result += RomanNum.find(s[i])->second;
			}
		}
		else
		{
			result += RomanNum.find(s[i])->second;
		}
	}

	return result;
}


int main()
{
	//cout << romanToInt("MDCXCV");
	cout<<romanToInt("LVIII");
}