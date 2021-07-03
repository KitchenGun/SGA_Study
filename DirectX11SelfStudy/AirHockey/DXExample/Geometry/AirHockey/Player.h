#pragma once

class Player :public FilledCircle
{
public:
	Player(Vector3 position, Vector3 size, int segments, Color color);
	virtual ~Player();

	void Move();
	void Update() override;

	void SetIntersect(bool value) { bIntersect = value; }
	Vector3 GetVecDir();

private:
	Vector3 vecDir;
};