#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#include <stack>
#include <queue>
using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x)
{
	visited[x] = true;
	cout << x << ' ';
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y])
		{
			dfs(y);
		}
	}
}

int count = 0;

queue<int> queueGroup[3];


void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		int x = q.front();
		q.pop();
		cout << x << ' ';
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

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
	/*
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
		*/
	
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);

	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(5);
	
	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(7);

	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(1);
	graph[8].push_back(7);

	//dfs(1);
	bfs(1);
	
}
