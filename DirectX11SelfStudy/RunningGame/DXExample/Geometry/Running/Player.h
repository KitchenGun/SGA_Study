#pragma once

class Player : public TextureRect
{
public:
	Player(Vector3 position, Vector3 size, float rotation);
	~Player();
public:
	void Jump();
	void Update() override;
private:
	//점프 수치
	bool isJump = false;
	float fJumpPower=0.0f;
	const float fMaxJumpSpeed = 10.0f;
	int nJumpCount = 0;
	const int nMaxJumpCount = 2;
	//지상 판정
	bool GroundIntersect = true;
};