#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>nums = {1,2,4,5,7,6};//?

    int left = 0;
    int right = nums.size() - 1;

    if (nums.size() <= 1)
    {
        return 0;
    }
    while (left < right)
    {
        int pivot = (left + right) / 2;
        int num = nums[pivot];
        int nextnum = nums[pivot + 1];
        if (num < nextnum)
        {
            left = pivot + 1;
        }
        else
        {
            right = pivot;
        }
    }
    cout<<left;
    return left;
}