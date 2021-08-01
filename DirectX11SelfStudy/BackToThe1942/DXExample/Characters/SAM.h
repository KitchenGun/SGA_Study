#pragma once

class SAM :public AnimationRect
{
public:
	SAM(Vector3 position, Vector3 size, float rotation);
	~SAM();
public:
	void Update() override;
	void SetAnimation();
	void Rotation();
	void Fire();
	//get&set
	void SetEnemyBM(BulletManager* val) { EnemyBM = val; }
	void SetTarget(Player* val) { Target = val; }
private:
	float fangle = 0.0f;
	Player* Target = nullptr;
private:
	BulletManager* EnemyBM = nullptr;
	float deltaTime = 0.0f;
	float FireRate = 1 / 1.0f;
	float fSpeed = -300.0f;
};