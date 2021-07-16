#pragma once
class Enemy :public TextureRect
{
public:
	Enemy(Vector3 position, Vector3 size, float rotation);
	~Enemy();
public:
	void Update() override;
	void SetPosition(Vector3 position);
	void SetSpeed(float speed) { fSpeed = speed; }
private:
	float fSpeed=-3.0f;
};