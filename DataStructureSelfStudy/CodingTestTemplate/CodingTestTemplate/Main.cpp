#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//그리디 알고리즘
	/*
	int n, k;
	int result=0;
	cin >> n >> k;

	while (true)
	{
		int target = (n / k) * k;
		result += (n - target);
		n = target;
		if (n < k)break;
		result++;
		n /= k;
		result += (n - 1);
		cout << result << endl;
	}
	*/

	/*
	string str;

	cin >> str;

	int result = str[0] - '0';
	for (int i = 1; i < str.size(); ++i)
	{
		int num = str[i] - '0';
		if (num <= 1 || result <= 1)
		{
			result += num;
		}
		else
		{
			result *= num;
		}
	}
	cout << result << endl;
	*/

	//int n; 
	//vector<int> arr;
	//
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	int x;
	//	cin >> x;
	//	arr.push_back(x);
	//}
	//sort(arr.begin(), arr.end());
	//
	//int result = 0;
	//int cnt = 0;
	//for (int i =0;i<n;++i)
	//{
	//	cnt += 1;
	//	if (cnt >= arr[i])
	//	{
	//		result += 1;
	//		cnt = 0;
	//	}
	//}
	//cout << result << endl;
	/*
	배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

제한사항
배열 arr의 크기 : 1,000,000 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수
	*/
	//vector<int> arr = {1,1,3,3,0,1,1};
	//vector<int> answer;
	//answer.push_back(arr[0]);
	//for (int i = 0; i < arr.size(); ++i)
	//{
	//	if (arr[i] != answer[answer.size() - 1])
	//	{
	//		answer.push_back(arr[i]);
	//	}
	//}
	//
	//
	//cout << "Hello Cpp" << endl;
	//
	//
	//for (int temp : answer)
	//{
	//	cout << temp;
	//}
	//문자열 정렬 소문자 -> 대문자로
	/*
	string s = "Zbcdefg";
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[i] != s[j])
			{
				if (s[i] > s[j])
				{
					char temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}

	string answer = s;

	cout << s << endl;
	*/


	//정렬
	//int n = 10;
	//int target[10] = { 7,5,9,0,3,1,6,2,8,4 };
	//배열에서 가장 작은 수를 찾아서 순서대로 정렬하는 방식 중복이 없어야함
//for (int i = 0; i < (sizeof(target) / sizeof(int)); ++i)
//{
//	int min_index = i;
//	for (int j = i + 1; j < (sizeof(target) / sizeof(int)); ++j)
//	{
//		if (target[min_index] > target[j])
//		{
//			min_index = j;
//		}
//	}
//	swap(target[i], target[min_index]);
//}

	/*데이터 교체
	for (int i = 1; i < 10; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (target[j] < target[j-1])
			{
				swap(target[j], target[j-1]);
			}
			else
				break;
		}
	}
	*/
	//계수 정렬
	//int n = 15;
	//int target[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
	//int maxValue = 9;
	//int cnt[10] = {};
	//
	//for (int i = 0; i < n; ++i)
	//{
	//	cnt[target[i]] += 1;
	//}
	//
	//for (int i = 0; i <= maxValue; ++i)
	//{
	//	for (int j = 0; j < cnt[i]; ++j)
	//	{
	//		cout << i ;
	//	}
	//}

	//for (int temp : target)
	//{
	//	cout << temp;
	//}

	/*
문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

제한 조건
s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.
입출력 예
s	return
"1 2 3 4"	"1 4"
"-1 -2 -3 -4"	"-4 -1"
"-1 -1"	"-1 -1"
string solution(string s) {
	string answer = "";
	return answer;
}
*/
	string s = "-11 0 100";

	string answer = "";
	int min, max;
	int current = 0;
	bool isPlus = true;
	bool isSpace = true;
	int SpaceCount = 0;

	

	/*
	n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.
입출력 예
numbers	target	return
[1, 1, 1, 1, 1]	3	5
입출력 예 설명
문제에 나온 예와 같습니다.

int solution(vector<int> numbers, int target) {
	int answer = 0;
	return answer;
}
	*/
}
