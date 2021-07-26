#pragma once
class Rockman : public AnimationRect
{
public:
	Rockman(Vector3 position, Vector3 size, float rotation);
	~Rockman();
public:
	void Move(Vector3 position) override;
public:
	void SetAnimation();

private:

};