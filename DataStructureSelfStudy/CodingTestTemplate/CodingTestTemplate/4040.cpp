#include <iostream> 

using namespace std;

int n, m;
int day_begin, day_end;
char arr[101][31];

//���� ���� �ӹ� �� �ִ� �� ã�� 
int greedy(int index) {

	int max = 0;
	for (int i = 0; i < m; i++) {	//1������� m�������
		int day = 0;
		for (int j = index; j < day_end - 1; j++) {	//index�Ϻ��� 
			if (arr[j][i] == 'O') day++;	//�ӹ��� �ִٸ� ������ �ش�� Ȯ��(�������) 
			else break;
		}
		if (max < day) max = day;
	}
	return max;
}

int main() {

	cin>>n>>m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//s�� t�Է�
	cin >> day_begin >> day_end;

	int cnt = -1;	//�ű� Ƚ�� 
	//s�Ϻ��� t�ϱ���
	for (int i = day_begin - 1; i < day_end - 1;) {
		cnt++;
		//������ �Ұ����� ���
		if (greedy(i) == 0) {
			cnt = -1;
			break;
		}
		//��¥�� ���Ͽ� ���� ���� �ӹ��� �ִ� �� ã�� 
		i += greedy(i);	//�� �Ⱓ��ŭ �����ֱ�
	}

	printf("%d", cnt);
}