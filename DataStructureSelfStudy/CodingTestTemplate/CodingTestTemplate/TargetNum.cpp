#include <iostream>
#include <vector>
using namespace std;

int Target;
int Ans;

void dfs(int index, vector<int> nums,int result)
{
	if (index == nums.size())
	{
		if (result == Target)
		{
			Ans++;
			return;
		}
	}
	else
	{
		dfs(index+1,nums,result+nums[index]);
		dfs(index + 1, nums, result - nums[index]);
	}
}

int solution(vector<int> numbers, int target)
{
	Ans = 0;
	Target = target;
	dfs(0,numbers,0);
	return Ans;
}


int main()
{
	cout<<solution({ 4, 1, 2, 1 }, 2);
}