#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums1={4,5,6,0,0,0};
    int m = 3;
    vector<int> nums2 = { 1,2,3 };
    int n =3;




    int num1idx = m - 1;
    int num2idx = n - 1;
    int widx = nums1.size() - 1;

    if (num2idx < 0)
        return 0;
    while (num1idx >= 0 && num2idx >= 0)
    {
        if (nums2[num2idx] <= nums1[num1idx])
        {
            nums1[widx] = nums1[num1idx];
            widx--;
            num1idx--;
        }
        else
        {
            nums1[widx] = nums2[num2idx];
            widx--;
            num2idx--;
        }
    }
    while (num2idx >= 0)
    {
        nums1[widx] = nums2[num2idx];
        widx--;
        num2idx--;
    }

    return 0;
}