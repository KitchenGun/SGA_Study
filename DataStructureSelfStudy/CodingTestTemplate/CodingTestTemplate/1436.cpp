#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a;

	cin >> a;

	int target = 666;

	int count = 0; // ������ ���� ����
	int num = 666; // ���� ���� (666���� �����ص� ����)
	while (1) {
		// num�� 666�� ���Եȴٸ� count++
		int consecutive_6 = 0;
		int cur = num;
		while (cur > 0) 
		{
			int digit = cur % 10;
			if (digit == 6)
				consecutive_6++;
			else
				consecutive_6 = 0; //�ٽ� 0���� �ʱ�ȭ

			if (consecutive_6 == 3) {
				count++;
				break;
			}
			cur = cur / 10;
		}

		// N��°�� ���� ���� ���ڿ��ٸ� break, �ƴ϶�� ���
		if (count == a)
			break;
		num++;
	}
	cout << num << endl;

}