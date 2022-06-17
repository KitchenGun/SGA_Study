#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*�Ϲ����� ���ڿ� Ž�� �ð� ���⵵�� �ʹ� ��ȿ������*/
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

/*��� ī�� �˰��� hash�� ����ؼ� �ſ� ������ ó����*/
/*void findString(string s, string pattern)
{
	int sSize = s.size();
	int patternSize = pattern.size();

	int sHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= sSize - patternSize; i++)
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
				printf("%d��°\n", i + 1);
			}
		}
	}
	
}
*/

//�������� �˰���
int GetHash(string target, int idx, int length)
{
    int result = 0;
    for (int i = idx; i <= idx + length; i++)
        result += target[i];
    return result;
}

int strStr(string haystack, string needle)
{
    int hsSize = haystack.size() - 1;
    int nSize = needle.size() - 1;

    int hsHash = 0;
    int nHash = 0;


    for (int i = 0; i <= nSize; i++)
        nHash += needle[i];

    for (int i = 0; i <= hsSize - nSize; i++)
    {
        hsHash = GetHash(haystack, i, nSize);
        if (hsHash == nHash)
        {
            bool isSame = false;
            for (int j = 0; j <= nSize; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    isSame = false;
                    break;
                }
                else
                {
                    isSame = true;
                }
            }
            if (isSame == true)
                return i;
        }

    }

    return -1;



}

int main()
{
	string s = "a";
	string p = "a";
	cout<<strStr(s, p);

}
