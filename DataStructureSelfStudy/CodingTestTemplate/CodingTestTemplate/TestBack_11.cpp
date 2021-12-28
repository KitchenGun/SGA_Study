#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s1,s2;
	int n1, n2;
	cin >> s1;
	cin >> s2;

	reverse(s1.begin(),s1.end());
	reverse(s2.begin(), s2.end());
	
	n1 = atoi(s1.c_str());
	n2 = atoi(s2.c_str());

	cout << (n1 > n2 ? n1 : n2) << endl;
}