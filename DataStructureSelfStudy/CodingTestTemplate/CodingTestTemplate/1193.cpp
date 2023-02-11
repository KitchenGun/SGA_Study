#include <iostream>
using namespace std;

int main()
{

	int num =0;
	
	cin>>num;

	int i = 0;
	while (num > 0)
	{
		i++;
		num-=i;
	}

	if (i % 2 == 0)//Â¦¼ö
	{
		cout<< i + num <<"/" << i-(i+num-1);
	}
	else//È¦¼ö
	{
		cout << i - (i + num - 1) << "/" << i + num;
	}


	return 0;
}