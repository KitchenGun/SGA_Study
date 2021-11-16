#include <iostream>

void Plus(int* a)
{
	*a += 10;
}


int main()
{
	int temp = 10;
	int* b = &temp;
	int** a = &b;
	
	Plus(&temp);
	printf("t:%d\n", temp);
	printf("a:%d\n", **a);
	printf("b:%d\n", *b);

}