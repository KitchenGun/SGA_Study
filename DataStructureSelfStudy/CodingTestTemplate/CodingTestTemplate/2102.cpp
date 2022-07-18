#include <iostream>
using namespace std;

unsigned long long n;
unsigned long long limit = 1111111111111111111;
unsigned long long minVal = INT64_MAX;

void solution(unsigned long long start)
{
	if (start % n == 0)
		minVal = min(minVal, start);

	if (start > limit)
		return;

	solution(start * 10 + 1);
	solution(start * 10);
}



int main()
{
	cin>>n;
	if (n > limit)
	{
		cout<<0;
	}
	else
	{
		solution(1);
		cout<<(minVal==INT64_MAX?0: minVal);
	}
}