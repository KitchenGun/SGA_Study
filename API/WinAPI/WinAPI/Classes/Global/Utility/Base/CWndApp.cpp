#include "CWndApp.h"

//stdcall -> �Լ��� ȣ���ϸ� ȣ��� ������ ���ư� ������ 
//cdecl -> �Լ��� ȣ���� ������ ����� �� ������
/*
�������� �ü�� �󿡼� �����Ǵ� ���α׷��� �̺�Ʈ�� ������� �����ϴ� ���α׷��̱⶧���� �̺�Ʈ�� �������� ���� ��� �ƹ��� cpu�ڿ��� ��������ʴ� Ư¡�� �ִ�.

�� winapi�� ����ؼ� ���۵� ���α׷��� �ݵ�� �����쿡�� �߻��� �̺�Ʈ(�޼���)�� ó���ϱ� ���� �Լ��� �����ؾ��Ѵ�
*/
//������ ���ν���//callback == �Լ� ȣ�� �Ծ�
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}


CWndApp::CWndApp(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize)
{
	ZeroMemory(&m_stWndCls, sizeof(m_stWndCls));
}

CWndApp::~CWndApp(void)
{
	UnregisterClass(m_stWndCls.lpszClassName, m_stWndCls.hInstance);
}

void CWndApp::Init(void)
{
	m_hWnd = this->CreateWnd(&m_stWndCls);
	
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

LRESULT CWndApp::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams)
{
	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

int CWndApp::RunMsgLoop(void)
{
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

	/*
	������ �� �߻��� �޼����� �޼��� ť�� �����Ǳ� ������ ���ø����̼���
	�޼����� ó���Ҽ��ִ� ��Ȳ�� �߻����� ��� �޼��� ť�κ��� �߻��� �޼����� ������ �ش� �޼����� �´� ó���� �� �ʿ䰡 �ִ�.
	�̶� �޼��� ť�κ��� �߻��� �޼����� �������� ������ �����ϴ� �Լ��� GetMessage�Լ��̴�

	���� GetMessage�Լ��� ��ŷ �Լ��̱� ������ �ش� �Լ� ȣ�� �������� �޼����� ������ ����Ѵ� ȣ���� �Ϸ���� �ʰ� ����Ѵ�
	�� �ǽð����� ������ �ʿ��� ���ø����̼� ���� �Ҷ��� �ش� �Լ��� ������� �ʴ� ���� ����

	TranslateMessage�Լ��� ���������� WM_CHAR�޼����� �߻���Ű�� ������ �����Ѵ�
	WM_CHAR �޼��� ó���� �ʿ���� ��� �ش� �Լ��� ȣ������ �ʾƵ� �����ϴ�

	DispatchMessage�Լ��� ���������� �޼����� �����ϴ� ������ �����ϸ� �� ���
	�ش� �޼����� ó���ϱ� ���� ������ ���ν��� �Լ��� ȣ�� �ȴ� �� ������ ���ν��� �Լ���
	��������� ȣ���ϴ� ���� �ƴ϶� DispatchMessage�Լ��� ���ؼ� ȣ��Ǵ� ������ ���ϴ� ���� �ٶ����� �޼��� ���� �����̴�.
	*/
	while (GetMessage(&stMsg, NULL, 0, 0))//�޼��� ť�� ���� �޼����� ������ / �޼����� ������ ����Ѵ� / ���� �޼�������� false�� �������� �ʴ´�
	{
		TranslateMessage(&stMsg);//�ᵵ �ǰ� �Ƚᵵ �� WM_CHAR(Ű���尡 ���ȴ�)�� ��ȯ
		DispatchMessage(&stMsg);//�̺�Ʈ�� ó���ϴ� ������proc �� ȣ���� ���� ��Ų��
	}

	return stMsg.wParam;
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

	return CreateWindow(
		stWndCls.lpszClassName,  //������ Ŭ���� �̸�(�ĺ���)
		stWndCls.lpszClassName,  //������ �̸�					//������â�� ������ ���� �����
		WS_OVERLAPPEDWINDOW,	 //������ ��Ÿ��					//WS_OVERLAPPEDWINDOW�� ������ ���� �Ӽ��� ��ģ ��ũ�� ����
		CW_USEDEFAULT,			 //������ X��ġ					//�⺻���� ����
		CW_USEDEFAULT,			 //������ Y��ġ					//�⺻���� ����	
		CW_USEDEFAULT,			 //������ �ʺ�					//�⺻���� ����
		CW_USEDEFAULT,			 //������ ����					//�⺻���� ����
		GetDesktopWindow(),		 //�θ������� �ڵ�				//�� �θ��� ������� ����ȭ�� �� �̰� ����Ǹ� ����ȭ�鳪�� 
		NULL,					 //�޴� �ڵ�
		stWndCls.hInstance,	     //�ν��Ͻ� �ڵ�
		this);					 //�߰� ���� �Ű�����

}

