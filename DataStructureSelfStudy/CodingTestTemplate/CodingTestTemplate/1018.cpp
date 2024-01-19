#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, min = 64, cnt = 0;
	char board[50][50];

	cin >> N >> M;
	for (int n = 0; n < N; n++)
		cin >> board[n];

	for (int n = 0; n <= N - 8; n++)
	{
		for (int m = 0; m <= M - 8; m++)
		{
			cnt = 0;
			for (int i = n; i < n + 8; i++)
			{
				for (int j = m; j < m + 8; j++)
				{
					if ((i + j) % 2 == 0 && board[i][j] == 'B')
						cnt++;
					else if ((i + j) % 2 == 1 && board[i][j] == 'W')
						cnt++;
				}
			}
			if (cnt > 32)
				cnt = 64 - cnt;
			if (cnt < min)
				min = cnt;
		}
	}
	cout << min << endl;
	return 0;
	
}