#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;

	cin>>a>>b;
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	string c;
	bool addone = false;

	int i =0;
	while(i<a.length()||i<b.length())
	{
		int anum =0;
		int bnum = 0;
		if(i<a.length())
		{
			anum = a[i]- '0';
		}
		if (i < b.length())
		{
			bnum = b[i] - '0';
		}
		int cnum = anum+bnum;

		if(addone)
			cnum++;

		if(cnum<=9)
		{
			addone = false;
		}
		else
		{
			addone = true;
			cnum-=10;
		}

		c.push_back('0' + (char)cnum);

		i++;
	}

	if (addone)
		c.push_back('1');

	reverse(c.begin(), c.end());

	cout<<c;

}