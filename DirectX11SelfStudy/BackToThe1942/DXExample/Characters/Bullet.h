#pragma once

class Bullet : public AnimationRect
{
public:
	Bullet(Vector3 position, Vector3 size, float rotation);
	~Bullet();
public:
	void Update() override;
	void Move(Vector3 position) override;
public:
	void SetAnimation();
	Vector3 GetPosition() { return position; };
private:
	float fSpeed = 300.0f;
};