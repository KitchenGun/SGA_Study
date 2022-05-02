#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

//틀린 이유 중복을 찾을려는 문제를 잘 읽지 않은 문제
//멍청하게 무한 루프문을 만듬end = target;->end = target-1;이렇게 바꿔서 해결

//이진탐색(Binary Search)을 이용하여 탐색
int Solution(int n, int key) 
{
	int start = 0;
	int end = n-1;
	int target = (start+end)/2;
	int count = 0;

	while (end>=start)
	{
		target = (start + end) / 2;

		if (arr[target]==key)
		{
			return 1;
		}
		else if (arr[target] > key)
		{
			end = target-1;
		}
		else
		{
			start = target+1;
		}
	}
	return 0;

}


int main(void) 
{
	int n,m;

	cin>>n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;

		arr.push_back(temp);
	}
   
   //정렬
   sort(arr.begin(),arr.end());

	cin>>m;

	vector<int> results;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		results.push_back(Solution(n,temp));
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", results[i]);
	}

}