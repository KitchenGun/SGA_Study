#include <iostream>
using namespace std;
int main() {
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a')
			input[i]=toupper(input[i]);
		else
			input[i] = tolower(input[i]);
	}

	cout << input;

	return 0;
}