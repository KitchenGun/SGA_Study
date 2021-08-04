#pragma once

class Bullet : public AnimationRect
{
public:
	Bullet(Vector3 position, Vector3 size, float rotation,bool isPlayer = false);
	~Bullet();
public:
	virtual void Update() override;
	virtual void Move(Vector3 position) override;
public:
	virtual void SetAnimation();
	Vector3 GetPosition() { return position; };
protected:
	float fSpeed = 800.0f;
	bool isPlayer = false;
};