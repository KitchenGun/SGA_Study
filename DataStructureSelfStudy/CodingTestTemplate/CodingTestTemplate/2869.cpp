#include <iostream>
using namespace std;

int main()
{
	int Range =0;
	int Up = 0;
	int Down =0;
	int cur =0;
	cin>>Up>>Down>>Range;

	Range-=Up;

	cur++;
	if(Range>0)
	{	
		cur+=(Range/(Up-Down));
		if((Range % (Up - Down)))
			cur++;
	}
	
	cout<<cur;
}