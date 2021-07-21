#pragma once

class Scene1 :public Scene
{
public:
	Scene1();
	~Scene1();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	Square* square;
	Square* square2;
};