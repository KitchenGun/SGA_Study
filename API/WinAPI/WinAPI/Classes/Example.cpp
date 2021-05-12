#include "Example01/Example01.h"
#include "Example02/Example02.h"


/*
WinAPI��?

�������� �ü�� �󿡼� �����Ǵ� ���ø����̼��� �����ϱ� ���� API�� �ǹ��Ѵ�
�� WinAPI�� ����ϸ� ��Ƽ�̵�� ���ø����̼��� �����Ҽ��ִ�
*/
//�����Լ�
//�޸𸮻󿡼� Ȱ��ȭ ������ ������ ���μ��� ���α׷��� �ϳ��� �ν��Ͻ��� ���α׷��̶�� �Ѵ�
int WINAPI _tWinMain(//�����ڵ�� ��Ƽ����Ʈ�� �ٲ㵵 ���������� _t�� ����
	HINSTANCE a_hInst,//������ ���μ����� �޸𸮻� �ּ� ������
	HINSTANCE a_hPrevInst, //������� ���� �Լ�����������
	TCHAR *a_pszCmdLine, //Ŀ�ǵ����
	int a_nShowOpts)//�ɼ�
{
	SIZE stWndSize = {
		480,320
	};

	//Example01 oApp(a_hInst, a_nShowOpts, stWndSize);
	Example02 oApp(a_hInst, a_nShowOpts, stWndSize);

	return oApp.Run();
}