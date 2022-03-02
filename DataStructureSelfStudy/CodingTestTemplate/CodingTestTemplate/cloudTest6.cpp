#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> *target, int num, int size)
{
	int minindex = num;


	for (int i = num; i < size; i++)
	{
		if (target->at(i)< target->at(minindex))
		{
			minindex = i;
		}
	}

	int temp = target->at(minindex);
	target->at(minindex) = target->at(num);
	target->at(num) = temp;
}



int main() {
	int count;
	int sortcount;
	vector<int> array;
	cin >> count >> sortcount;

	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		array.push_back(temp);
	}

	for (int i = 0; i < sortcount; i++)
		sortArray(&array, i, count);

	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}