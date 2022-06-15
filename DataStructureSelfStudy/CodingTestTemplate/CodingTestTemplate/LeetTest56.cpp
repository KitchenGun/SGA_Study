#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{

    vector<vector<int>>nums{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = nums.size();
 
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0, left, right; i < n;)
    {
        left = nums[i][0], right = nums[i++][1];
        while (i < n && nums[i][0] <= right)
            right = max(right, nums[i++][1]);
        res.push_back({ left, right });
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout<< res[i][0]<< res[i][1]<<endl;
    }
	
	return 0;
}