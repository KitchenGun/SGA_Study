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
	return false;
}

bool CInputManager::IsKeyPress(BYTE a_nKeyCode) const
{
	return false;
}

bool CInputManager::IsKeyRelease(BYTE a_nKeyCode) const
{
	return false;
}

bool CInputManager::IsMouseBtnDown(EMouseBtn a_eMouseBtn) const
{
	return false;
}

bool CInputManager::IsMouseBtnPress(EMouseBtn a_eMouseBtn) const
{
	return false;
}

bool CInputManager::IsMouseBtnRelease(EMouseBtn a_eMouseBtn) const
{
	return false;
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
	//에러코드를 받아서 확인하기 위해서 assert(SUCCEEDED를 사용함
	assert(SUCCEEDED(DirectInput8Create(GET_INST_HANDLE(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&pDInput, NULL)));
	return pDInput;
}

IDirectInputDevice8 * CInputManager::CreateKeyboardDevice(void)
{
	return nullptr;
}

IDirectInputDevice8 * CInputManager::CreateMouseDevice(void)
{
	return nullptr;
}
