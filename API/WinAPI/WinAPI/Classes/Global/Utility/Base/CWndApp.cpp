#include "CWndApp.h"
#include "../Manager/CTimeManager.h"

//#define GET_MSG_ENABLE	
#define PEEK_MSG_ENABLE	

//전역 변수
static CWndApp *g_pInst = nullptr;

//stdcall -> 함수를 호출하면 호출된 곳으로 돌아가 정리함 
//cdecl -> 함수를 호출한 곳으로 결과가 들어가 정리함
/*
윈도우즈 운영체제 상에서 구동되는 프로그램은 이벤트를 기반으로 동작하는 프로그램이기때문에 이벤트가 존재하지 않을 경우 아무런 cpu자원도 사용하지않는 특징이 있다.

즉 winapi를 사용해서 제작된 프로그램은 반드시 윈도우에서 발생한 이벤트(메세지)를 처리하기 위한 함수를 제공해야한다
*/
//윈도우 프로시져//callback == 함수 호출 규약
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	static CWndApp *pWndApp = nullptr;

	switch (a_nMsg)
	{
	case WM_CREATE:
	{
		auto pstCreateStruct = (CREATESTRUCT*)a_lParams;//long 형을 주소값으로 변환
		pWndApp = static_cast<CWndApp*>(pstCreateStruct->lpCreateParams);//받은 값을 주소에서 사용할수있도록 변환
	}break;
	}

	//윈도우 어플리케이션이 존재할경우
	if (pWndApp != nullptr)
	{
		return pWndApp->HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
	}
	/*
	DefWindowProc 함수는 윈도우 메세지를 처리하는 역할을 수행한다
	즉 윈도우 어플리케이션을 제작할때 해당 프로그램의 목적에 맞는 메세지만 처리하고 나머지 메세지는 해당 함수에 전달함으로써 
	불필요한 메세지는 처리하지 않아도 된다
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
	AllocConsole 함수는 콘솔창을 생성하는 역할을 수행한다 단 해당함수로 
	생성된 콘솔창은 아직 데이터를 입출력 하기 위한 스트림이 연결되지 않는 상태이기
	때문에 해당 콘솔창에 데이터를 입 출력 하기 위해서는 
	반드시 freopen함수를 사용해서 스트림을 연결 시켜줘야한다
	*/
	//콘솔창이 생성되었을 경우
	if (AllocConsole())
	{
		m_pstRStream = freopen("CONIN$", "rb", stdin);//파일 재 오픈    //윈도우 내부적으로 콘솔 연결에 사용하는 파일 이름 CONIN$
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
	UpdateWindow함수를 사용하면 메세지 큐에 존재하는 메세지들을 정리하는 역할을 수행한다
	또한 showWindow 함수는 생성된 윈도우를 화면상에 출력해주는 역할을 수행한다
	즉 윈도우를 생성한 후 해당 함수를 사용하지 않았을 경우 윈도우는 생성이 완료된 상태이지만 눈에 보이도록 출력이 되지 않는 상태로 백그라운드상에
	존재한다는 것을 알수있다.
	*/
	UpdateWindow(m_hWnd);			  //메세지 큐 자료구조 형태의 버퍼  //이벤트를 바로 바로 처리하는 것이 아닌 여유가 될때 처리 메세지 큐를 비우는 역할  
	ShowWindow(m_hWnd, m_nShowOpts);//눈에 보이도록 만드는 함수

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
	일반적으로 윈도우 상에 발생한 메세지는 메세지 큐에 보관되기 때문에 어플리케이션은
	메세지를 처리 할 수 있는 상황이 발생했을 경우 메세지 큐로부터 발생 된 메세지를
	가져와 해당 메세지에 맞는 처리를 할 필요가 있다. 이때, 메세지 큐로부터 발생 된
	메세지를 가져오는 역할을 수행하는 함수가 GetMessage 함수이다.

	또한, GetMessage 함수는 블럭킹 함수이기 때문에 만약 해당 함수를 호출 한 시점에
	메세지 큐에 아무런 메세지가 존재하지 않을 경우 새로운 메세지가 발생 할 때 까지
	호출이 완료되지 않고 대기하는 특징이 있다. (즉, 실시간으로 동작이 필요한 어플리케이션을
	제작 할 때는 해당 함수를 사용하지 않는 것이 좋다.)

	TranslateMessage 함수는 내부적으로 WM_CHAR 메세지를 발생시키는 역할을 수행한다.
	(즉, WM_CHAR 메세지 처리가 필요 없을 경우 해당 함수는 호출하지 않아도 무방하다.)

	DispatchMessage 함수는 내부적으로 메세지를 전달하는 역할을 수행하며, 그 결과
	해당 메세지를 처리하기 위한 윈도우 프로시저 함수가 호출된다. (즉, 윈도우 프로시저
	함수는 명시적으로 호출하는 것이 아니라 DispatchMessage 함수에 의해서 호출되는
	구조를 지니는 것이 바람직한 메세지 루프 구조이다.)
	*/
	while (GetMessage(&stMsg, NULL, 0, 0)) {
		TranslateMessage(&stMsg);
		DispatchMessage(&stMsg);
}
#elif defined PEEK_MSG_ENABLE
	/*
	PeekMessage 함수는 GetMessage 함수와 마찬가지로 메세지 큐로부터 발생한 메세지를
	가져오는 역할을 수행한다. 단, 해당 함수는 GetMessage 함수와 달리 메세지 큐가
	비었을 경우 새로운 메세지를 대기하는 것이 아니라 바로 함수 호출이 종료되는 특징이
	있다. (즉, 해당 함수를 사용하면 실시간 처리를 할 수 있는 프로그램을 제작하는 것이
	가능하다.)
	*/
	while (stMsg.message != WM_QUIT) {
		// 윈도우 메세지가 존재 할 경우 
		if (PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&stMsg);
			DispatchMessage(&stMsg);
		}

		/*
		CreateCompatibleDC함수는 특정 윈도우가 지니고 있는 디바이스 컨텍스트와 호환되는 사본 디바이스 컨텍스트를 생성하는 역할을 수행한다
		*/
		HDC hDC = GetDC(m_hWnd);
		HDC hMemDC = CreateCompatibleDC(hDC);

		_try
		{
			RECT stWndRect = {
				0,0,m_stWndSize.cx,m_stWndSize.cy
			};

			/*
			SelectObject는 디바이스 컨텍스트에 GDI객체를 설정하는 역할을 수행한다
			즉 해당함수를 사용해서 디바이스 컨텍스트에 여러 GDI객체를 설정함으로써 
			다양한 효과를 지닌 이미지등을 그리는 것이 가능하다
			*/
			HBITMAP hPrevBitmap = (HBITMAP)SelectObject(hMemDC,m_hBitmap);
			FillRect(hMemDC, &stWndRect, m_stWndCls.hbrBackground);

			

			this->Update(GET_DELTA_TIME());
			this->LateUpdate(GET_DELTA_TIME());

			this->Render(hMemDC);

			//BitBlt원본 그대로 비트맵 복사
			/*
			StretchBlt은 특정 디바이스 컨텍스트에 설정되어있는 비트맵을 다른 비트맵으로 복사하는 역할을 수행한다 또한 해당 역할을 하는 함수로는
			BitBlt가 있으며 차이점은 원본 비트맵의 크기를 변결 할수있는지 유무이다. BitBlt함수는 원본 비트맵의 크기를 변경할수없는 단점이 존재한다
			*/
			StretchBlt(hDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, 
				hMemDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, SRCCOPY);
			//설정 이전으로 돌리는거 필수임
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

//메크로함수 LOWORD하위 2바이트,  HIWORD상위 2바이트 데이터를 가져오는 것이 가능하다     
	m_stWndSize.cx = LOWORD(a_lParams);
	m_stWndSize.cy = HIWORD(a_lParams);

	HDC hDC = GetDC(m_hWnd);
	SAFE_DEL_GDI_OBJ(m_hBitmap);
	
	
	_try
	{
		/*
		CreateCompatibleBitmap 함수는 특정 윈도우의 클라이언트 영역과 호환되는 새로운 영역을 생성하는역할을 수행한다 
		즉 해당 함수를 사용하면 사용자에게 보여지는 클라이언트 영역이 아닌 오프 스크린 영역을 생성하는 것이 가능하다
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
	WINAPI메세지 전달 방식
	PostMessage//지정된 메세지를 메세지 큐에 넣는거임
	SendMessage//지정된 메세지를 바로 윈도우 프로시저를 호출하여 전달
	*/
	PostQuitMessage(0);//윈도우와 프로그램은 별개이다 //윈도우가 닫히면 프로그램이 닫히도록 제작//자원을 정리하기 위해서 메세지 큐에 넣는 방식을 선호함
	//wm_quit 메세지를 메세지큐에 전달하는 역할 수행한다
	return 0;
}

HWND CWndApp::CreateWnd(WNDCLASS * a_pstOutWndClass)
{
	/*
	wndclass 구조체는 커스텀 윈도우를 생성하기 위한 속성을 지정하는 역할을 수행한다
	즉(윈도우를 생성하기 위해서는 윈도우즈 운영체제에 해당 윈도우 생성에 대한 요청이 필요한데
	기본적으로 윈도우즈 운영체제는 해당 윈도우에 대한 정보가 존재하지 않기 때문에 이를 가능하게 하기 위해서는
	wndclass를 통해서 커스텀 윈도우에 대한 속성을 지정후 해당 정보를 registerclass함수를 통해서 윈도우즈 운영체제에 알려줘야한다

	zeromemory 함수는 지정된 메모리를 0으로 초기화 시키는 역할을 수행한다
	즉 내부적으로 memset함수와 동일한 구문으로 되어있다.

	*/
	WNDCLASS stWndCls;//우리가 만들 윈도우 정보를 가지고 있음
	ZeroMemory(&stWndCls, sizeof(stWndCls));//memset과 같은 일을 함 (초기화)

	stWndCls.style = CS_VREDRAW | CS_HREDRAW;
	stWndCls.cbClsExtra = 0;//쓰지 않음
	stWndCls.cbWndExtra = 0;//쓰지 않음
	stWndCls.hInstance = m_hInst;//생성한 윈도우가 어떤 어플리케이션에서 동작하는지 (자기자신에서 실행한다는 이야기)
	stWndCls.lpfnWndProc = WndProc;//윈도우에서 발생한 이벤트 메세지를 이것을 통해서 처리한다
	stWndCls.hIcon = LoadIcon(NULL, IDI_APPLICATION);//어플리케이션 아이콘은 기본으로 사용하겠다
	stWndCls.hCursor = LoadCursor(NULL, IDC_ARROW);//어플리케이션 마우스는 기본으로 사용하겠다
	stWndCls.hbrBackground = (HBRUSH)GetStockObject(COLOR_WINDOW + 1);//어플리케이션 배경색 지정
	stWndCls.lpszMenuName = _T("");//멀티바이트와 유니코드의 차이없이 출력하기 위해서 _T를 붙임 
	//_T 메크로함수는 문자열 상수를 프로젝트 설정에 따라서 멀티바이트or유니코드 형태로 변경해주는 역할 수행
	//TCHAR타입으로 문자열을 표현할경우 반드시 _T를 사용해서 문자열을 지정해야한다
	stWndCls.lpszClassName = _T("Example");
	/*
	create window 함수는  윈도우 창 생성하는역할 수행
	생성할 윈도우는 윈도우 클래스 식별자를 요구하며 해당 매개 변수에 지정된 식별자에 따라 여러 특징을 지니는 윈도우를 생성하는 것이 가능하다
	즉 해당 함수를 사용하면 윈도우즈 운영체제가 제공하는 윈도우 이외에 커스텀 속성을 지니는 윈도우를 생성하는 것이 가능하다
	*/
	RegisterClass(&stWndCls);
	CopyMemory(a_pstOutWndClass, &stWndCls, sizeof(stWndCls));

	RECT stWndRect = { 0,0,m_stWndSize.cx,m_stWndSize.cy };
	/*
	AdjustWindowRect함수는 주어진 클라이언트 영역을 기반으로 윈도우 스타일에 대응되는 
	윈도우 전체 크기로 해당 영역을 보정해주는 역할을 수행한다
	즉 CreateWindow함수에서 주어지는 윈도우의 너비 높이는 클라이언트영역과 윈도우 영역을 합친 윈도우 전체 크기이기
	때문에 특정 클라이언트 영역을 지니는 윈도우를 생성하기 위해서는 반드시 해당 함수를 사용해서 윈도우 크기를 계산해야한다

	기본적으로 윈도우의 좌표계는 화면의 좌상단을 기준으로 하는 화면 좌표계를 사용한다
	이때 윈도우의 특정 영역을 표현하는 방식은 LT/RB, XY/WH방식으로 구별되며
	LT/RB방식은 윈도우 좌상단을 기준으로 0,0 절대좌표값을 지니며 
	XY/WH방식은 xy위치 부터 너비 높이 값을 계산하는 상대 좌표를 가지고 있다.
	*/
	AdjustWindowRect(&stWndRect, WS_OVERLAPPEDWINDOW, FALSE);

	return CreateWindow(
		stWndCls.lpszClassName,  //윈도우 클래스 이름(식별자)
		stWndCls.lpszClassName,  //윈도우 이름					//윈도우창을 여러개 쓸때 사용함
		WS_OVERLAPPEDWINDOW,	 //윈도우 스타일					//WS_OVERLAPPEDWINDOW에 지정된 여러 속성을 합친 매크로 변수
		CW_USEDEFAULT,			 //윈도우 X위치					//기본으로 설정
		CW_USEDEFAULT,			 //윈도우 Y위치					//기본으로 설정	
		stWndRect.right-stWndRect.left,			 //윈도우 너비					//기본으로 설정
		stWndRect.bottom - stWndRect.top,		 //윈도우 높이					//기본으로 설정
		GetDesktopWindow(),		 //부모윈도우 핸들				//내 부모의 윈도우는 바탕화면 즉 이게 종료되면 바탕화면나옴 
		NULL,					 //메뉴 핸들
		stWndCls.hInstance,	     //인스턴스 핸들
		this);					 //추가 생성 매개변수

}

