#pragma once

class Scene2 :public Scene
{
public:
	Scene2();
	~Scene2();

	void Init() override;
	void Update() override;
	void Render() override;

private:

	SYSTEMTIME time;

	Line* Hour;
	Line* Min;
	Line* Sec;

	Circle* clock;
};