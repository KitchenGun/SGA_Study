#pragma once

class AirHockey :public Scene
{
public:
	AirHockey();
	~AirHockey();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;

private:
	//map
	Circle* CLeft;
	Circle* CRight;
	Line* CMidLine;
	//player
	Player* CPlayer;
	Square* CPlayerGoalPost;
	//ai
	Player* CEnemy;
	Square* CEnemyGoalPost;
	//ball
	Ball* CBall;
	//Point
	int nPlayerPoint = 0;
	int nEnemyPoint = 0;
	//sound
	SoundSystem* bounceSFX;
	SoundSystem* bounce2SFX;
};