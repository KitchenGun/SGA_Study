#pragma once

class BlockDestroy :public Scene
{
public:
	BlockDestroy();
	~BlockDestroy();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;

private:

	BoxManager* BoxM;
	Player* player;
	Ball* ball;
};