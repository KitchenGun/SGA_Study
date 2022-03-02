#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];

	double result = 0;
	float a,b,c;

	a = 4 * pow(input[0], 2) * pow(input[1], 2);
	b = pow(pow(input[0], 2) + pow(input[1], 2) - pow(input[2], 2), 2);
	c=a-b;
	result = 0.25f * sqrtf(c);

	cout<<fixed;
	cout.precision(2);
	cout << result;
	return 0;
}