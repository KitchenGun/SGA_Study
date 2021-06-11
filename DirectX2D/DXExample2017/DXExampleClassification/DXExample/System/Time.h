#pragma once
class Time
{
public:
	static Time* Get();
	static void Create();
	static void Delete();

	static bool Stopped() { return isTimerStopped; }
	static bool Delta() { return isTimerStopped ? 0.0f : timeElapsed; }

	void Update();

	void Start();
	void Stop();
	float FPS() const { return framePerSecond; }
	float Running() const { return runningTime; }
private:
	Time(void);
	~Time(void);

	static Time* instance;
	static bool isTimerStopped;
	static float timeElapsed;	//경과 시간

	//64비트 정수를 사용할 수 있도록 정의한 이유는 microsecond(1 / 1000000)초까지 측정하여 좀 더 정확한 시간값을 저장하기 위함
	
	INT64 ticksPerSecond=0;		//1초당 진동수
	INT64 currentTime=0;		//현재시간
	INT64 lastTime=0;
	INT64 lastFPSUpdate=0;
	INT64 fpsUpdateInterval=0;  //프레임 업데이트 간격

	UINT frameCount=0;			//프레임
	float runningTime=0.0f;
	float framePerSecond=0.0f;
};