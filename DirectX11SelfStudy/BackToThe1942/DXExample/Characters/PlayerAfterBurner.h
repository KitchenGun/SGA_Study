#pragma once
class PlayerAfterBurner : public AnimationRect
{
public:
	PlayerAfterBurner(Vector3 position, Vector3 size, float rotation);
	~PlayerAfterBurner();
public:
	void Update() override;
	void Move(Vector3 position) override;
	void Render() override;
public:
	void SetIsActive(bool val) { isActive = val; }
	bool GetIsActive() { return isActive; }
	void SetAnimation();
private:
	Vector3 TempMovePos;
	bool isActive = true;
	bool isReset = false;
};