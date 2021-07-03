#pragma once

class Scene5 :public Scene
{
public:
	Scene5();
	~Scene5();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;

private:
	TextureRect* texture;
};