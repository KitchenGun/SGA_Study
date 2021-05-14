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
	//버튼이 눌렸을 경우
	if (a_wParams != 0)
	{
		m_stCurPos.x = LOWORD(a_lParams);
		m_stCurPos.y = HIWORD(a_lParams);
		//유요하지 않은 영역 = 특정영역 무효화 
		/*
		InvalidateRect를 사용하면 특정영역을 무효화 시키는 것이 가능하다 즉 윈도우가 지니고있는 특정 영역을
		무효화 시킬 경우 해당 윈도우 무효화된 영역을 다시 그리기 위해서 WM_Paint메세지를 발생시킨다
		
		따라서 해당 함수를 사용하면 이전에 그려진 이미지 등을 깔끔하게 지우는 것이 가능하다
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
	//마우스 버튼 눌렀을 경우
	if (a_bIsBtnDown)
	{
		m_stCurPos.x = m_stPrevPos.x = LOWORD(a_lParams);
		m_stCurPos.y = m_stPrevPos.y = HIWORD(a_lParams);
	}
	else 
	{
		/*
		GETDC함수는 특정 윈도우가 가지고 있는 디바이스 컨텍스트를 가져오는 역학을 수행한다
		WinAPI함수 중에 특정 윈도우에 그림을 출력하는 함수는 모든 디바이스 컨텍스트를 필요로 하기 때문에 특정 윈도우에 그림을 기리고 싶다면
		반드시 해당 함수를 사용해서 디바이스 컨텍스트를 가져와야한다

		또한 해당 함수를 통해서 가져온 디바이스 컨텍스트는 반드시 더이상 필요가 없을 경우 ReleaseDC함수를 사용해서 반드시 반환해야한다
		즉 GETDC를 통해서 디바이스 컨텍스트를 가져온 후 해당 함수를 호출하지 않는다면 쓸데없는 컴퓨터의 자원이 늘어나는 원인이 된다
		*/
		HDC hDC = GetDC(GET_WND_HANDLE());

		/*
		_try~_finally 구문을 사용하면 특정 함수가 실행 도중에 중단 되었을때 반드시 실행되도록 보장하는 구문을 작성하는 것이 가능하다
		즉 해당 구문을 사용하면 획득한 자원을 좀 더 안전하게 해제하는 것이 가능하다
		*/
		_try//_try는 비공식적인 호출 window visual 환경에서만 사용가능함
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

	
	//유요하지 않은 영역 = 특정영역 무효화 
	/*
	InvalidateRect를 사용하면 특정영역을 무효화 시키는 것이 가능하다 즉 윈도우가 지니고있는 특정 영역을
	무효화 시킬 경우 해당 윈도우 무효화된 영역을 다시 그리기 위해서 WM_Paint메세지를 발생시킨다

	따라서 해당 함수를 사용하면 이전에 그려진 이미지 등을 깔끔하게 지우는 것이 가능하다
	*/
	HDC hDC = GetDC(GET_WND_HANDLE());

	_try
	{
		/*
		반복 생성
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

