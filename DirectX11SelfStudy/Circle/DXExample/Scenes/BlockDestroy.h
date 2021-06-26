#pragma once

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
	Square* player;
	FilledCircle* ball;
};