#pragma once
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
private:
	bool isAxisDirInput = false;
	Texture2D* textureX = nullptr;
	Texture2D* textureY = nullptr;
};