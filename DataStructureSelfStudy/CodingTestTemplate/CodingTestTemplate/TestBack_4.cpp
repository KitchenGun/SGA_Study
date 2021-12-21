#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	string num;
	int result = 0;
	bool isMinus=false;
	//ют╥б
	cin >> s;
	
    for (int i = 0; i <= s.size(); i++) 
    {
        if (s[i] == '-' || s[i] == '+' || i == s.size()) 
        {
            if (isMinus) 
            {
                result -= stoi(num);
                num = "";
            }
            else 
            {
                result += stoi(num);
                num = "";
            }
        }
        else
        {
            num += s[i];
        }

        if (s[i] == '-') 
        {
            isMinus = true;
        }
    }
    cout << result;
}