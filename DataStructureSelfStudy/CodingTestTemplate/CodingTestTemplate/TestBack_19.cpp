#include <iostream>
using namespace std;


int main()
{
	int count;
	int Hresult,Wresult;
	cin >> count;


	for (int i = 0; i < count; i++)
	{
		int H, W, N;
		//�Է�
		cin >> H;
		cin >> W;
		cin >> N;
		//����
		if (N % H==0)
			Wresult = N / H;
		else
			Wresult = (N / H)+1;
		if (N % H==0)
			Hresult = H;
		else
			Hresult = (N % H);

		//���
		cout << Hresult;
		if (Wresult < 10)
		{
			cout << 0 << Wresult << endl;
		}
		else
		{
			cout << Wresult << endl;;
		}
	}
}