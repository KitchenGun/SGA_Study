#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#include <stack>
#include <queue>
using namespace std;

int main()
{
	//�׸��� �˰���
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
	�迭 arr�� �־����ϴ�. �迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�. �̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�. ��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�. ���� ���,

arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸� [4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
�迭 arr�� ũ�� : 1,000,000 ������ �ڿ���
�迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����
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
	//���ڿ� ���� �ҹ��� -> �빮�ڷ�
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


	//����
	//int n = 10;
	//int target[10] = { 7,5,9,0,3,1,6,2,8,4 };
	//�迭���� ���� ���� ���� ã�Ƽ� ������� �����ϴ� ��� �ߺ��� �������
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

	/*������ ��ü
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
	//��� ����
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
���ڿ� s���� �������� ���е� ���ڵ��� ����Ǿ� �ֽ��ϴ�. str�� ��Ÿ���� ���� �� �ּҰ��� �ִ밪�� ã�� �̸� "(�ּҰ�) (�ִ밪)"������ ���ڿ��� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���.
������� s�� "1 2 3 4"��� "1 4"�� �����ϰ�, "-1 -2 -3 -4"��� "-4 -1"�� �����ϸ� �˴ϴ�.

���� ����
s���� �� �̻��� ������ �������� ���еǾ� �ֽ��ϴ�.
����� ��
s	return
"1 2 3 4"	"1 4"
"-1 -2 -3 -4"	"-4 -1"
"-1 -1"	"-1 -1"
string solution(string s) {
	string answer = "";
	return answer;
}
*/
	//string s = "-1 200 -100";
//vector<int> vecInt;
//string sTemp="";
//string answer = "";
//
//
//for (int i =0; i<s.size();++i)
//{
//	if (s[i] == ' ')
//	{
//		vecInt.push_back(stoi(sTemp));
//		sTemp.clear();
//		continue;
//	}
//	sTemp += s[i];
//}
//vecInt.push_back(stoi(sTemp));
//sort(vecInt.begin(),vecInt.end());
//
//answer += to_string(vecInt.front());
//answer += ' ';
//answer += to_string(vecInt.back());
//
//cout<< answer;

	stack<int> stack1;

	stack1.push(1);
	stack1.push(2);
	stack1.push(3);

	while (!stack1.empty())
	{
		cout << stack1.top() << endl;
		stack1.pop();
	}


	queue<int> queue1;

	queue1.push(1);
	queue1.push(2);
	queue1.push(3);

	while (!queue1.empty())
	{
		cout << queue1.front() << endl;
		queue1.pop();
	}
}
