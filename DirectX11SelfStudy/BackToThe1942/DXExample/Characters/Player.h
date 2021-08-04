#pragma once
enum class State
{
	Idle,
	Forward,
	Backward,
	Left,
	Right,
};


class Player : public AnimationRect
{
public:
	Player(Vector3 position, Vector3 size, float rotation);
	~Player();
public:
	void Update() override;
	void Move(Vector3 position) override; 
	void Input();
public:
	void SetAnimation();
	Vector3 GetPosition() { return position; };
	State PlayerState;
	void SetPlayerAfterBurner(PlayerAfterBurner* val) { afterBurner = val; }
	void SetPlayerBM(BulletManager* val) { playerBM = val; }
private:
	PlayerAfterBurner* afterBurner = nullptr;
	Vector3 TempMovePos;
	bool isVerticalDirInput = false;
	bool isHorizontalDirInput = false;
	bool isForward = false;
	bool isLeft = false;
private:
	BulletManager* playerBM = nullptr;
	float deltaTime = 0.0f;
	float FireRate = 1 / 10.0f;
private:
	SoundSystem* GunSFX;
};