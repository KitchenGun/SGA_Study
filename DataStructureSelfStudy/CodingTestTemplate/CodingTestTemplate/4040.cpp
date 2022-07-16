#include <iostream> 

using namespace std;

int n, m;
int day_begin, day_end;
char arr[101][31];

//가장 오래 머물 수 있는 방 찾기 
int greedy(int index) {

	int max = 0;
	for (int i = 0; i < m; i++) {	//1번방부터 m번방까지
		int day = 0;
		for (int j = index; j < day_end - 1; j++) {	//index일부터 
			if (arr[j][i] == 'O') day++;	//머물수 있다면 다음날 해당방 확인(루프계속) 
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

	//s와 t입력
	cin >> day_begin >> day_end;

	int cnt = -1;	//옮긴 횟수 
	//s일부터 t일까지
	for (int i = day_begin - 1; i < day_end - 1;) {
		cnt++;
		//예약이 불가능한 경우
		if (greedy(i) == 0) {
			cnt = -1;
			break;
		}
		//날짜에 대하여 가장 오래 머물수 있는 방 찾기 
		i += greedy(i);	//그 기간만큼 더해주기
	}

	printf("%d", cnt);
}