#pragma once
#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

/*
����̽� ���ؽ�Ʈ (DC)��?
������� Ư�� �̹��� ���� ����ϱ� ���ؼ��� �ش� �̹����� �׸��� ���� ���� �������� �ʿ��ϸ� 
�ش� �������� ������ �ִ� Ư�� �ڿ��� ����̽� ���ؽ�Ʈ��� �Ѵ�
�� ����̽� ���ؽ�Ʈ ���� ������ ���� �����ν� �پ��� �̹����� ���� ���� ������ �� ����ϴ� ���� �����ϴ�
������ ���� ���� �ڿ�
*/
//����ü ��� ���� ��� �� ��� 
class Example02 :public CWndApp
{
public:
	//������ �޼��� ó��
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd,
		UINT a_nMsg,
		WPARAM a_wParams,
		LPARAM a_lParams)override;
public:
	Example02(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
private:
	//���콺 �̵� �޼����� ó���Ѵ�
	LRESULT HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams);
	//���콺 ��ư �޼��� ó���Ѵ�
	LRESULT HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams,bool a_bIsBtnDown);
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)override;
private:
	POINT m_stPrevPos;
	POINT m_stCurPos;
};