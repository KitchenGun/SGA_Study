#include <iostream>

using namespace std;

int main()
{
	int mx,my,endx,endy;

	cin>> mx >> my >> endx >> endy;

	int x,y;

	if(endx-mx>mx)
	{
		x = mx;
	}
	else
	{
		x= endx - mx;
	}

	if (endy - my > my)
	{
		y = my;
	}
	else
	{
		y = endy - my;
	}


	cout<<(x<y?x:y);
}