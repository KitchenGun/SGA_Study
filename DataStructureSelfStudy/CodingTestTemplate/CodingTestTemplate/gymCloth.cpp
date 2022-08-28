#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) 
{
	for (int i = 0; i < lost.size(); i++)
	{
		if (i == lost.size())
		{
			break;
		}
		auto it = find(reserve.begin(), reserve.end(), lost[i]);
		if(it!=reserve.end())
		{
			reserve.erase(it);
			lost.erase(lost.begin()+i);
		}
	}

	//sort(lost.begin(),lost.end());
	//sort(reserve.begin(), reserve.end());

    int answer = n-lost.size();

	int pivot = 0;
    for (int i = 0; i < lost.size(); i++)
    {
        bool rent = false;
		int finder = pivot;

		
		while (!rent)
		{
			if (finder == reserve.size())
			{
				break;
			}

			if (reserve[finder] == (lost[i] - 1))
			{
				finder++;
				pivot = finder;
				answer++;
				rent = true;
			}
			else if (reserve[finder] == (lost[i] + 1))
			{
				finder++;
				pivot = finder;
				answer++;
				rent = true;
			}
			else if (reserve[finder] == (lost[i]))
			{
				finder++;
				pivot = finder;
				answer++;
				rent = true;
			}
			else
			{
				finder++;
			}
		}

    }
    return answer;
}

int main()
{
    cout<<solution(5,{1,2,3},{1,2,3,5});


}