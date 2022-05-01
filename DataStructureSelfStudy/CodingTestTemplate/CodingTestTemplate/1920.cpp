#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



using namespace std;

int arr[100001];

//����Ž��(Binary Search)�� �̿��Ͽ� Ž��
void Solution(int n, int key) {

    int start = 0;
    int end = n - 1;
    int mid;

    while (end - start >= 0) {
        mid = (start + end) / 2;

        if (arr[mid] == key) {   //key ���� �迭�� �߾� ���� ������
            printf("1\n");
            return;

        }
        else if (arr[mid] > key) { //key ���� �迭�� �߾� ������ ������ (��������)
            end = mid - 1;

        }
        else {  //key ���� �迭�� �߾� ������ Ŭ�� (����������)
            start = mid + 1;
        }
    }

    printf("0\n");
    return;
}

int main(void) {

    int n, m, tmp;

    //�Է�
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);   //quick sort�� �̿��� �迭 ������������ ����

    //�Է�
   cin>>m;

    for (int i = 0; i < m; i++) {
       cin>>tmp;
        Solution(n, tmp);
    }

    return 0;
}