#pragma once

class Scene1 :public Scene
{
public:
	Scene1();
	~Scene1();

	void Init() override;
	void Update() override;
	void Render() override;

private:
	Square* square;
	Square* square2;


};