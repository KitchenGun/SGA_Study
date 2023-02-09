#include <iostream>

using namespace std;

int main()
{
	long long room = 0;
	cin >> room;

	if (room == 1)
	{
		cout << 1;
		return 0;
	}

	long long count = 0;
	long long curRoom = 1;
	while (curRoom < room)
	{
		curRoom += (count * 6);
		count++;
	}
	cout << count;
	return 0;
}