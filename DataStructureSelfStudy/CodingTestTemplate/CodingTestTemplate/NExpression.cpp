#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int solution(int N, int number)
{
    unordered_set<int> s[8];

    int sum =0;
    for (int i = 0; i < 8; ++i) 
    { // 각 항목에다가 N, NN, NNN... 넣어줌
        sum = 10 * sum + N;
        s[i].insert(sum);
    }


    for (int i = 1; i < 8; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            for (int a : s[j]) 
            {
                for (int b : s[i - j - 1]) 
                {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0)
                        s[i].insert(a / b);
                }
            }
        }
    }

  
	for (int i = 0; i < 9; i++)
	{
		if(s[i].find(number)!=s[i].end())	
			return i+1;
	}
	return -1;
}


int main()
{
	
	cout<<solution(5,12);

}