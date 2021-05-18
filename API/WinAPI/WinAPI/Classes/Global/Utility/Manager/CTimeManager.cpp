#include "CTimeManager.h"

CTimeManager::CTimeManager(void)
{
	//do nothing
}
CTimeManager::~CTimeManager(void)
{
	//do nothing
}

void CTimeManager::Init(void)
{
	m_oPrevTime = std::chrono::system_clock::now();
	m_oStartTime = std::chrono::system_clock::now();
}


void CTimeManager::Update(float a_fDeltaTime)
{
	auto oCurTime = std::chrono::system_clock::now();

	m_fDeltaTime = std::chrono::duration<float>(oCurTime - m_oPrevTime).count();
	m_fRunningTime = std::chrono::duration<float>(oCurTime - m_oStartTime).count();
	m_oPrevTime = oCurTime;
}

float CTimeManager::GetDeltaTime(void) const
{
	return m_fDeltaTime;
}

float CTimeManager::GetRunningTime(void) const
{
	return m_fRunningTime;
}
