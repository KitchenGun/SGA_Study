#include <iostream>
using namespace std;

int main()
{
	int testNum=0;
	cin>>testNum;
	int h,w,count;

	for (int i = 0; i < testNum; i++)
	{
		cin >> h >> w >> count;
		count--;
		int floor = 0, room =0;

		room = count / h +1;

		floor = count % h+1;

		char temp ='0';

		cout << floor;
		if(room<10)
			cout << temp;
		cout<< room;
		cout<<endl;
	}

}