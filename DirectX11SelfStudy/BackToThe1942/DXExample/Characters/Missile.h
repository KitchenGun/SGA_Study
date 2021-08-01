#pragma once
class Missile :public Bullet
{
public:
	Missile(Vector3 position, Vector3 size, float rotation);
	~Missile();
public:
	void Update() override;
	void Move(Vector3 position) override;
public:
	void SetAnimation() override;
private:
	Vector3 MoveDir;
};