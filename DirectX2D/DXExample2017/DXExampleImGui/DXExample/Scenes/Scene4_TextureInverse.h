#pragma once

class Scene4 :public Scene
{
public:
	Scene4();
	~Scene4();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	Square* square;
	Square* square2;

	RenderTexture* RTT;

	TextureRect* textureRect;

};