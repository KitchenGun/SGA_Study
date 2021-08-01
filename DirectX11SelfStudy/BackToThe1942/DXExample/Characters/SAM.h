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
	//get&set
	void SetTarget(Player* val) { Target = val; }
private:
	float fangle = 0.0f;
	Player* Target = nullptr;;
};