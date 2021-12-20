#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int count = 0;
	int result = 0;
	int endTime = 0;
	vector<pair<int, int>> scheduler;
	//입력
	cin >> count;
	scheduler.resize(count);
	for (int i = 0; i < count; i++)
	{
		pair<int, int> temp;
		cin >> temp.second;
		cin >> temp.first;
		scheduler[i] = temp;
	}
	//정렬
	sort(scheduler.begin(), scheduler.end());
	//연산
	for (int i = 0; i < count; i++)
	{
		if (endTime <= scheduler[i].second)
		{
			endTime = scheduler[i].first;
			result++;
		}
	}
	cout << result;
}