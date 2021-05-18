#include "CWndApp.h"
#include "../Manager/CTimeManager.h"

//#define GET_MSG_ENABLE	
#define PEEK_MSG_ENABLE	

//���� ����
static CWndApp *g_pInst = nullptr;

//stdcall -> �Լ��� ȣ���ϸ� ȣ��� ������ ���ư� ������ 
//cdecl -> �Լ��� ȣ���� ������ ����� �� ������
/*
�������� �ü�� �󿡼� �����Ǵ� ���α׷��� �̺�Ʈ�� ������� �����ϴ� ���α׷��̱⶧���� �̺�Ʈ�� �������� ���� ��� �ƹ��� cpu�ڿ��� ��������ʴ� Ư¡�� �ִ�.

�� winapi�� ����ؼ� ���۵� ���α׷��� �ݵ�� �����쿡�� �߻��� �̺�Ʈ(�޼���)�� ó���ϱ� ���� �Լ��� �����ؾ��Ѵ�
*/
//������ ���ν���//callback == �Լ� ȣ�� �Ծ�
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	static CWndApp *pWndApp = nullptr;

	switch (a_nMsg)
	{
	case WM_CREATE:
	{
		auto pstCreateStruct = (CREATESTRUCT*)a_lParams;//long ���� �ּҰ����� ��ȯ
		pWndApp = static_cast<CWndApp*>(pstCreateStruct->lpCreateParams);//���� ���� �ּҿ��� ����Ҽ��ֵ��� ��ȯ
	}break;
	}

	//������ ���ø����̼��� �����Ұ��
	if (pWndApp != nullptr)
	{
		return pWndApp->HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
	}
	/*
	DefWindowProc �Լ��� ������ �޼����� ó���ϴ� ������ �����Ѵ�
	�� ������ ���ø����̼��� �����Ҷ� �ش� ���α׷��� ������ �´� �޼����� ó���ϰ� ������ �޼����� �ش� �Լ��� ���������ν� 
	���ʿ��� �޼����� ó������ �ʾƵ� �ȴ�
	*/
	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}


CWndApp::CWndApp(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize)
{
	g_pInst = this;
	ZeroMemory(&m_stWndCls, sizeof(m_stWndCls));
	/*
	AllocConsole �Լ��� �ܼ�â�� �����ϴ� ������ �����Ѵ� �� �ش��Լ��� 
	������ �ܼ�â�� ���� �����͸� ����� �ϱ� ���� ��Ʈ���� ������� �ʴ� �����̱�
	������ �ش� �ܼ�â�� �����͸� �� ��� �ϱ� ���ؼ��� 
	�ݵ�� freopen�Լ��� ����ؼ� ��Ʈ���� ���� ��������Ѵ�
	*/
	//�ܼ�â�� �����Ǿ��� ���
	if (AllocConsole())
	{
		m_pstRStream = freopen("CONIN$", "rb", stdin);//���� �� ����    //������ ���������� �ܼ� ���ῡ ����ϴ� ���� �̸� CONIN$
		m_pstWStream = freopen("CONOUT$", "wb", stdout);
	}
}

CWndApp::~CWndApp(void)
{
	SAFE_FCLOSE(m_pstRStream);
	SAFE_FCLOSE(m_pstWStream);

	FreeConsole();
	UnregisterClass(m_stWndCls.lpszClassName, m_stWndCls.hInstance);
}

void CWndApp::Init(void)
{
	m_hWnd = this->CreateWnd(&m_stWndCls);
	
	GET_TIME_MANAGER()->Init();
}

int CWndApp::Run(void)
{
	this->Init();

	/*
	UpdateWindow�Լ��� ����ϸ� �޼��� ť�� �����ϴ� �޼������� �����ϴ� ������ �����Ѵ�
	���� showWindow �Լ��� ������ �����츦 ȭ��� ������ִ� ������ �����Ѵ�
	�� �����츦 ������ �� �ش� �Լ��� ������� �ʾ��� ��� ������� ������ �Ϸ�� ���������� ���� ���̵��� ����� ���� �ʴ� ���·� ��׶����
	�����Ѵٴ� ���� �˼��ִ�.
	*/
	UpdateWindow(m_hWnd);			  //�޼��� ť �ڷᱸ�� ������ ����  //�̺�Ʈ�� �ٷ� �ٷ� ó���ϴ� ���� �ƴ� ������ �ɶ� ó�� �޼��� ť�� ���� ����  
	ShowWindow(m_hWnd, m_nShowOpts);//���� ���̵��� ����� �Լ�

	return this->RunMsgLoop();
}

void CWndApp::Update(float a_fDeltaTime)
{
	GET_TIME_MANAGER()->Update(a_fDeltaTime);
}

