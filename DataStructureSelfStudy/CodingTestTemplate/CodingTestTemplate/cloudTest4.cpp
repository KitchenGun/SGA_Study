#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;

	int spacecount =input;
	int starcount =1;
	for (int i = 0; i < input; i++)
	{
		for (int j = spacecount; j > 1; j--)
		{
			cout << " ";
		}
		for (int k = 1; k <= starcount; k++)
		{
			cout << "*";
		}
		cout << endl;
		spacecount--;
		starcount+=2;
	}

	return 0;
}