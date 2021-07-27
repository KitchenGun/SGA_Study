#pragma once

class Scene9 :public Scene
{
public:
	Scene9();
	~Scene9();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	TextureRect* background;
	Texture2D* mapTex;
	Ataho* animRect;
};