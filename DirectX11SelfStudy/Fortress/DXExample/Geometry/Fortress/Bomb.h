#pragma once
class Bomb : public FilledCircle
{
public:
	Bomb(Vector3 position, Vector3 size, int segments, Color color);
	~Bomb();

	void Update() override;
	void Fire(float fPower);
	void Move();
	void Move(Vector3 val);
	void SetFirePower(float val) { fPower = val; }
	Vector3 GetMoveDir() { return vec3MoveDir; }
	void SetMoveDir(Vector2 val) { vec3MoveDir.x = val.x; vec3MoveDir.y = val.y; }
private:
	//방향 벡터
	Vector3 vec3MoveDir;
	//중력
	float fGravityPower = -5.0f;
	bool bGroundIntersect = false;
	//발사
	bool isFire = false;
	float fPower = 0;
	clock_t FireStartTime;
	clock_t CurrentTime;
};