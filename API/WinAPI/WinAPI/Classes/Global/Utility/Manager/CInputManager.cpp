#include "CInputManager.h"
#include "../Base/CWndApp.h"

CInputManager::CInputManager(void)
{
	ZeroMemory(m_anKeyStates, sizeof(m_anKeyStates));
	ZeroMemory(m_anPrevKeyStates, sizeof(m_anPrevKeyStates));

	ZeroMemory(&m_stMouseState, sizeof(m_stMouseState));
	ZeroMemory(&m_stPrevMouseState, sizeof(m_stPrevMouseState));
}
CInputManager::~CInputManager(void)
{
	SAFE_UNACQUIRE(m_pKeyboardDevice);
	SAFE_UNACQUIRE(m_pMouseDevice);

	SAFE_RELEASE(m_pDInput);
}

void CInputManager::Init(void)
{
	m_pDInput = this->CreateInput();
	m_pKeyboardDevice = this->CreateKeyboardDevice();
	m_pMouseDevice = this->CreateMouseDevice();
}

void CInputManager::Update(float a_fDeltaTime)
{
	CopyMemory(m_anPrevKeyStates, m_anKeyStates, sizeof(m_anKeyStates));
	CopyMemory(&m_stPrevMouseState, &m_stMouseState, sizeof(m_stMouseState));
	
	m_pKeyboardDevice->GetDeviceState(sizeof(m_anKeyStates), m_anKeyStates);
	m_pMouseDevice->GetDeviceState(sizeof(m_stMouseState), &m_stMouseState);
}


bool CInputManager::IsKeyDown(BYTE a_nKeyCode) const
{
	return m_anKeyStates[a_nKeyCode] & 0x80;
}

bool CInputManager::IsKeyPress(BYTE a_nKeyCode) const
{
	return this->IsKeyDown(a_nKeyCode) && !(m_anPrevKeyStates[a_nKeyCode] != 0x80);
}

bool CInputManager::IsKeyRelease(BYTE a_nKeyCode) const
{
	return !this->IsKeyDown(a_nKeyCode) &&
		(m_anPrevKeyStates[a_nKeyCode] & 0x80);
}

bool CInputManager::IsMouseBtnDown(EMouseBtn a_eMouseBtn) const
{
	return m_stMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80;
}

bool CInputManager::IsMouseBtnPress(EMouseBtn a_eMouseBtn) const
{
	return this->IsMouseBtnDown(a_eMouseBtn)&&!(m_stPrevMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80);
}

bool CInputManager::IsMouseBtnRelease(EMouseBtn a_eMouseBtn) const
{
	return !this->IsMouseBtnDown(a_eMouseBtn) && (m_stPrevMouseState.rgbButtons[(int)a_eMouseBtn] & 0x80);
}

POINT CInputManager::GetMousePos(void) const
{
	POINT stMousePos;
	GetCursorPos(&stMousePos);
	ScreenToClient(GET_WND_HANDLE(), &stMousePos);

	return stMousePos;
}

IDirectInput8 * CInputManager::CreateInput(void)
{
	IDirectInput8 *pDInput = nullptr;
	//�����ڵ带 �޾Ƽ� Ȯ���ϱ� ���ؼ� assert(SUCCEEDED�� �����
	assert(SUCCEEDED(DirectInput8Create(GET_INST_HANDLE(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&pDInput, NULL)));
	return pDInput;
}

IDirectInputDevice8 * CInputManager::CreateKeyboardDevice(void)
{
	IDirectInputDevice8 *pKeyboardDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysKeyboard,&pKeyboardDevice,NULL)));//�������н� ���α׷� ����ǵ��� assert�� �ɾ��

	/*
	SetDataFormat �Լ��� ����̽��� ���� ������ �������� ������ �����ϴ� ������ �����Ѵ� �� IDirectInputDevice8��ü�� Ű���带 ����� ���� �Է� ��ġ��
	�����Ҽ��ִ� Ŭ�����̱� ������ �ش� Ŭ������ ���ؼ� Ư�� ��ġ�� �����ϱ� ���ؼ� �ش� ��ġ�� �����ϴ� ������ ���信 �°� �ش� �Լ��� ����ؾ��Ѵ�
	*/
	pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	/*
	SetCooperativeLevel �Լ��� �ش� ����̽��� ���� ���� ������ �����ϴ¿����� �����Ѵ�
	�� ���� ���ؿ� ���ο� ���� Ư�� ���α׷��� �ش� ����̽��� ���� ������ �����ϴ� ���� �����ϴ�
	���� �������α׷����� Ư�� ��ġ�� �����ؼ� �����ϱ� ���ؼ��� �ݵ�� DISCL_NONEXCLUSIVE�� ����Ͽ�
	Ư����ġ�� �������� �ʰڴٰ� �˷�����Ѵ�
	*/
	pKeyboardDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	/*
	Acquire�Լ��� Ư�� ��ġ�� ���� ������ �������� ������ �����Ѵ�
	�� �ش��Լ�ȣ���� ���������� �Ϸ�� �Ŀ��� IDirectInputDevice8 ��ü�� ����ؼ� Ư����ġ �����ϴ� ���� �����ϴ�
	*/
	pKeyboardDevice->Acquire();

	return pKeyboardDevice;
}

IDirectInputDevice8 * CInputManager::CreateMouseDevice(void)
{

	IDirectInputDevice8 *pMouseDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL)));//�������н� ���α׷� ����ǵ��� assert�� �ɾ��

	
	pMouseDevice->SetDataFormat(&c_dfDIMouse);
	
	pMouseDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	
	pMouseDevice->Acquire();

	return pMouseDevice;
}