void CWndApp::Render(HDC a_hDC)
{
	this->PreRender(a_hDC);
	this->DoRender(a_hDC);
	this->PostRender(a_hDC);
}

SIZE CWndApp::GetWndSize(void) const
{
	return m_stWndSize;
}

HWND CWndApp::GetWndHandle(void) const
{
	return m_hWnd;
}

HINSTANCE CWndApp::GetInstHandle(void) const
{
	return m_hInst;
}

CWndApp * CWndApp::GetInst(void)
{
	return g_pInst;
}

LRESULT CWndApp::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	switch (a_nMsg)
	{
	case WM_SIZE: return this->HandleSizeMsg(a_wParams, a_lParams);
	case WM_PAINT: return this->HandlePaintMsg(a_wParams, a_lParams);
	case WM_DESTROY:return this->HandleDestroyMsg(a_wParams, a_lParams);
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

int CWndApp::RunMsgLoop(void)
{
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

#if defined GET_MSG_ENABLE
	/*
	�Ϲ������� ������ �� �߻��� �޼����� �޼��� ť�� �����Ǳ� ������ ���ø����̼���
	�޼����� ó�� �� �� �ִ� ��Ȳ�� �߻����� ��� �޼��� ť�κ��� �߻� �� �޼�����
	������ �ش� �޼����� �´� ó���� �� �ʿ䰡 �ִ�. �̶�, �޼��� ť�κ��� �߻� ��
	�޼����� �������� ������ �����ϴ� �Լ��� GetMessage �Լ��̴�.

	����, GetMessage �Լ��� ��ŷ �Լ��̱� ������ ���� �ش� �Լ��� ȣ�� �� ������
	�޼��� ť�� �ƹ��� �޼����� �������� ���� ��� ���ο� �޼����� �߻� �� �� ����
	ȣ���� �Ϸ���� �ʰ� ����ϴ� Ư¡�� �ִ�. (��, �ǽð����� ������ �ʿ��� ���ø����̼���
	���� �� ���� �ش� �Լ��� ������� �ʴ� ���� ����.)

	TranslateMessage �Լ��� ���������� WM_CHAR �޼����� �߻���Ű�� ������ �����Ѵ�.
	(��, WM_CHAR �޼��� ó���� �ʿ� ���� ��� �ش� �Լ��� ȣ������ �ʾƵ� �����ϴ�.)

	DispatchMessage �Լ��� ���������� �޼����� �����ϴ� ������ �����ϸ�, �� ���
	�ش� �޼����� ó���ϱ� ���� ������ ���ν��� �Լ��� ȣ��ȴ�. (��, ������ ���ν���
	�Լ��� ��������� ȣ���ϴ� ���� �ƴ϶� DispatchMessage �Լ��� ���ؼ� ȣ��Ǵ�
	������ ���ϴ� ���� �ٶ����� �޼��� ���� �����̴�.)
	*/
	while (GetMessage(&stMsg, NULL, 0, 0)) {
		TranslateMessage(&stMsg);
		DispatchMessage(&stMsg);
}
#elif defined PEEK_MSG_ENABLE
	/*
	PeekMessage �Լ��� GetMessage �Լ��� ���������� �޼��� ť�κ��� �߻��� �޼�����
	�������� ������ �����Ѵ�. ��, �ش� �Լ��� GetMessage �Լ��� �޸� �޼��� ť��
	����� ��� ���ο� �޼����� ����ϴ� ���� �ƴ϶� �ٷ� �Լ� ȣ���� ����Ǵ� Ư¡��
	�ִ�. (��, �ش� �Լ��� ����ϸ� �ǽð� ó���� �� �� �ִ� ���α׷��� �����ϴ� ����
	�����ϴ�.)
	*/
	while (stMsg.message != WM_QUIT) {
		// ������ �޼����� ���� �� ��� 
		if (PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&stMsg);
			DispatchMessage(&stMsg);
		}

		/*
		CreateCompatibleDC�Լ��� Ư�� �����찡 ���ϰ� �ִ� ����̽� ���ؽ�Ʈ�� ȣȯ�Ǵ� �纻 ����̽� ���ؽ�Ʈ�� �����ϴ� ������ �����Ѵ�
		*/
		HDC hDC = GetDC(m_hWnd);
		HDC hMemDC = CreateCompatibleDC(hDC);

		_try
		{
			RECT stWndRect = {
				0,0,m_stWndSize.cx,m_stWndSize.cy
			};

			/*
			SelectObject�� ����̽� ���ؽ�Ʈ�� GDI��ü�� �����ϴ� ������ �����Ѵ�
			�� �ش��Լ��� ����ؼ� ����̽� ���ؽ�Ʈ�� ���� GDI��ü�� ���������ν� 
			�پ��� ȿ���� ���� �̹������� �׸��� ���� �����ϴ�
			*/
			HBITMAP hPrevBitmap = (HBITMAP)SelectObject(hMemDC,m_hBitmap);
			FillRect(hMemDC, &stWndRect, m_stWndCls.hbrBackground);

			

			this->Update(GET_DELTA_TIME());
			this->LateUpdate(GET_DELTA_TIME());

			this->Render(hMemDC);

			//BitBlt���� �״�� ��Ʈ�� ����
			/*
			StretchBlt�� Ư�� ����̽� ���ؽ�Ʈ�� �����Ǿ��ִ� ��Ʈ���� �ٸ� ��Ʈ������ �����ϴ� ������ �����Ѵ� ���� �ش� ������ �ϴ� �Լ��δ�
			BitBlt�� ������ �������� ���� ��Ʈ���� ũ�⸦ ���� �Ҽ��ִ��� �����̴�. BitBlt�Լ��� ���� ��Ʈ���� ũ�⸦ �����Ҽ����� ������ �����Ѵ�
			*/
			StretchBlt(hDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, 
				hMemDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, SRCCOPY);
			//���� �������� �����°� �ʼ���
			SelectObject(hMemDC, hPrevBitmap);
		}
		__finally
		{
			SAFE_DEL_DC(hMemDC);
			SAFE_RELEASE_DC(m_hWnd, hDC);
		}
	}
#endif			// #if defined GET_MSG_ENABLE

	return stMsg.wParam;
}

