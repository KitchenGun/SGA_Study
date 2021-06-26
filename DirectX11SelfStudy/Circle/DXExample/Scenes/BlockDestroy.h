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
	Player* player;
	Ball* ball;
};