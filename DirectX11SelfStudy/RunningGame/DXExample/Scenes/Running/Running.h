#pragma once

class Running :public Scene
{
public:
	Running();
	~Running();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	clock_t startTime;
	clock_t endTime;
	int score = 0;

	Player* CPlayer;
	EnemyManager* CSpawnManager;

	SoundSystem* BGSound;
};