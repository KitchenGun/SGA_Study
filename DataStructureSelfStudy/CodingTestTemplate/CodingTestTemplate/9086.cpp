#include <iostream>

using namespace std;

int main()
{
	int count;
	cin>>count;

	for(int i =0;i<count;i++)
	{
		string str;
		cin>>str;
		cout<<str[0]<<(str.length()>=1?str[str.length()-1]:str[0])<<endl;
	}
}