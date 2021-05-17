#include "Example02.h"

Example02::Example02(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
	: CWndApp(a_hInst, a_nShowOpts, a_rstWndSize)
{
	// Do Nothing
}

LRESULT Example02::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	switch (a_nMsg) {
	case WM_MOUSEMOVE: {
		return this->HandleMouseMoveMsg(a_wParams, a_lParams);
	}
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN: {
		bool bIsBtnDown = a_nMsg == WM_LBUTTONDOWN;
		return this->HandleMouseBtnMsg(a_wParams, a_lParams, bIsBtnDown);
	}
	}

	return CWndApp::HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

void Example02::DoRender(HDC a_hDC)
{
	CWndApp::DoRender(a_hDC);

	for (auto &rstLineInfo : m_oLineInfoList) {
		MoveToEx(a_hDC,
			rstLineInfo.m_stStartPos.x, rstLineInfo.m_stStartPos.y, NULL);

		LineTo(a_hDC,
			rstLineInfo.m_stEndPos.x, rstLineInfo.m_stEndPos.y);
	}
}

LRESULT Example02::HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	// 버튼이 눌렸을 경우
	if (a_wParams != 0) {
		m_oLineInfoList.back().m_stEndPos.x = LOWORD(a_lParams);
		m_oLineInfoList.back().m_stEndPos.y = HIWORD(a_lParams);

		/*
		InvalidateRect 함수를 사용하면 윈도우의 특정 영역을 무효화 시키는 것이
		가능하다. (즉, 윈도우가 지니고 있는 특정 영역을 무효화 시킬 경우 해당
		윈도우 무효화 된 영역을 다시 그리기 위해서 WM_PAINT 메세지를 발생시킨다.)

		따라서, 해당 함수를 사용하면 이전에 그려진 이미지 등을 깔끔하게 지우는
		것이 가능하다.
		*/
		//InvalidateRect(GET_WND_HANDLE(), NULL, TRUE);
	}

	return 0;
}

LRESULT Example02::HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams, bool a_bIsBtnDown)
{
	// 마우스 버튼 눌렀을 경우
	if (a_bIsBtnDown) {
		STLineInfo stLineInfo = {
			{ LOWORD(a_lParams), HIWORD(a_lParams) },
			{ LOWORD(a_lParams), HIWORD(a_lParams) }
		};

		m_oLineInfoList.push_back(stLineInfo);
	}

	return 0;
}

LRESULT Example02::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	/*
	GetDC 함수는 특정 윈도우가 지니고 있는 디바이스 컨텍스트를 가져오는
	역할을 수행한다. WinAPI 함수 중에 특정 윈도우에 그림을 출력하는 함수는
	모든 디바이스 컨텍스트를 필요로 하기 때문에 특정 윈도우에 그림을 그리고
	싶다면 반드시 해당 함수를 사용해서 디바이스 컨텍스트를 가져와야한다.

	또한, 해당 함수를 통해서 가져온 디바이스 컨텍스트는 반드시 더이상 필요가
	없을 경우 ReleaseDC 함수를 사용해서 다시 반환시켜줘야한다.
	(즉, GetDC 함수를 사용해서 디바이스 컨텍스트를 가져온 후 해당 함수를
	호출하지 않는다면 쓸데 없는 컴퓨터의 자원이 늘어나는 원인이 된다.)

	단, WN_PAINT 메세지가 발생했을 경우에는 GetDC 함수가 아닌 BeginPaint 함수를
	통해 디바이스 컨텍스트를 가져오는 것을 추천한다. 이는 해당 함수를 통해서
	디바이스 컨텍스트를 가져 올 경우 해당 자원 이외에 그림을 그리기 위한 부가 정보를
	알 수 있기 때문이다.

	그리고 해당 함수를 통해서 가져온 디바이스 컨텍스트는 반드시 EndPaint 함수를
	사용해서 자원을 반환해줘야한다.
	*/
	PAINTSTRUCT stPaintStruct;
	BeginPaint(GET_WND_HANDLE(), &stPaintStruct);

	//HDC hDC = GetDC(GET_WND_HANDLE());

	/*
	__try ~ __finally 구문을 사용하면 특정 함수가 실행 도중에 중단 되었을
	경우 반드시 실행되도록 보장하는 구문을 작성하는 것이 가능하다.
	(즉, 해당 구문을 사용하면 획득 한 자원을 좀 더 안전하게 해제하는 것이
	가능하다.)
	*/
	__try {
		//for (auto &rstLineInfo : m_oLineInfoList) {
		//	MoveToEx(stPaintStruct.hdc,
		//		rstLineInfo.m_stStartPos.x, rstLineInfo.m_stStartPos.y, NULL);
		//
		//	LineTo(stPaintStruct.hdc,
		//		rstLineInfo.m_stEndPos.x, rstLineInfo.m_stEndPos.y);
		//}
	}
	__finally {
		EndPaint(GET_WND_HANDLE(), &stPaintStruct);

		//SAFE_RELEASE_DC(GET_WND_HANDLE(), hDC);
	}

	return CWndApp::HandlePaintMsg(a_wParams, a_lParams);
}
