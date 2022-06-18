#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cfloat>

using namespace std;

string solution(vector<int> nums, string hand)
{
    string answer = "";
    int left = 10;
    int right = 12;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1 || nums[i] == 4 || nums[i] == 7)
        {
            answer.push_back('L');
            left = nums[i];
        }
        else if (nums[i] == 3 || nums[i] == 6 || nums[i] == 9)
        {
            answer.push_back('R');
            left = nums[i];
        }
        else
        {
            int leftDistx = (left % 3) - 1;
            int leftDisty = left / 3;
            int rightDistx = (right % 3) - 1;
            int rightDisty = right / 3;

            if (nums[i] == 0)
                nums[i] = 11;
            int targetDistx = (nums[i] % 3) - 1;
            int targetDisty = nums[i] / 3;

            float leftDist;
            float rightDist;

            leftDist = abs(targetDistx- leftDistx)+abs(targetDisty - leftDisty);
            rightDist = abs(targetDistx - rightDistx) + abs(targetDisty - rightDisty);

            if (fabs(leftDist - rightDist) <= FLT_EPSILON)
            {
                if (hand.compare("left"))
                {
                    left = nums[i];
                    answer.push_back('L');
                }
                else
                {
                    right = nums[i];
                    answer.push_back('R');
                }
            }
            else
            {
                answer.push_back((leftDist<rightDist)?'L':'R');
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> nums ={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    cout<<solution(nums,hand);
}