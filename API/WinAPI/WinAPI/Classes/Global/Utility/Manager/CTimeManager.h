#pragma once

#include"../../Define/KGDefine.h"
#include"../Interface/IUpdatable.h"

//시간 관리자
class CTimeManager :public IUpdatable
{
public://IUpdatable
	//상태를 갱신한다
	virtual void Update(float a_fDeltaTime)override;
public:
	//싱글톤
	DECLARE_SINGLETON(CTimeManager);
	//초기화
	virtual void Init(void);
	//시간간격을 반환한다
	float GetDeltaTime(void)const;
	//구동시간을 반환한다
	float GetRunningTime(void)const;

private:
	float m_fDeltaTime = 0.0f;
	float m_fRunningTime = 0.0f;

	std::chrono::system_clock::time_point m_oPrevTime;
	std::chrono::system_clock::time_point m_oStartTime;
};
