#pragma once

class Scene7 :public Scene
{
public:
	Scene7();
	~Scene7();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:
	SoundSystem* BGSound;
	SoundSystem* EffSound;
};