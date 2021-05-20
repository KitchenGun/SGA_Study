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
	//에러코드를 받아서 확인하기 위해서 assert(SUCCEEDED를 사용함
	assert(SUCCEEDED(DirectInput8Create(GET_INST_HANDLE(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&pDInput, NULL)));
	return pDInput;
}

IDirectInputDevice8 * CInputManager::CreateKeyboardDevice(void)
{
	IDirectInputDevice8 *pKeyboardDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysKeyboard,&pKeyboardDevice,NULL)));//생성실패시 프로그램 종료되도록 assert를 걸어둠

	/*
	SetDataFormat 함수는 디바이스로 부터 가져올 데이터의 형식을 지정하는 역할을 수행한다 즉 IDirectInputDevice8객체는 키보드를 비롯한 여러 입력 장치를
	제어할수있는 클래스이기 때문에 해당 클래스를 통해서 특정 장치를 제어하기 위해서 해당 장치가 제공하는 데이터 포멧에 맞게 해당 함수를 사용해야한다
	*/
	pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	/*
	SetCooperativeLevel 함수는 해당 디바이스에 대한 협력 수준을 지정하는역할을 수행한다
	즉 협력 수준에 여부에 따라서 특정 프로그램이 해당 디바이스에 대한 권한을 독점하는 것이 가능하다
	따라서 여러프로그램에서 특정 장치를 공유해서 제어하기 위해서는 반드시 DISCL_NONEXCLUSIVE를 명시하여
	특정장치를 독점하지 않겠다고 알려줘야한다
	*/
	pKeyboardDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	/*
	Acquire함수는 특정 장치에 대한 권한을 가져오는 역할을 수행한다
	즉 해당함수호출이 정상적으로 완료된 후에야 IDirectInputDevice8 객체를 사용해서 특정장치 제어하는 것이 가능하다
	*/
	pKeyboardDevice->Acquire();

	return pKeyboardDevice;
}

IDirectInputDevice8 * CInputManager::CreateMouseDevice(void)
{

	IDirectInputDevice8 *pMouseDevice = nullptr;
	assert(SUCCEEDED(m_pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, NULL)));//생성실패시 프로그램 종료되도록 assert를 걸어둠

	
	pMouseDevice->SetDataFormat(&c_dfDIMouse);
	
	pMouseDevice->SetCooperativeLevel(GET_WND_HANDLE(), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	
	pMouseDevice->Acquire();

	return pMouseDevice;
}
