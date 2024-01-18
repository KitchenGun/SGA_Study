#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int a, b;
	cin >> a >> b;
	int answer = 0;
	vector<int> v;
	for (int i = a; i <= b; i++)
	{
		int cnt =0;
		for (int j = 1; j <= i; j++)
		{
			if(i%j==0)
				cnt++;	
		}
		if(cnt==2)
				v.push_back(i);
	}

	if (v.size() == 0)
		cout << -1;
	else
	{
		for(int i : v)
			answer+=i;
		cout << answer << '\n' << v[0] << endl;
	}
}