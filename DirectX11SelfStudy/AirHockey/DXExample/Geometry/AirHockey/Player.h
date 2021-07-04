#pragma once

class Player :public FilledCircle
{
public:
	Player(Vector3 position, Vector3 size, int segments, Color color);
	virtual ~Player();

	void Move();
	void Update() override;
	void Reset();

	bool GetIntersect() { return bIntersect; }
	void SetIntersect(bool value) { bIntersect = value; }
	Vector3 GetVecDir() { return vecDir; }
	void SetVecDir(Vector3 value) { vecDir = value; }
	void SetEnemy(bool value) { isEnemy = value; }
private:
	Vector3 vecDir;
	bool isEnemy = false;
};