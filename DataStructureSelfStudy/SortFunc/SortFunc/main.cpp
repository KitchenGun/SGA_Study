#include <iostream>
#include <algorithm>
using namespace std;


class person
{
public:
	person(string name, int score)
		:
		name(name), score(score)
	{

	}


	string name;
	int score;
	bool operator<(person& val)
	{
		return this->score < val.score;
	}

};

int main(void)
{
	person vec[3] = { person("a",10),person("b",5), person("c",2) };
	sort(vec, vec+3);
	for (person temp : vec)
	{
		cout << temp.name << endl;
	}

}