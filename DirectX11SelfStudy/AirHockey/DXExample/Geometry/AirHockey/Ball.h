#pragma once

class Ball :public FilledCircle
{
public:
	Ball(Vector3 position, Vector3 size, int segments, Color color);
	~Ball();

	void Move(Vector3 position);

	void Update() override;

	void Reset();
	bool GetIntersect() { return bIntersect; }
	void SetIntersect(bool value) { bIntersect = value; }
	Vector3 GetVecDir() { return vecDir; }
	void SetVecDir(Vector3 value) { vecDir = value; }
private:
	Vector3 vecDir;
};