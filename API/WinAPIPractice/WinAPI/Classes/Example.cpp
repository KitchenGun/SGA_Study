#include "Example01/Example01.h"
#include "Example02/Example02.h"


/*
WinAPI란?

윈도우즈 운영체제 상에서 구동되는 어플리케이션을 제작하기 위한 API를 의미한다
즉 WinAPI를 사용하면 멀티미디어 어플리케이션을 제작할수있다
*/
//메인함수
//메모리상에서 활성화 스택이 있으면 프로세스 프로그램의 하나의 인스턴스를 프로그램이라고 한다
int WINAPI _tWinMain(//유니코드와 멀티바이트를 바꿔도 문제없도록 _t를 붙임
	HINSTANCE a_hInst,//실행한 프로세스의 메모리상 주소 포인터
	HINSTANCE a_hPrevInst, //사용하지 않음 함수원형유지용
	TCHAR *a_pszCmdLine, //커맨드라인
	int a_nShowOpts)//옵션
{
	SIZE stWndSize = {
		480,320
	};

	//Example01 oApp(a_hInst, a_nShowOpts, stWndSize);
	Example02 oApp(a_hInst, a_nShowOpts, stWndSize);

	return oApp.Run();
}