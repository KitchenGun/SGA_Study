#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
int main() {
	int N, j, cnt = 0;
	string str;
	int arr[26];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		fill_n(arr, 26, 0);

		arr[str[0] - 97] = 1;
		for (j = 1; j < str.length(); j++) {
			if (str[j - 1] != str[j]) {
				int idx = str[j] - 97;
				if (arr[idx] == 0)
					arr[idx]++;
				else
					break;
			}
		}
		if (j == str.length())
			cnt++;
	}
	cout << cnt;
}*/


int main()
{
	vector<string> sVector;
	int alphabet[26] = { 0 };
	int count = 0;
	int result=0;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		string temp;
		cin >> temp;

		sVector.push_back(temp);
	}


	for (string temp : sVector)
	{
		char beforec=0;
		bool IsContinuous = false;
		memset(alphabet, 0, 26);
		for (char tempc : temp)
		{
			if (alphabet[tempc - 'a'] == 0)
			{
				alphabet[tempc - 'a']++;
				if (beforec == 0)
				{
					beforec = tempc;
					IsContinuous = true;
				}
				else if (beforec > tempc)
				{
					if (IsContinuous)
						result++;

					beforec = tempc;
					IsContinuous = false;
				}
				else if (beforec < tempc)
				{
					beforec = tempc;
					IsContinuous = true;
				}
				else
					break;
			}
			else
			{
				beforec = 0;
				IsContinuous = false;
				break;
			}
		}
		if (IsContinuous)
			result++;
	}

	cout << result;
}