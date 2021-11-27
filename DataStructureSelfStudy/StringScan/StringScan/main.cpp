#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*일반적인 문자열 탐색 시간 복잡도상 너무 비효율적임*/
//int findString(string parent, string pattern)
//{
//	int parentSize = parent.size();
//	int patternSize = pattern.size();
//	for (int i = 0; i <= parentSize - patternSize; i++)
//	{
//		bool finded = true;
//		for (int j = 0; j < patternSize; j++)
//		{
//			if (parent[i + j] != pattern[j])
//			{
//				finded = false;
//				break;
//			}
//		}
//
//		if (finded)
//		{
//			return i;
//		}
//	}
//	return -1;
//
//}
//
//int main()
//{
//	string parent = "hiiiii world";
//	string pattern = "world";
//
//	int result = findString(parent, pattern);
//	if (result == -1)
//	{
//		cout << "no found";
//	}
//	else
//	{
//		cout << result + 1 << " found";
//	}
//}

/*라빈 카프 알고리즘 hash를 사용해서 매우 빠르게 처리함*/
void findString(string s,string pattern)
{
	int sSize = s.size();
	int patternSize = pattern.size();

	int sHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i < sSize - patternSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < patternSize; j++)
			{
				sHash += s[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1)
					power *= 2;
			}
		}
		else
		{
			sHash = 2 * (sHash - s[i - 1] * power) + s[patternSize - 1 + i];
		}

		if (sHash == patternHash)
		{
			bool finded = true;
			for (int j = 0; j < patternSize; j++)
			{
				if (s[i + j] != pattern[j])
				{
					finded = false;
					break;
				}
			}

			if (finded)
			{
				printf("%d번째\n", i + 1);
			}
		}
	}
	
}
int main()
{
	string s = "ababacabacaabacaaba";
	string p = "a";
	findString(s, p);

}