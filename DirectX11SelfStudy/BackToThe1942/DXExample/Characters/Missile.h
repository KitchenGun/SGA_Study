#pragma once
class Missile :public Bullet
{
public:
	Missile(Vector3 position, Vector3 size, float rotation, bool isPlayer=false);
	~Missile();
public:
	void Update() override;
	void Move(Vector3 position) override;
public:
	void SetAnimation() override;
	void SetAngle(float val) { MoveDir.y = sinf(val); MoveDir.x = cosf(val);}
private:
	Vector3 MoveDir;
};