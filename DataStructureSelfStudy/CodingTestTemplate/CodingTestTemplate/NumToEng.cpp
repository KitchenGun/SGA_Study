#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int start = 0;
	string subString;
	vector<string> nums = { "zero" ,"one","two" ,"three","four","five","six","seven","eight","nine" };

	for (int j = 0; j < s.size(); j++)
	{
		if(s[j]<'0'||s[j]>'9')
			subString.push_back(s[j]);
		else
		{
			start = j+1;
		}
		if (subString.size() >= 3)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (subString == nums[i])
				{
					s.replace(s.begin() + start, s.begin() + j + 1, to_string(i));
					j = start;
					start = j+1;
					subString = "";
					break;
				}
			}
		}
	}

	answer = stoi(s);


	return answer;
}


int main()
{
    cout<<solution("one4seveneight");
}