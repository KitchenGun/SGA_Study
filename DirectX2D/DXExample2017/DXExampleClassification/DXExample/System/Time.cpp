#include "stdafx.h"
#include "Time.h"
//�̱�������
Time* Time::instance = NULL;

bool Time::isTimerStopped = true;
float Time::timeElapsed = 0.0f;

Time::Time(void)
{
	//QueryPerformanceCounter : ���������ȿ��� ��� ���� �Ͽ��°��� ��Ÿ���� �Լ�
	//QueryPerformanceFrequency  : 1�ʴ� ƽ(����)���� ��ȯ�Ѵ� �Ű�����(lpFrequency)���� �ش� Ÿ�̸��� �ֱⰡ ������
	//�� �Ű��������� ���� �ð����� ������
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
	//���� �ð��� ������ ������Ʈ
	QueryPerformanceFrequency((LARGE_INTEGER*)&currentTime);
	timeElapsed = (float)(currentTime - lastTime) / (float)ticksPerSecond;
	runningTime += timeElapsed;
	//fps ������Ʈ ������ �� ����
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

