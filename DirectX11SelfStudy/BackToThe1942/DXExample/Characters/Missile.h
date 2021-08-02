#pragma once
class Player;

class Missile :public Bullet
{
public:
	Missile(Vector3 position, Vector3 size, float rotation, bool isPlayer=false);
	~Missile();
public:
	void Update() override;
	void Move(Vector3 position) override;
	void Rotation();
public:
	void SetAnimation() override;
	void SetTarget(Player* val) { Target = val; }
private:
	Vector3 MoveDir;
	float fangle;
	Player* Target;
private:
	float deltaTime = 0.0f;
	float FireRate = 1 / 5.0f;
};