LRESULT CWndApp::HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams)
{

//��ũ���Լ� LOWORD���� 2����Ʈ,  HIWORD���� 2����Ʈ �����͸� �������� ���� �����ϴ�     
	m_stWndSize.cx = LOWORD(a_lParams);
	m_stWndSize.cy = HIWORD(a_lParams);

	HDC hDC = GetDC(m_hWnd);
	SAFE_DEL_GDI_OBJ(m_hBitmap);
	
	
	_try
	{
		/*
		CreateCompatibleBitmap �Լ��� Ư�� �������� Ŭ���̾�Ʈ ������ ȣȯ�Ǵ� ���ο� ������ �����ϴ¿����� �����Ѵ� 
		�� �ش� �Լ��� ����ϸ� ����ڿ��� �������� Ŭ���̾�Ʈ ������ �ƴ� ���� ��ũ�� ������ �����ϴ� ���� �����ϴ�
		*/
		m_hBitmap = CreateCompatibleBitmap(hDC,m_stWndSize.cx,m_stWndSize.cy);
	}
	__finally
	{
		SAFE_RELEASE_DC(m_hWnd, hDC);
	}
	return 0;
}

LRESULT CWndApp::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)
{
	return 0;
}

LRESULT CWndApp::HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams)
{	/*
	WINAPI�޼��� ���� ���
	PostMessage//������ �޼����� �޼��� ť�� �ִ°���
	SendMessage//������ �޼����� �ٷ� ������ ���ν����� ȣ���Ͽ� ����
	*/
	PostQuitMessage(0);//������� ���α׷��� �����̴� //�����찡 ������ ���α׷��� �������� ����//�ڿ��� �����ϱ� ���ؼ� �޼��� ť�� �ִ� ����� ��ȣ��
	//wm_quit �޼����� �޼���ť�� �����ϴ� ���� �����Ѵ�
	return 0;
}

