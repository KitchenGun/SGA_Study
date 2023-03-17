#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int count=0;
	cin>>count;

	int big,small;

	map<int,vector<int>> info;

	for(int i=0;i<6;i++)
	{
		int dir,len;

		cin>>dir>>len;

		info[dir].push_back(len);
	}

	//큰거 작은거 찾기
	vector<int> max(4, 0);
	vector<int> min(4, INT32_MAX);

	for(int i =1;i<=4;i++)
	{
		for (int temp : info[i])
		{
			if(temp>max[i-1])
			{
				max[i-1]=temp;
			}
			if(temp<min[i-1])
			{
				min[i-1] = temp;
			}
		}
	}

	int maxx,maxy;
	int maxxidx,maxyidx;
	//큰 x y 구하기
	if(max[2]>max[3])
	{
		maxx = max[2];
		maxxidx = 3;
	}
	else
	{
		maxx = max[3];
		maxxidx = 4;
	}
	if(max[0] > max[1])
	{
		maxy = max[0];
		maxyidx = 1;
	}
	else
	{
		maxy = max[1];
		maxyidx = 2;
	}

	big=maxx*maxy;

	int minx,miny;
	//작은 x y 구하기
	if(maxxidx==3)
	{
		if(maxyidx==1)
		{

			minx = info[4][1];
		}
		else
		{
			minx = info[4][0];
		}
	}
	else
	{
		if (maxyidx == 1)
		{
			minx = info[3][0];
		}
		else
		{
			minx = info[3][1];
		}
	}

	if (maxyidx == 2)
	{
		if (maxyidx == 1)
		{
			miny = info[1][1];
		}
		else
		{
			miny = info[1][0];
		}
	}
	else
	{
		if (maxxidx == 1)
		{
			miny = info[2][1];
		}
		else
		{
			miny = info[2][0];
		}
	}

	small = minx*miny;

	cout<<(big-small)*count;

}