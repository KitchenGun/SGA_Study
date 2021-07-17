#pragma once
#pragma once

class Fortress :public Scene
{
public:
	Fortress();
	~Fortress();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	Player* CPlayer;
};