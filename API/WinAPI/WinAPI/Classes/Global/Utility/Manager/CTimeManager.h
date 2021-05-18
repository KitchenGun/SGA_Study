#pragma once

#include"../../Define/KGDefine.h"
#include"../Interface/IUpdatable.h"

//�ð� ������
class CTimeManager :public IUpdatable
{
public://IUpdatable
	//���¸� �����Ѵ�
	virtual void Update(float a_fDeltaTime)override;
public:
	//�̱���
	DECLARE_SINGLETON(CTimeManager);
	//�ʱ�ȭ
	virtual void Init(void);
	//�ð������� ��ȯ�Ѵ�
	float GetDeltaTime(void)const;
	//�����ð��� ��ȯ�Ѵ�
	float GetRunningTime(void)const;

private:
	float m_fDeltaTime = 0.0f;
	float m_fRunningTime = 0.0f;

	std::chrono::system_clock::time_point m_oPrevTime;
	std::chrono::system_clock::time_point m_oStartTime;
};
