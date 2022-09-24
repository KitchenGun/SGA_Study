#include <iostream>
#include <string>
#include <vector>

using namespace std;


int gcd(int n, int m)
{
    int lowVal = n<m?n:m;
    int gcd =0;
    for (int i = 1; i <= lowVal; i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }
    
    return gcd;
}

int lcm(int n, int m)
{
    int lowVal = n < m ? n : m;
    int lcm = 0;
    for (int i = lowVal;; i++)
    {
        if (i%n == 0 && i%m == 0)
        {
            lcm = i;
            return lcm;
        }
    }
}


vector<int> solution(int n, int m) 
{
    vector<int> answer;

    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n, m));

    return answer;
}

int main()
{
    cout<<solution(3,12)[0]<< solution(3, 12)[1];
}