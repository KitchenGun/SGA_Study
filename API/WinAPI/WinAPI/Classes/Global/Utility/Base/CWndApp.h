#pragma once

#include "../../Define/KGDefine.h"

//������ ���ø����̼�

class CWndApp
{

public:
	//������ �޼����� ó���Ѵ�
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd, 
		UINT a_nMsg, 
		WPARAM a_wParams, 
		LPARAM a_lParams);
	//���ø����̼� ����
	int Run(void);

protected:
	//�ʱ�ȭ
	virtual void Init(void);
	//�޼��� ������ ������Ų��
	int RunMsgLoop(void);
	//ũ�� �޼����� ó���Ѵ�
	virtual LRESULT HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams);
	//�׸��� �޼����� ó���Ѵ�
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams);
	//���� �޼����� ó���Ѵ�
	virtual LRESULT HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams);
	//������ ����
	virtual HWND CreateWnd(WNDCLASS *a_pstOutWndClass);

protected:
	//������
	CWndApp(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
	//�Ҹ���
	virtual ~CWndApp(void);

private:
	//����
	int m_nShowOpts = 0;
	SIZE m_stWndSize;
	WNDCLASS m_stWndCls;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;

	HWND m_hWnd = nullptr;
	HINSTANCE m_hInst = nullptr;
};