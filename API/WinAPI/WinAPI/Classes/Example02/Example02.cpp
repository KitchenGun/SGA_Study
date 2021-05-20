#include "Example02.h"
#include "../Global/Utility/Manager/CInputManager.h"

Example02::Example02(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
	: CWndApp(a_hInst, a_nShowOpts, a_rstWndSize)
{
	// Do Nothing
}

Example02::~Example02(void)
{
	for (auto &rstKeyVal : m_oPenList)
	{
		SAFE_DEL_GDI_OBJ(rstKeyVal.second);
	}

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

void Example02::Init(void)
{
	CWndApp::Init();

	m_hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::RED, m_hRedPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::GREEN, m_hGreenPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::BLUE, m_hBluePen));

}

void Example02::Update(float a_fDeltaTime)
{
	CWndApp::Update(a_fDeltaTime);
	//������ Ű�� ������ ���
	if (IS_KEY_PRESS(DIK_R))
	{
		m_eColor = EColor::RED;
	}
	//�ʷ��� Ű�� ������ ���
	if (IS_KEY_PRESS(DIK_G))
	{
		m_eColor = EColor::GREEN;
	}
	//�Ķ��� Ű�� ������ ���
	if (IS_KEY_PRESS(DIK_B))
	{
		m_eColor = EColor::BLUE;
	}

	//���콺 ��ư�� ������ ���
	if (IS_MOUSE_BTN_DOWN(EMouseBtn::LEFT))
	{
		//���콺 ��ư������ �������� ���
		if (IS_MOUSE_BTN_PRESS(EMouseBtn::LEFT))
		{
			// ���콺 ��ư ������ ���
			STLineInfo stLineInfo = {
				m_eColor,GET_MOUSE_POS(),GET_MOUSE_POS()
			};

			m_oLineInfoList.push_back(stLineInfo);

		}
		m_oLineInfoList.back().m_eColor = m_eColor;
		m_oLineInfoList.back().m_stEndPos = GET_MOUSE_POS();
	}


}

void Example02::DoRender(HDC a_hDC)
{
	CWndApp::DoRender(a_hDC);

	for (auto &rstLineInfo : m_oLineInfoList) {
		HPEN hPen = m_oPenList[rstLineInfo.m_eColor];
		HPEN hPrevPen = (HPEN)SelectObject(a_hDC, hPen);
		MoveToEx(a_hDC,
			rstLineInfo.m_stStartPos.x, rstLineInfo.m_stStartPos.y, NULL);

		LineTo(a_hDC,
			rstLineInfo.m_stEndPos.x, rstLineInfo.m_stEndPos.y);
	}
}

LRESULT Example02::HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	// ��ư�� ������ ���
	//if (a_wParams != 0) {
	//	m_oLineInfoList.back().m_stEndPos.x = LOWORD(a_lParams);
	//	m_oLineInfoList.back().m_stEndPos.y = HIWORD(a_lParams);
	//
	//	/*
	//	InvalidateRect �Լ��� ����ϸ� �������� Ư�� ������ ��ȿȭ ��Ű�� ����
	//	�����ϴ�. (��, �����찡 ���ϰ� �ִ� Ư�� ������ ��ȿȭ ��ų ��� �ش�
	//	������ ��ȿȭ �� ������ �ٽ� �׸��� ���ؼ� WM_PAINT �޼����� �߻���Ų��.)
	//
	//	����, �ش� �Լ��� ����ϸ� ������ �׷��� �̹��� ���� ����ϰ� �����
	//	���� �����ϴ�.
	//	*/
	//	//InvalidateRect(GET_WND_HANDLE(), NULL, TRUE);
	//}

	return 0;
}

LRESULT Example02::HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams, bool a_bIsBtnDown)
{
	//// ���콺 ��ư ������ ���
	//if (a_bIsBtnDown) {
	//	STLineInfo stLineInfo = {
	//		{ LOWORD(a_lParams), HIWORD(a_lParams) },
	//		{ LOWORD(a_lParams), HIWORD(a_lParams) }
	//	};
	//
	//	m_oLineInfoList.push_back(stLineInfo);
	//}

	return 0;
}

LRESULT Example02::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	/*
	GetDC �Լ��� Ư�� �����찡 ���ϰ� �ִ� ����̽� ���ؽ�Ʈ�� ��������
	������ �����Ѵ�. WinAPI �Լ� �߿� Ư�� �����쿡 �׸��� ����ϴ� �Լ���
	��� ����̽� ���ؽ�Ʈ�� �ʿ�� �ϱ� ������ Ư�� �����쿡 �׸��� �׸���
	�ʹٸ� �ݵ�� �ش� �Լ��� ����ؼ� ����̽� ���ؽ�Ʈ�� �����;��Ѵ�.

	����, �ش� �Լ��� ���ؼ� ������ ����̽� ���ؽ�Ʈ�� �ݵ�� ���̻� �ʿ䰡
	���� ��� ReleaseDC �Լ��� ����ؼ� �ٽ� ��ȯ��������Ѵ�.
	(��, GetDC �Լ��� ����ؼ� ����̽� ���ؽ�Ʈ�� ������ �� �ش� �Լ���
	ȣ������ �ʴ´ٸ� ���� ���� ��ǻ���� �ڿ��� �þ�� ������ �ȴ�.)

	��, WN_PAINT �޼����� �߻����� ��쿡�� GetDC �Լ��� �ƴ� BeginPaint �Լ���
	���� ����̽� ���ؽ�Ʈ�� �������� ���� ��õ�Ѵ�. �̴� �ش� �Լ��� ���ؼ�
	����̽� ���ؽ�Ʈ�� ���� �� ��� �ش� �ڿ� �̿ܿ� �׸��� �׸��� ���� �ΰ� ������
	�� �� �ֱ� �����̴�.

	�׸��� �ش� �Լ��� ���ؼ� ������ ����̽� ���ؽ�Ʈ�� �ݵ�� EndPaint �Լ���
	����ؼ� �ڿ��� ��ȯ������Ѵ�.
	*/
	PAINTSTRUCT stPaintStruct;
	BeginPaint(GET_WND_HANDLE(), &stPaintStruct);

	//HDC hDC = GetDC(GET_WND_HANDLE());

	/*
	__try ~ __finally ������ ����ϸ� Ư�� �Լ��� ���� ���߿� �ߴ� �Ǿ���
	��� �ݵ�� ����ǵ��� �����ϴ� ������ �ۼ��ϴ� ���� �����ϴ�.
	(��, �ش� ������ ����ϸ� ȹ�� �� �ڿ��� �� �� �����ϰ� �����ϴ� ����
	�����ϴ�.)
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
