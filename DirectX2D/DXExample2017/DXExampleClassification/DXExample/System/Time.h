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
	static float timeElapsed;	//��� �ð�

	//64��Ʈ ������ ����� �� �ֵ��� ������ ������ microsecond(1 / 1000000)�ʱ��� �����Ͽ� �� �� ��Ȯ�� �ð����� �����ϱ� ����
	
	INT64 ticksPerSecond=0;		//1�ʴ� ������
	INT64 currentTime=0;		//����ð�
	INT64 lastTime=0;
	INT64 lastFPSUpdate=0;
	INT64 fpsUpdateInterval=0;  //������ ������Ʈ ����

	UINT frameCount=0;			//������
	float runningTime=0.0f;
	float framePerSecond=0.0f;
};