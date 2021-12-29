#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> Textsamples = { "c=","c-","dz=","d-","lj","nj","s","z" };
	string s;

	cin >> s;


	for (int i = 0; i < Textsamples.size(); i++)
	{
		for (string temps : Textsamples)
		{
			///idx == string::npos 찾아보기 필요
			// str.replace
		}
	}
}