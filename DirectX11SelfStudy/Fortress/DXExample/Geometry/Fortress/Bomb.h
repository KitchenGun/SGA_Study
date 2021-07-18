#pragma once
class Bomb : public FilledCircle
{
public:
	Bomb(Vector3 position, Vector3 size, int segments, Color color);
	~Bomb();

	void Update() override;
	void Fire(float fPower);
	void Move();
	void SetFirePower(float val) { fPower = val; }
	Vector3 GetMoveDir() { return vec3MoveDir; }
	void SetMoveDir(Vector2 val) { vec3MoveDir.x = val.x; vec3MoveDir.y = val.y; }
	CircleInfo GetCI() { return CI; }
	bool GetReadyDestroy() { return isNeedDestroy; }
	clock_t GetFireTime() { return FireStartTime; }
private:
	//���� ����
	Vector3 vec3MoveDir;
	//�߷�
	float fGravityPower = -5.0f;
	bool bGroundIntersect = false;
	//�߻�
	bool isFire = false;
	float fPower = 0;
	clock_t FireStartTime;
	clock_t CurrentTime;

	//����
	bool isNeedDestroy;

};