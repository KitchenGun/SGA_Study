#include <iostream>
using namespace std;


int recursionCount =0;

int recursion(string& s, int l, int r)
{
	recursionCount++;
    if (l >= r) 
		return 1;
    else if(s[l] != s[r])
		return 0;
    else 
		return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s)
{
    return recursion(s, 0, s.length() - 1);
}

int main()
{
	int count;
	cin>> count;
	
	for(int i =0;i<count;i++)
	{
		string str;
		cin>>str;

		recursionCount=0;
		
		cout<< isPalindrome(str) << " " << recursionCount << endl;
	}

}