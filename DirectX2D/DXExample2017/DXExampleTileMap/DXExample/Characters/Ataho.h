#pragma once

class Ataho : public AnimationRect
{
public:
	Ataho(Vector3 position, Vector3 size, float rotation);
	~Ataho();
public:
	void Update() override;
	void Move(Vector3 position) override;
	void Input();
public:
	void SetAnimation();
private:
	bool isAxisDirInput = false;
};