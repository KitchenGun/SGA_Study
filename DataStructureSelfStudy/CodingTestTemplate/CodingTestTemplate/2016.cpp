#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    string answer = "";
    int val =4;
    vector<int> month={31,29,31,30,31,30,31,31,30,31,30,31};

    for (int i = 0; i < (a-1); i++)
    {
        val+=month[i];
    }

    val+=b;
    
    switch (val%7)
    {
    case 0:
        answer = "SUN";
        break;
    case 1:
        answer = "MON";
        break;
    case 2:
        answer = "TUE";
        break;
    case 3:
        answer = "WED";
        break;
    case 4:
        answer = "THU";
        break;
    case 5:
        answer = "FRI";
        break;
    case 6:
        answer = "SAT";
        break;

    default:
        break;
    }

    return answer;
}



int main()
{
    cout<<solution(5,24);
}