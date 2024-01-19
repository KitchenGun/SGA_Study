#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a;

	cin >> a;

	int target = 666;

	int count = 0; // 종말의 숫자 개수
	int num = 666; // 현재 숫자 (666부터 시작해도 무관)
	while (1) {
		// num에 666이 포함된다면 count++
		int consecutive_6 = 0;
		int cur = num;
		while (cur > 0) 
		{
			int digit = cur % 10;
			if (digit == 6)
				consecutive_6++;
			else
				consecutive_6 = 0; //다시 0으로 초기화

			if (consecutive_6 == 3) {
				count++;
				break;
			}
			cur = cur / 10;
		}

		// N번째로 작은 종말 숫자였다면 break, 아니라면 계속
		if (count == a)
			break;
		num++;
	}
	cout << num << endl;

}