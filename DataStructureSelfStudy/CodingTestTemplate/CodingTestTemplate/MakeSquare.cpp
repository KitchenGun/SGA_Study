#include <iostream>

using namespace std;

int main(void) 
{
    int a;
    int b;
    cin >> a >> b;

    for (int y = 0; y < b; y++)
    {
        for (int x = 0; x < a; x++)
        {
            cout << "*";
        }
        cout<<endl;
    }

    return 0;
}