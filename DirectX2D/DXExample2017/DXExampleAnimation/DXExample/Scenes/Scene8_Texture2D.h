#pragma once

class Scene8 :public Scene
{
public:
	Scene8();
	~Scene8();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	TextureRect* textureRect;
	Texture2D* tex2D;
	RenderTexture* renderTex;
};