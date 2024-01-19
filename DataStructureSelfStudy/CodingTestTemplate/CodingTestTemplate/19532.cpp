#include <iostream>
using namespace std;

int main()
{
		int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	int x, y;
	for (x = -999; x <= 999; x++)
	{
		for (y = -999; y <= 999; y++)
		{
			if (A * x + B * y == C && D * x + E * y == F)
			{
				cout << x << ' ' << y;
				return 0;
			}
		}
	}
	return 0;
}