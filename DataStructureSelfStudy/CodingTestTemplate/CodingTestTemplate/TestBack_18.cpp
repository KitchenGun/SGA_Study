#include <iostream>
using namespace std;


int main()
{
	int u, d, l;
	//int c=0;
	int result = 1;
	
	cin>>u;
	cin>>d;
	cin>>l;


	result+=(l - u) / (u - d);

	if ((l - u) % (u - d) != 0)
		result++;
	if (u >= l)
		cout << "1";
	else
		cout << result;

	/*
	while (c < l)
	{
		result++;
		c += u;
		if (c >= l)
		{
			break;
		}
		c -= d;
	}
	printf("%d",result);
	*/

}