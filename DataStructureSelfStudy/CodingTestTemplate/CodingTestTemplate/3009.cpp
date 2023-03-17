#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> xarr(0), yarr(0);

	for(int i =0;i<3;i++)
	{
		int x, y;

		cin >> x >> y;


		for (int& temp : xarr)
		{
			if (temp == x)
			{
				temp = 0;
				x=0;
				break;
			}
		}

		
		for (int& temp : yarr)
		{
			if (temp == y)
			{
				temp = 0;
				y=0;
				break;
			}
		}

		xarr.push_back(x);
		yarr.push_back(y);
	}

	for (int temp : xarr)
	{
		if(temp!=0)
		{
			cout<<temp<<" ";
		}
		
	}

	for (int temp : yarr)
	{
		if (temp != 0)
		{
			cout << temp;
		}
	}

}
