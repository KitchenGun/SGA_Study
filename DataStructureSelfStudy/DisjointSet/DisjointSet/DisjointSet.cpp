#include <iostream>
#include "DisjointSet.h"
using namespace std;

int main()
{
	DisjointSet<int>::Set* set1 = DisjointSet<int>::CreateSet(1);
	DisjointSet<int>::Set* set2 = DisjointSet<int>::CreateSet(2);
	DisjointSet<int>::Set* set3 = DisjointSet<int>::CreateSet(3);
	DisjointSet<int>::Set* set4 = DisjointSet<int>::CreateSet(4);

	printf("Set1 == Set2 : %d\n", DisjointSet<int>::FindSet(set1) == DisjointSet<int>::FindSet(set2));

	DisjointSet<int>::UnionSet(set1, set3);

	printf("Set1 == Set3 : %d\n", DisjointSet<int>::FindSet(set1) == DisjointSet<int>::FindSet(set3));

	DisjointSet<int>::UnionSet(set3, set4 );

	printf("Set3 == Set4 : %d\n", DisjointSet<int>::FindSet(set3) == DisjointSet<int>::FindSet(set4));

	DisjointSet<int>::UnionSet(set1, set2);

	printf("Set1 == Set2 : %d\n", DisjointSet<int>::FindSet(set1) == DisjointSet<int>::FindSet(set2));

}