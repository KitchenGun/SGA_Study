#pragma once

class Player : public TextureRect
{
public:
	Player(Vector3 position, Vector3 size, float rotation);
	~Player();
public:
	void Jump();
	void Update() override;
	void SetPosition(Vector3 position);

private:
	//점프 수치
	bool isJump = false;
	float fJumpPower=0.0f;
	const float fMaxJumpSpeed = 20.0f;
	int nJumpCount = 0;
	const int nMaxJumpCount = 2;
	//지상 판정
	float GravatiyPower = -10.0f;
	bool GroundIntersect = true;
};