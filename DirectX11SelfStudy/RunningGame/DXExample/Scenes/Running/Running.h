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
	Player* CPlayer;

	SoundSystem* BGSound;
	SoundSystem* EffSound;
};