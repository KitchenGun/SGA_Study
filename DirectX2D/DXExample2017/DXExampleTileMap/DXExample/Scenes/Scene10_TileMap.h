#pragma once

class Scene10 :public Scene
{
public:
	Scene10();
	~Scene10();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	TileMap* tileMap;
};