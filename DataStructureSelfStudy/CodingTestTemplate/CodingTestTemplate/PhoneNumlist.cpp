#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;


bool solution(vector<string> phone_book) 
{
    bool answer = true;

    unordered_set<string>set(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            string phone_number = phone_book[i].substr(0, j + 1);
            if (set.find(phone_number)!=set.end())
                return false;
        }
    }

    return true;
}

int main()
{
    cout<< solution({ "123","456","789" });
}

