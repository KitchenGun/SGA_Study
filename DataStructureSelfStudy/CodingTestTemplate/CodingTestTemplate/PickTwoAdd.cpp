#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> s;


    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if(i!=j)
                s.insert(numbers[i]+numbers[j]);
        }
    }


    vector<int> answer(s.begin(),s.end());
   

    return answer;
}


int main()
{
    vector<int> temp = solution({ 2,1,3,4,1 });
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<temp[i];
    }

}