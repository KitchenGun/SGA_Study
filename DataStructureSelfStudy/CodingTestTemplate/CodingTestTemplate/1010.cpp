#include <iostream>
using namespace std;


int arr[31][31];

int main() 
{
	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		for (int j = 1; j <= M; j++)
			arr[1][j] = j;

		for (int j = 2; j <= N; j++)
			for (int h = 2; h <= M; h++)
				arr[j][h] = arr[j - 1][h - 1] + arr[j][h - 1];

		cout << arr[N][M] << endl;
	}

	return 0;
}
