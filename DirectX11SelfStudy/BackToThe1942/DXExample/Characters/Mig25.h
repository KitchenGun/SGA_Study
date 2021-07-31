#pragma once
class Mig25 : public AnimationRect
{
public:
	Mig25(Vector3 position, Vector3 size, float rotation);
	~Mig25();
public:
	void Update() override;
	void Move(Vector3 position) override;
	void Fire();
public:
	void SetAnimation();
	Vector3 GetPosition() { return position; };
	void SetEnemyBM(BulletManager* val) { EnemyBM = val; }
private:
	BulletManager* EnemyBM = nullptr;
	float deltaTime = 0.0f;
	float FireRate = 1 / 5.0f;
	float fSpeed = -300.0f;
};