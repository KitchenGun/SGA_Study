#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"

//�Է°�����
class CInputManager :public IUpdatable
{
public://IUpdatable
	//���¸� �����Ѵ�
	virtual void Update(float a_fDeltaTime)override;
public:
	//�̱���
	DECLARE_SINGLETON(CInputManager);
	//�ʱ�ȭ
	virtual void Init(void);
	//Ű�������� �˻�
	bool IsKeyDown(BYTE a_nKeyCode)const;
	//Ű���� ���� ���θ� �˻��Ѵ�
	bool IsKeyPress(BYTE a_nKeyCode)const;
	//Ű���� ���Ῡ�θ� �˻��Ѵ�
	bool IsKeyRelease(BYTE a_nKeyCode)const;
	//���콺 ��ư �������θ� �˻��Ѵ�
	bool IsMouseBtnDown(EMouseBtn a_eMouseBtn)const;
	//���콺 ��ư ���� ���ۿ��θ� �˻��Ѵ�
	bool IsMouseBtnPress(EMouseBtn a_eMouseBtn)const;
	//���콺 ��ư �������� ���θ� �˻��Ѵ�
	bool IsMouseBtnRelease(EMouseBtn a_eMouseBtn)const;
	//���콺 ��ġ�� ��ȯ�Ѵ�
	POINT GetMousePos(void) const;
private:
	//���̷�Ʈ ��ǲ�� �����Ѵ�
	IDirectInput8 *CreateInput(void);
	//Ű���� ����̽��� �����Ѵ�
	IDirectInputDevice8 *CreateKeyboardDevice(void);
	//���콺 ����̽��� �����Ѵ�
	IDirectInputDevice8 *CreateMouseDevice(void);
private:
	BYTE m_anKeyStates[UCHAR_MAX + 1];
	BYTE m_anPrevKeyStates[UCHAR_MAX + 1];
	
	DIMOUSESTATE m_stMouseState;//���콺 state2�� ����ϸ� ���콺 �߰� ��ư�� ��밡���ϴ�
	DIMOUSESTATE m_stPrevMouseState;

	IDirectInput8 *m_pDInput = nullptr;
	IDirectInputDevice8 *m_pKeyboardDevice = nullptr;
	IDirectInputDevice8 *m_pMouseDevice = nullptr;
};