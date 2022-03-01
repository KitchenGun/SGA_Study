#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	int start;
	int count;
	getline(cin, input);

	cin >> start >> count;
	start--;
	count--;
	string result = input.substr(start, count);
	cout<<result;

	return 0;
}