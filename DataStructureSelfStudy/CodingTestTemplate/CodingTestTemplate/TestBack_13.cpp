#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> Textsamples = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	string s;
	int Result = 0;
	cin >> s;


	for (int i = 0; i < Textsamples.size(); i++)
	{
		int idx = s.find(Textsamples[i]);
		while (idx != -1)
		{
			s.replace(idx,Textsamples[i].length(),".");
			Result++;
			idx = s.find(Textsamples[i]);
		}
		
	}
	cout << Result+(s.length()-Result) << endl;
}