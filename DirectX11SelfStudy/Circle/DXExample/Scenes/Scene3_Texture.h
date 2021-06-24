#pragma once

class Scene3 :public Scene
{
public:
	Scene3();
	~Scene3();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;

private:
	FilledCircle* circle;

};