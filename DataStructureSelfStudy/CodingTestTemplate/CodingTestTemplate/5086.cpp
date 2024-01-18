#include <iostream>



using namespace std;

int main()
{
	while (1)
	{
		int a,b;

		cin>>a>>b;
		bool first=false,second = false;
		if (a == 0 && b == 0)
		{
			break;
		}

		if (b % a == 0)
			cout << "factor" << endl;
		else if(a%b==0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;

	}
}