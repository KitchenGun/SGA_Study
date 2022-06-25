#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> cardlist;

void cut()
{
	int half = cardlist.size() / 2;
	for (int i = 0; i < half; i++)
	{
		int start;
		start = cardlist[i];
		cardlist.push_back(start);
	}
	cardlist.erase(cardlist.begin(),cardlist.begin()+half);
}

void riffle()
{
	int half = cardlist.size() / 2;
	vector<int> a;
	for (int i = half; i < cardlist.size(); i++)
	{
		a.push_back(cardlist[i]);
	}
	cardlist.erase(cardlist.begin()+half, cardlist.end());

	vector<int>b;
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a[i]);
		b.push_back(cardlist[i]);
	}
	copy(b.begin(),b.end(),cardlist.begin());
}

int main()
{
	vector<int>card ={1,2,5,6,4,3};
	cardlist.assign(card.begin(), card.end());
	cut();
	cut();
	cut();
}