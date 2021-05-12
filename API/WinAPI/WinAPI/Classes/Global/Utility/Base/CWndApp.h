#pragma once

#include "../../Define/KGDefine.h"

//윈도우 어플리케이션

class CWndApp
{

public:
	//윈도우 메세지를 처리한다
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd, 
		UINT a_nMsg, 
		WPARAM a_wParams, 
		LPARAM a_lParams);
	//어플리케이션 구동
	int Run(void);

protected:
	//초기화
	virtual void Init(void);
	//메세지 루프를 구동시킨다
	int RunMsgLoop(void);
	//크기 메세지를 처리한다
	virtual LRESULT HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams);
	//그리기 메세지를 처리한다
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams);
	//제거 메세지를 처리한다
	virtual LRESULT HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams);
	//윈도우 생성
	virtual HWND CreateWnd(WNDCLASS *a_pstOutWndClass);

protected:
	//생성자
	CWndApp(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
	//소멸자
	virtual ~CWndApp(void);

private:
	//변수
	int m_nShowOpts = 0;
	SIZE m_stWndSize;
	WNDCLASS m_stWndCls;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;

	HWND m_hWnd = nullptr;
	HINSTANCE m_hInst = nullptr;
};