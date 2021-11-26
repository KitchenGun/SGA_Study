#include <iostream>
using namespace std;

int main()
{
	int number = 9;
	int heap[9] = { 9,1,3,8,9,5,7,6,5 };

	//먼저 전체 트리 구조를 최대 힙구조로 바꿉니다.
	for (int i = 1; i < number; i++)
	{
		int c = i;
		do 
		{
			int root = (c - 1) / 2;
		
			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	
	//크기를 줄여가면서 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do 
		{
			c = 2 * root + 1;
			//자식중에서 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1)
			{
				c++;
			}
			//루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i)
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	


	for (int temp : heap)
	{
		cout << temp;
	}
}