#include "stdafx.h"
#include "Time.h"
//싱글톤패턴
Time* Time::instance = NULL;

bool Time::isTimerStopped = true;
float Time::timeElapsed = 0.0f;

Time::Time(void)
{
	//QueryPerformanceCounter : 일정지점안에서 몇번 진동 하였는가를 나타내는 함수
	//QueryPerformanceFrequency  : 1초당 틱(진동)수를 반환한다 매개변수(lpFrequency)에는 해당 타이머의 주기가 설정됨
	//즉 매개변수에게 현재 시간값을 전달함
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);
	fpsUpdateInterval = ticksPerSecond >> 1;//?
}

Time::~Time(void)
{

}

Time * Time::Get()
{
	return instance;
}

void Time::Create()
{
	assert(instance == NULL);
	instance = new Time();
}

void Time::Delete()
{
}

void Time::Update()
{
	if (isTimerStopped) return;
	//현재 시간과 간격의 업데이트
	QueryPerformanceFrequency((LARGE_INTEGER*)&currentTime);
	timeElapsed = (float)(currentTime - lastTime) / (float)ticksPerSecond;
	runningTime += timeElapsed;
	//fps 업데이트 프레임 수 증가
	frameCount++;
	if (currentTime - lastFPSUpdate >= fpsUpdateInterval)//??
	{
		float tempCurrentTime = (float)currentTime / (float)ticksPerSecond;
		float tempLastTime = (float)lastFPSUpdate / (float)ticksPerSecond;
		framePerSecond = (float)frameCount / (tempCurrentTime - tempLastTime);

		lastFPSUpdate = (INT64)currentTime;
		frameCount = 0;
	}
	lastTime = currentTime;
}

void Time::Start()
{
	if (!isTimerStopped)
		assert(false);

	QueryPerformanceFrequency((LARGE_INTEGER*)&lastTime);
	isTimerStopped = false;
}

void Time::Stop()
{
	if (!isTimerStopped)
		assert(false);

	INT64 stopTime = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&stopTime);
	runningTime += (float)(stopTime - lastTime) / (float)ticksPerSecond;
	isTimerStopped = true;
}

