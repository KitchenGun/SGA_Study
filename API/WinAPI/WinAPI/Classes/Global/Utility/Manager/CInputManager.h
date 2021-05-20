#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"

//입력관리자
class CInputManager :public IUpdatable
{
public://IUpdatable
	//상태를 갱신한다
	virtual void Update(float a_fDeltaTime)override;
public:
	//싱글턴
	DECLARE_SINGLETON(CInputManager);
	//초기화
	virtual void Init(void);
	//키눌림여부 검사
	bool IsKeyDown(BYTE a_nKeyCode)const;
	//키눌림 시작 여부를 검사한다
	bool IsKeyPress(BYTE a_nKeyCode)const;
	//키눌림 종료여부를 검사한다
	bool IsKeyRelease(BYTE a_nKeyCode)const;
	//마우스 버튼 눌림여부를 검사한다
	bool IsMouseBtnDown(EMouseBtn a_eMouseBtn)const;
	//마우스 버튼 눌림 시작여부를 검사한다
	bool IsMouseBtnPress(EMouseBtn a_eMouseBtn)const;
	//마우스 버튼 눌림종료 여부를 검사한다
	bool IsMouseBtnRelease(EMouseBtn a_eMouseBtn)const;
	//마우스 위치를 반환한다
	POINT GetMousePos(void) const;
private:
	//다이렉트 인풋을 생성한다
	IDirectInput8 *CreateInput(void);
	//키보드 디바이스를 생성한다
	IDirectInputDevice8 *CreateKeyboardDevice(void);
	//마우스 디바이스를 생성한다
	IDirectInputDevice8 *CreateMouseDevice(void);
private:
	BYTE m_anKeyStates[UCHAR_MAX + 1];
	BYTE m_anPrevKeyStates[UCHAR_MAX + 1];
	
	DIMOUSESTATE m_stMouseState;//마우스 state2를 사용하면 마우스 추가 버튼이 사용가능하다
	DIMOUSESTATE m_stPrevMouseState;

	IDirectInput8 *m_pDInput = nullptr;
	IDirectInputDevice8 *m_pKeyboardDevice = nullptr;
	IDirectInputDevice8 *m_pMouseDevice = nullptr;
};