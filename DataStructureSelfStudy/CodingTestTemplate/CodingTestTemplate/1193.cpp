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

	if (i % 2 == 0)//¦��
	{
		cout<< i + num <<"/" << i-(i+num-1);
	}
	else//Ȧ��
	{
		cout << i - (i + num - 1) << "/" << i + num;
	}


	return 0;
}