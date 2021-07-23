#pragma once
class Time: public Singleton<Time>
{
public:
	friend class Singleton<Time>;

	static bool Stopped() { return isTimerStopped; }
	static float Delta() { return isTimerStopped ? 0.0f : timeElapsed; }

	void Update();

	void Start();
	void Stop();
	float FPS() const { return framePerSecond; }
	float Running() const { return runningTime; }
private:
	Time(void);
	~Time(void);

	
	static bool isTimerStopped;	//�ð��� ������� �ƴ��� Ȯ�ο� ����
	static float timeElapsed;	//��� �ð�

	//64��Ʈ ������ ����� �� �ֵ��� ������ ������ microsecond(1 / 1000000)�ʱ��� �����Ͽ� �� �� ��Ȯ�� �ð����� �����ϱ� ����
	
	INT64 ticksPerSecond=0;		//1�ʴ� ����ī������ ��
	INT64 currentTime=0;		//����ð�
	INT64 lastTime=0;			//������ ���� �ð�
	INT64 lastFPSUpdate=0;		//������ �ʴ� ������ ������Ʈ �ð�
	INT64 fpsUpdateInterval=0;  //�ʴ� ������ ������Ʈ ���� = delta time = current time - previous time

	UINT frameCount=0;			//������
	float runningTime=0.0f;		//����ð�
	float framePerSecond=0.0f;
};