HWND CWndApp::CreateWnd(WNDCLASS * a_pstOutWndClass)
{
	/*
	wndclass ����ü�� Ŀ���� �����츦 �����ϱ� ���� �Ӽ��� �����ϴ� ������ �����Ѵ�
	��(�����츦 �����ϱ� ���ؼ��� �������� �ü���� �ش� ������ ������ ���� ��û�� �ʿ��ѵ�
	�⺻������ �������� �ü���� �ش� �����쿡 ���� ������ �������� �ʱ� ������ �̸� �����ϰ� �ϱ� ���ؼ���
	wndclass�� ���ؼ� Ŀ���� �����쿡 ���� �Ӽ��� ������ �ش� ������ registerclass�Լ��� ���ؼ� �������� �ü���� �˷�����Ѵ�

	zeromemory �Լ��� ������ �޸𸮸� 0���� �ʱ�ȭ ��Ű�� ������ �����Ѵ�
	�� ���������� memset�Լ��� ������ �������� �Ǿ��ִ�.

	*/
	WNDCLASS stWndCls;//�츮�� ���� ������ ������ ������ ����
	ZeroMemory(&stWndCls, sizeof(stWndCls));//memset�� ���� ���� �� (�ʱ�ȭ)

	stWndCls.style = CS_VREDRAW | CS_HREDRAW;
	stWndCls.cbClsExtra = 0;//���� ����
	stWndCls.cbWndExtra = 0;//���� ����
	stWndCls.hInstance = m_hInst;//������ �����찡 � ���ø����̼ǿ��� �����ϴ��� (�ڱ��ڽſ��� �����Ѵٴ� �̾߱�)
	stWndCls.lpfnWndProc = WndProc;//�����쿡�� �߻��� �̺�Ʈ �޼����� �̰��� ���ؼ� ó���Ѵ�
	stWndCls.hIcon = LoadIcon(NULL, IDI_APPLICATION);//���ø����̼� �������� �⺻���� ����ϰڴ�
	stWndCls.hCursor = LoadCursor(NULL, IDC_ARROW);//���ø����̼� ���콺�� �⺻���� ����ϰڴ�
	stWndCls.hbrBackground = (HBRUSH)GetStockObject(COLOR_WINDOW + 1);//���ø����̼� ���� ����
	stWndCls.lpszMenuName = _T("");//��Ƽ����Ʈ�� �����ڵ��� ���̾��� ����ϱ� ���ؼ� _T�� ���� 
	//_T ��ũ���Լ��� ���ڿ� ����� ������Ʈ ������ ���� ��Ƽ����Ʈor�����ڵ� ���·� �������ִ� ���� ����
	//TCHARŸ������ ���ڿ��� ǥ���Ұ�� �ݵ�� _T�� ����ؼ� ���ڿ��� �����ؾ��Ѵ�
	stWndCls.lpszClassName = _T("Example");
	/*
	create window �Լ���  ������ â �����ϴ¿��� ����
	������ ������� ������ Ŭ���� �ĺ��ڸ� �䱸�ϸ� �ش� �Ű� ������ ������ �ĺ��ڿ� ���� ���� Ư¡�� ���ϴ� �����츦 �����ϴ� ���� �����ϴ�
	�� �ش� �Լ��� ����ϸ� �������� �ü���� �����ϴ� ������ �̿ܿ� Ŀ���� �Ӽ��� ���ϴ� �����츦 �����ϴ� ���� �����ϴ�
	*/
	RegisterClass(&stWndCls);
	CopyMemory(a_pstOutWndClass, &stWndCls, sizeof(stWndCls));

	RECT stWndRect = { 0,0,m_stWndSize.cx,m_stWndSize.cy };
	/*
	AdjustWindowRect�Լ��� �־��� Ŭ���̾�Ʈ ������ ������� ������ ��Ÿ�Ͽ� �����Ǵ� 
	������ ��ü ũ��� �ش� ������ �������ִ� ������ �����Ѵ�
	�� CreateWindow�Լ����� �־����� �������� �ʺ� ���̴� Ŭ���̾�Ʈ������ ������ ������ ��ģ ������ ��ü ũ���̱�
	������ Ư�� Ŭ���̾�Ʈ ������ ���ϴ� �����츦 �����ϱ� ���ؼ��� �ݵ�� �ش� �Լ��� ����ؼ� ������ ũ�⸦ ����ؾ��Ѵ�

	�⺻������ �������� ��ǥ��� ȭ���� �»���� �������� �ϴ� ȭ�� ��ǥ�踦 ����Ѵ�
	�̶� �������� Ư�� ������ ǥ���ϴ� ����� LT/RB, XY/WH������� �����Ǹ�
	LT/RB����� ������ �»���� �������� 0,0 ������ǥ���� ���ϸ� 
	XY/WH����� xy��ġ ���� �ʺ� ���� ���� ����ϴ� ��� ��ǥ�� ������ �ִ�.
	*/
	AdjustWindowRect(&stWndRect, WS_OVERLAPPEDWINDOW, FALSE);

	return CreateWindow(
		stWndCls.lpszClassName,  //������ Ŭ���� �̸�(�ĺ���)
		stWndCls.lpszClassName,  //������ �̸�					//������â�� ������ ���� �����
		WS_OVERLAPPEDWINDOW,	 //������ ��Ÿ��					//WS_OVERLAPPEDWINDOW�� ������ ���� �Ӽ��� ��ģ ��ũ�� ����
		CW_USEDEFAULT,			 //������ X��ġ					//�⺻���� ����
		CW_USEDEFAULT,			 //������ Y��ġ					//�⺻���� ����	
		stWndRect.right-stWndRect.left,			 //������ �ʺ�					//�⺻���� ����
		stWndRect.bottom - stWndRect.top,		 //������ ����					//�⺻���� ����
		GetDesktopWindow(),		 //�θ������� �ڵ�				//�� �θ��� ������� ����ȭ�� �� �̰� ����Ǹ� ����ȭ�鳪�� 
		NULL,					 //�޴� �ڵ�
		stWndCls.hInstance,	     //�ν��Ͻ� �ڵ�
		this);					 //�߰� ���� �Ű�����

}

