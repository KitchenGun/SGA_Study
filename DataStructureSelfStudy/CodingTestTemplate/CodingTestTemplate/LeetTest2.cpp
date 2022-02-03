#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
	string result ="";
	bool isCommon = true;
	char temp= strs[0][0];//ù�ܾ� ù���ĺ��� �Է�
	
	int i = 0;//�ܾ� ����
	int j = 0;//�ܾ� ��ġ
	
	while(isCommon)
	{
		if (strs[i].size() <= j)
		{
			return result;
		}

		if (i == 0)
		{
			temp=strs[i][j];
		}
		if (strs[i][j] != temp)
		{
			isCommon=false;
		}


		if (!isCommon)
		{
			return result;
		}
		if (i == strs.size() - 1)
		{
			i = 0;
			j++;
			result.push_back(temp);
		}
		else
		{
			i++;
		}
	}

	return result;
}


int main()
{
	cout<<longestCommonPrefix(vector<string>{"cog", "cacecar", "car"});
}