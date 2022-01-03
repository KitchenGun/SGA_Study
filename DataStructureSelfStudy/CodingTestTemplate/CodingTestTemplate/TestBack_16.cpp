#include <iostream>
using namespace std;


int main()
{
	int n = 0;
	cin >> n;

	int i = 1;
	int temp=1;
	while (1)
	{
		if (n <= temp) {
			printf("%d", i);
			break;
		}
		temp += 6 * i;
		i++;
	}
	return 0;
}