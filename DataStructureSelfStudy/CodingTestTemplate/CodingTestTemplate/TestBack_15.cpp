#include <iostream>

using namespace std;

int main()
{

	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;
	

	
	if (b - c >= 0)
		cout << -1;
	else
	{
		cout << a / (c - b) + 1 << endl;
	}
}