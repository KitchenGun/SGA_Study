#include "Example02.h"

Example02::Example02(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
	:
	CWndApp(a_hInst, a_nShowOpts, a_rstWndSize)
{
	ZeroMemory(&m_stCurPos, sizeof(m_stCurPos));
	ZeroMemory(&m_stPrevPos, sizeof(m_stPrevPos));
}

LRESULT Example02::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	switch (a_nMsg)
	{
	case WM_MOUSEMOVE:
	{
		return this->HandleMouseMoveMsg(a_wParams, a_lParams);
	}
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
	{
		bool bIsBtnDown = a_nMsg == WM_LBUTTONDOWN;
		return this->HandleMouseBtnMsg(a_wParams, a_lParams, bIsBtnDown);
	}
	}
	return CWndApp::HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
}


LRESULT Example02::HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	//��ư�� ������ ���
	if (a_wParams != 0)
	{
		m_stCurPos.x = LOWORD(a_lParams);
		m_stCurPos.y = HIWORD(a_lParams);
		//�������� ���� ���� = Ư������ ��ȿȭ 
		/*
		InvalidateRect�� ����ϸ� Ư�������� ��ȿȭ ��Ű�� ���� �����ϴ� �� �����찡 ���ϰ��ִ� Ư�� ������
		��ȿȭ ��ų ��� �ش� ������ ��ȿȭ�� ������ �ٽ� �׸��� ���ؼ� WM_Paint�޼����� �߻���Ų��
		
		���� �ش� �Լ��� ����ϸ� ������ �׷��� �̹��� ���� ����ϰ� ����� ���� �����ϴ�
		*/
		InvalidateRect(GET_WND_HANDLE(), NULL, TRUE);

		HDC hDC = GetDC(GET_WND_HANDLE());

		_try
		{
			MoveToEx(hDC,m_stPrevPos.x,m_stPrevPos.y,NULL);
			LineTo(hDC, m_stCurPos.x, m_stCurPos.y);

		}
		__finally
		{
			SAFE_RELEASE_DC(GET_WND_HANDLE(), hDC);
		}
	}
	return 0;
}

LRESULT Example02::HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams, bool a_bIsBtnDown)
{
	//���콺 ��ư ������ ���
	if (a_bIsBtnDown)
	{
		m_stCurPos.x = m_stPrevPos.x = LOWORD(a_lParams);
		m_stCurPos.y = m_stPrevPos.y = HIWORD(a_lParams);
	}
	else 
	{
		/*
		GETDC�Լ��� Ư�� �����찡 ������ �ִ� ����̽� ���ؽ�Ʈ�� �������� ������ �����Ѵ�
		WinAPI�Լ� �߿� Ư�� �����쿡 �׸��� ����ϴ� �Լ��� ��� ����̽� ���ؽ�Ʈ�� �ʿ�� �ϱ� ������ Ư�� �����쿡 �׸��� �⸮�� �ʹٸ�
		�ݵ�� �ش� �Լ��� ����ؼ� ����̽� ���ؽ�Ʈ�� �����;��Ѵ�

		���� �ش� �Լ��� ���ؼ� ������ ����̽� ���ؽ�Ʈ�� �ݵ�� ���̻� �ʿ䰡 ���� ��� ReleaseDC�Լ��� ����ؼ� �ݵ�� ��ȯ�ؾ��Ѵ�
		�� GETDC�� ���ؼ� ����̽� ���ؽ�Ʈ�� ������ �� �ش� �Լ��� ȣ������ �ʴ´ٸ� �������� ��ǻ���� �ڿ��� �þ�� ������ �ȴ�
		*/
		HDC hDC = GetDC(GET_WND_HANDLE());

		/*
		_try~_finally ������ ����ϸ� Ư�� �Լ��� ���� ���߿� �ߴ� �Ǿ����� �ݵ�� ����ǵ��� �����ϴ� ������ �ۼ��ϴ� ���� �����ϴ�
		�� �ش� ������ ����ϸ� ȹ���� �ڿ��� �� �� �����ϰ� �����ϴ� ���� �����ϴ�
		*/
		_try//_try�� ��������� ȣ�� window visual ȯ�濡���� ��밡����
		{
			MoveToEx(hDC,m_stPrevPos.x,m_stPrevPos.y,NULL);
			LineTo(hDC, m_stCurPos.x, m_stCurPos.y);
			m_LineArr.push_back(std::make_pair(m_stPrevPos, m_stCurPos));
		}
		__finally
		{
			SAFE_RELEASE_DC(GET_WND_HANDLE(), hDC);
		}
	}
	return 0;
}

LRESULT Example02::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)
{

	
	//�������� ���� ���� = Ư������ ��ȿȭ 
	/*
	InvalidateRect�� ����ϸ� Ư�������� ��ȿȭ ��Ű�� ���� �����ϴ� �� �����찡 ���ϰ��ִ� Ư�� ������
	��ȿȭ ��ų ��� �ش� ������ ��ȿȭ�� ������ �ٽ� �׸��� ���ؼ� WM_Paint�޼����� �߻���Ų��

	���� �ش� �Լ��� ����ϸ� ������ �׷��� �̹��� ���� ����ϰ� ����� ���� �����ϴ�
	*/
	HDC hDC = GetDC(GET_WND_HANDLE());

	_try
	{
		/*
		�ݺ� ����
		*/
		for (std::pair<POINT,POINT> templine : m_LineArr) 
		{
			MoveToEx(hDC, templine.first.x, templine.first.y, NULL);
			LineTo(hDC, templine.second.x, templine.second.y);
		}
	}
	__finally
	{
		SAFE_RELEASE_DC(GET_WND_HANDLE(), hDC);
	}
	return CWndApp::HandlePaintMsg(a_wParams, a_lParams);
}

