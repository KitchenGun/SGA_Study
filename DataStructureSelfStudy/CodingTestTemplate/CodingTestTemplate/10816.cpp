#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int cards[500000];

int lowerBound(int n)
{
	int f = 0, l = N - 1, m;
	for (;;)
	{
		m = (f + l) / 2;

		if (f > l)
		{
			if (cards[f] == n) return f;
			else return -1;
		}

		if (cards[m] >= n) l = m - 1;
		else f = m + 1;
	}
}

int upperBound(int n)
{
	int f = 0, l = N - 1, m;
	for (;;)
	{
		m = (f + l) / 2;

		if (f > l)
		{
			if (cards[l] == n) return l;
			else return -1;
		}

		if (cards[m] <= n) f = m + 1;
		else l = m - 1;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> cards[i];
	sort(cards, cards + N);

	cin >> M;
	int n, res;
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		res = upperBound(n);
		if (res == -1) cout << "0 ";
		else cout << res - lowerBound(n) + 1 << " ";
	}

	return 0;
}