#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(string expression)
{
    long long answer = 0;
    vector<long long> Numlist;
    vector<char> Operlist;

    bool isOperator = false;
    int tempNum = 0;
    int startPoint = 0;
    //string dataȭ
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            if (isOperator)
            {
                Numlist.push_back(tempNum);
                tempNum = 0;
                tempNum += (expression[i] - '0');
                isOperator = false;
            }
            else
            {
                tempNum *= 10;
                tempNum += (expression[i] - '0');
            }
        }
        else if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
        {
            isOperator = true;
            Operlist.push_back(expression[i]);
        }
        if (i == expression.size() - 1)
        {
            Numlist.push_back(tempNum);
        }
    }

    string OperPriority[6] =
    {
        "*+-", "*-+",
        "-*+", "-+*",
        "+-*", "+*-"
    };

    for (int i = 0; i < 6; i++) {
        vector<long long> temp_nums = Numlist;
        vector<char> temp_op = Operlist;
        string pr = OperPriority[i];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < temp_op.size(); k++) {
                if (pr[j] == temp_op[k]) {
                    if (pr[j] == '*') {
                        temp_nums[k] = temp_nums[k] * temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '+') {
                        temp_nums[k] = temp_nums[k] + temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    else if (pr[j] == '-') {
                        temp_nums[k] = temp_nums[k] - temp_nums[k + 1];
                        temp_nums.erase(temp_nums.begin() + k + 1);
                    }
                    temp_op.erase(temp_op.begin() + k--);
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    }
    return answer;
}



int main()
{
    cout << solution("100-200*300-500+20") << endl;
}