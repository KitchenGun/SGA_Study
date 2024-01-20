#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;


vector<int> solution(string& R, vector<int>& V) 
{
	vector<int> result = { 0,0 };
	//반전
	reverse(R.begin(), R.end());
	reverse(V.begin(), V.end());
	//순환
	for (int i =0;i<(int)R.length();i++)
	{
		if (R[i] == 'A')
		{

			result[1] += V[i];
			//은행은 빚질수 없다
			if(result[0]-V[i]>=0)
				result[0] -= V[i];
			else
				result[0] = 0;
		}
		else
		{
			result[0] += V[i];
			//은행은 빚질수 없다
			if (result[1] - V[i] >= 0)
				result[1] -= V[i];
			else
				result[1] = 0;
		}
	}
	return result;
}


int main()
{
	vector<int> A = { 10,5,10,15 };
	string R = "ABAB";

	for (int temp : solution(R, A))
	{
		cout <<temp << " ";
	}
}