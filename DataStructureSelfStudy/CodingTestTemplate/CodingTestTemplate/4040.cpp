#include <iostream> 
#include <vector>
using namespace std;



//가장 오래 머물 수 있는 방 찾기 
int greedy(vector<vector<char>>&arr,int start,int end)
{
	int max = 0;
	for (int i = 0; i < arr[0].size(); i++) 
	{	//1번방부터 m번방까지
		int day = 0;
		for (int j = start; j < end; j++)
		{	//index일부터 
			if (arr[j][i] == 'O') 
				day++;	//머물수 있다면 다음날 해당방 확인(루프계속) 
			else
				break;
		}

		if (max < day) 
			max = day;
	}
	return max;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> arr(n,vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>arr[i][j];
		}
	}

	int start,end;
	cin>>start>>end;

	int count =-1;
	for (int i = start - 1; i < end - 1;)
	{
		count++;
		int curCount = greedy(arr, i, end - 1);
		if (curCount ==0)
		{
			count = -1;
			break;		
		}
		i+= curCount;
	}
	
	cout<<count;
}