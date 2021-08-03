#pragma once

class Intro :public Scene
{
public:
	Intro();
	~Intro();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;

private:
	TextureRect* background;
	Texture2D* mapTex;
	Player* animRect;
	PlayerAfterBurner* subAnimRect;
private:
};