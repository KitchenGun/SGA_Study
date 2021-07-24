#pragma once

class Scene2 :public Scene
{
public:
	Scene2();
	~Scene2();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;

private:

	SYSTEMTIME time;

	Line* Hour;
	Line* Min;
	Line* Sec;

	Circle* clock;
};