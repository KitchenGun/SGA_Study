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
	//ai
	//ball
	Ball* CBall;
};